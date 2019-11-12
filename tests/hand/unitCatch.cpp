#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "hand/evalhand.h"
#include "bidding/bidding.h"
using namespace br;

Auction auction1()
{
    return Auction{
        Bid{ValidBids::one_club,Players::North},
        Bid{ValidBids::Pass,Players::East},
        Bid{ValidBids::Pass,Players::South}

    };
}
Hand hand1()
{
    return Hand{

        Card{Rank::King,Colour::Diamond},
        Card{Rank::Ten,Colour::Diamond},

        Card{Rank::Ten,Colour::Club},
        Card{Rank::Two,Colour::Club},

        Card{Rank::Jack,Colour::Spade},


        Card{Rank::Seven,Colour::Diamond},
        Card{Rank::Two,Colour::Diamond},

        Card{Rank::Queen,Colour::Heart},
        Card{Rank::Ten,Colour::Heart},

        Card{Rank::Ace,Colour::Club},
        Card{Rank::King,Colour::Club},

        Card{Rank::Seven,Colour::Heart},

        Card{Rank::Six,Colour::Spade}

    };
}
Hand hand_sorted1()
{
    return Hand{
        Card{Rank::Two,Colour::Club},
        Card{Rank::Ten,Colour::Club},
        Card{Rank::King,Colour::Club},
        Card{Rank::Ace,Colour::Club},

        Card{Rank::Two,Colour::Diamond},
        Card{Rank::Seven,Colour::Diamond},
        Card{Rank::Ten,Colour::Diamond},
        Card{Rank::King,Colour::Diamond},

        Card{Rank::Seven,Colour::Heart},
        Card{Rank::Ten,Colour::Heart},
        Card{Rank::Queen,Colour::Heart},

        Card{Rank::Six,Colour::Spade},
        Card{Rank::Jack,Colour::Spade}

    };
}

Hand hand2()
{
    return Hand{
        Card{Rank::Five,Colour::Club},
        Card{Rank::Six,Colour::Club},
        Card{Rank::Eight,Colour::Club},
        Card{Rank::Nine,Colour::Club},
        Card{Rank::King,Colour::Club},


        Card{Rank::Queen,Colour::Diamond},
        Card{Rank::King,Colour::Diamond},
        Card{Rank::Ace,Colour::Diamond},

        Card{Rank::Four,Colour::Heart},
        Card{Rank::Eight,Colour::Heart},
        Card{Rank::Queen,Colour::Heart},

        Card{Rank::Three,Colour::Spade},
        Card{Rank::Eight,Colour::Spade}

    };
}


TEST_CASE( "Hands ", "[hands]" )
{

    SECTION("hpo")
    {


    }

    SECTION("hpo_hand")
    {
        auto h1=hand1();
        auto eh=EvalHand(h1);
        REQUIRE(13==eh.HPO());
        auto h2=hand_sorted1();
        REQUIRE(h2==eh.hand());
    }

    SECTION("FL_hand")
    {
        auto h1=hand2();
        auto eh=EvalHand(h1);
        REQUIRE(14==eh.HPO());
        REQUIRE(15==eh.FL());
    }

    SECTION("FV_hand")
    {
        auto h1=hand2();
        auto eh=EvalHand(h1);
        REQUIRE(14==eh.HPO());
        REQUIRE(16==eh.count_FV(Colour::Club,3));
    }
    SECTION("auction1")
    {
        auto a1=auction1();
        auto g1=GameBidding(a1);
        auto bRet=g1.addBid(Bid{ValidBids::Pass,Players::West});
        assert(bRet);
    }
}
