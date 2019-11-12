#pragma once
#include <array>
#include <algorithm>
#include <numeric>
#include "gsl-lite.hpp"
namespace br {
enum class Colour:uint8_t
{
    Club,
    Diamond,
    Heart,
    Spade
} ;


enum class Rank:uint8_t
{
    Two, //0
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,//8
    Jack,
    Queen,
    King,
    Ace
};

struct  Card
{
    Rank rank;
    Colour colour;
};

inline bool operator==(const Card &a,const Card &b)
{
    return a.rank==b.rank && a.colour==b.colour;
}
constexpr uint8_t NRCARDS=13;


using Hand=std::array<Card,NRCARDS>;
using HandIter=Hand::const_iterator;
using ColourCards=gsl::span<Card>;


}
