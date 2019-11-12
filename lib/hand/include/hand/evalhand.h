#pragma once
#include "hand/hand.h"



namespace br{
class EvalHand {
public:
    EvalHand()=default;
    explicit EvalHand(const Hand  &h);


    uint8_t HPO() const;

    Hand hand() const;

    uint8_t FL() const;
    uint8_t count_FV(Colour c, uint8_t estimatedLengthPartner) const;
private:

    void sort();
    uint8_t orderCard(Card card) const;
    uint8_t hpo(Rank r) const
    {
        auto v=static_cast<uint8_t>(r);
        if (v<=8) //Ten
            return 0;
        else
            return v-8;
    }

    uint8_t hpo(const Card &c) const
    {
        return hpo(c.rank);
    }


    uint8_t hpo() const
    {
        uint8_t st=0;
        return std::accumulate(hand_.begin(),hand_.end(),st,[this](uint8_t a,auto &o)
        {
            return a+hpo(o);
        });
    }

    uint8_t hpo(const ColourCards &clr) const
    {
        uint8_t st=0;
        return std::accumulate(clr.begin(),clr.end(),st,[this](uint8_t a,auto &o)
        {
            return a+hpo(o);
        });
    }
    ColourCards getColour(Colour c);
    uint8_t countFL(const ColourCards &clr) const;
    uint8_t countFL() const;
    HandIter firstCard(Colour c) const;
    long countCard(Colour c) const;


    uint8_t count_other_FV(const ColourCards &clr) const;
    uint8_t count_trump_FV(const ColourCards &clr, uint8_t estimatedLengthPartner) const;

    Hand  hand_;
    uint8_t HPO_;
    uint8_t FL_;

    ColourCards clubs_;
    ColourCards diamonds_;
    ColourCards hearts_;
    ColourCards spades_;



};

}
