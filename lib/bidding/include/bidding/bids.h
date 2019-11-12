#pragma once
#include <vector>
#include <cstdint>
#include <variant>
#include <optional>

namespace br {
enum class  Players:uint8_t
{
    North,
    East,
    South,
    West
};

enum class  TypeContract:uint8_t
{
    Club,
    Diamond,
    Heart,
    Spade,
    NT
};

enum class  ValidBids:uint8_t
{
    one_club=0,
    one_diamond,
    one_heart,
    one_spade,
    one_NT,

    two_clubs,
    two_diamonds,
    two_hearts,
    two_spades,
    two_NT,

    three_clubs,
    three_diamonds,
    three_hearts,
    three_spades,
    three_NT,

    four_clubs,
    four_diamonds,
    four_hearts,
    four_spades,
    four_NT,

    five_clubs,
    five_diamonds,
    five_hearts,
    five_spades,
    five_NT,


    six_clubs,
    six_diamonds,
    six_hearts,
    six_spades,
    six_NT,

    seven_clubs,
    seven_diamonds,
    seven_hearts,
    seven_spades,
    seven_NT,//34

    Double,
    Redouble,
    Pass


};

inline bool isContractBid(ValidBids b)
{
    auto v=static_cast<uint8_t>(b);
    if (0<= v && v <= 34)
       return true;
    else
       return false;

}

inline bool isPenalty(ValidBids b)
{
if (b==ValidBids::Double ||
    b==ValidBids::Redouble)
    return true;
else
    return false;
}


inline bool isPass(ValidBids b)
{
if (b==ValidBids::Pass )
    return true;
else
    return false;
}


enum class Penalty:uint8_t{
    No=0,
    Double,
    Redouble

};

Penalty toPenalty(ValidBids vb)
{
    switch(vb)
    {
    default:
        return Penalty::No;
    case ValidBids::Double:
        return Penalty::Double;
    case ValidBids::Redouble:
        return Penalty::Redouble;
    }
}
struct Bid
{
    ValidBids bid;
    Players player;
};

using Auction=std::vector<Bid>;
using ReverseIterAction=std::reverse_iterator<Auction::const_iterator>;
struct EmptyContract{};
struct PlayContract{
    ValidBids bid;
    Penalty penalty;
    Players declarer;
};
using OptPlayContract=std::optional<PlayContract>;
using Contract=std::variant<EmptyContract,PlayContract>;


}
