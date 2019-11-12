#pragma once
#include "bids.h"
namespace br {
class GameBidding{
public:
GameBidding()=default;
explicit GameBidding(const Auction &auction);
//return true if is end of auction
bool addBid(const Bid &vb);
private:

bool isEmptyContract() const;
bool isEndAuction() const;
Penalty getPenalty() const;
OptPlayContract getContractBid() const;




Auction auction_;
Contract contract_;
};
}
