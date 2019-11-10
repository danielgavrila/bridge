#include "hand/hand.h"

namespace br {



EvalHand::EvalHand(const Hand  &h):hand_(h)
{
    sort();
    HPO_=hpo();
    clubs_=getColour(Colour::Club);
    diamonds_=getColour(Colour::Diamond);
    hearts_=getColour(Colour::Heart);
    spades_=getColour(Colour::Spade);

    FL_=HPO_+countFL();
}

void EvalHand::sort()
{
    std::sort(hand_.begin(),hand_.end(),[this](const auto &a,const auto &b)->bool
    {
        return orderCard(a) < orderCard(b);
    });
}

uint8_t EvalHand::orderCard(Card card) const
{
    auto r= static_cast<uint8_t>(card.rank);
    auto c= static_cast<uint8_t>(card.colour);
    return c*NRCARDS+r;
}

uint8_t EvalHand::countFL(const ColourCards &clr) const
{
    auto f=hpo(clr);
    auto sz=clr.size();
    if (f>=3 && sz >4)
        return static_cast<uint8_t>(sz -4);
    else
        return 0;
}

uint8_t EvalHand::count_trump_FV(const ColourCards &clr, uint8_t estimatedLengthPartner) const
{
auto sz=clr.size();
return static_cast<uint8_t>(sz+estimatedLengthPartner-7u);
}

uint8_t EvalHand::count_FV(Colour c, uint8_t estimatedLengthPartner) const
{
    uint8_t ret=HPO_;
switch(c)
{
case Colour::Club:
    ret+=count_trump_FV(clubs_,estimatedLengthPartner);
    ret+=count_other_FV(diamonds_);
    ret+=count_other_FV(hearts_);
    ret+=count_other_FV(spades_);
    break;
case Colour::Diamond:
    ret+=count_other_FV(clubs_);
    ret+=count_trump_FV(diamonds_,estimatedLengthPartner);
    ret+=count_other_FV(hearts_);
    ret+=count_other_FV(spades_);
    break;
case Colour::Heart:
    ret+=count_other_FV(clubs_);
    ret+=count_other_FV(diamonds_);
    ret+=count_trump_FV(hearts_,estimatedLengthPartner);
    ret+=count_other_FV(spades_);
    break;
case Colour::Spade:
    ret+=count_other_FV(clubs_);
    ret+=count_other_FV(diamonds_);
    ret+=count_other_FV(hearts_);
    ret+=count_trump_FV(spades_,estimatedLengthPartner);
    break;

}
return ret;
}

uint8_t EvalHand::count_other_FV(const ColourCards &clr) const
{

    auto sz=clr.size();

    switch(sz)
    {
    default:
        return 0;
    case 2://doubleton
        return 1;
    case 1://singleton
        return 2;

    case 0://chicane
        return 3;

    }


}

uint8_t EvalHand::countFL() const
{
    uint8_t ret=0;
    ret+=countFL(clubs_);
    ret+=countFL(diamonds_);
    ret+=countFL(hearts_);
    ret+=countFL(spades_);
    return ret;
}

ColourCards EvalHand::getColour(Colour c)
{
    auto itClubs=firstCard(c);
    auto sizeClubs=countCard(c);
    return ColourCards(const_cast<Card*>(itClubs),static_cast<size_t>(sizeClubs));
}

HandIter EvalHand::firstCard(Colour c) const
{
    return std::find_if(hand_.cbegin(),hand_.cend(),[c=c](auto &o)->bool
    {
        return o.colour==c;
    });
}

long EvalHand::countCard(Colour c) const
{
    return std::count_if(hand_.cbegin(),hand_.cend(),[c=c](auto &o)->bool
    {
        return o.colour==c;
    });
}

uint8_t EvalHand::FL() const
{
    return FL_;
}

Hand EvalHand::hand() const
{
    return hand_;
}

uint8_t EvalHand::HPO() const
{
    return HPO_;
}

}
