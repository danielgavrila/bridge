#include "bidding/bidding.h"
#include <cassert>
#include <algorithm>
namespace br {

GameBidding::GameBidding(const Auction &auction):
    auction_(auction)
{

}

bool GameBidding::addBid(const Bid &vb)
{
    auction_.emplace_back(vb);
    if(isEmptyContract())
    {
        contract_=EmptyContract{};
        return true;
    }
    if(isEndAuction())
    {
        auto ret=getContractBid();
        if(ret)
        {
            contract_=*ret;
            return true;
        }

    }

    return false;
}

bool GameBidding::isEmptyContract() const
{
    if(auction_.size()==4 )
    {
        for(auto &o:auction_)
        {
            if(false==isPass(o.bid))
                return false;
        }
    }
    else
        return false;
    return true;

}

bool GameBidding::isEndAuction() const
{
    if(auction_.size()>=4 )
    {
        auto sz=auction_.size();
        if(isPass(auction_[sz-1].bid) &&
           isPass(auction_[sz-2].bid) &&
           isPass(auction_[sz-3].bid)      )
            return true;
    }

    return false;
}


Penalty GameBidding::getPenalty() const
{
    assert(isEndAuction());
    auto sz=auction_.size();
    return toPenalty(auction_[sz-4].bid);
}
OptPlayContract GameBidding::getContractBid() const
{

    assert(isEndAuction());
    auto sz=auction_.size();
    auto penalty=getPenalty();
    if (Penalty::No==penalty)
    {

        return PlayContract {.bid=auction_[sz-4].bid,
                             .penalty=penalty,
                             .declarer=Players::North};

    }
    else
    {
         ReverseIterAction r = auction_.rbegin()+3;
         ReverseIterAction end=auction_.rend();
         assert(isPenalty((*r).bid));
         auto it=std::find_if(r,end,[](auto &o)->bool
         {
             return isContractBid(o.bid);
         });
         if(it!=auction_.rend())
              return PlayContract {.bid=(*it).bid,
                                   .penalty=penalty,
                                   .declarer=Players::North
                                   };
         else
             return OptPlayContract();
    }
}
}
