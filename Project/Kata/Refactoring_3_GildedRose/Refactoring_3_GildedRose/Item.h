#pragma once
#include <iostream>
using namespace std;

namespace ITEM
{
    constexpr const char* SULFURAS = "Sulfuras, Hand of Ragnaros";
    constexpr const char* AGED_BRIE = "Aged Brie";
    constexpr const char* BACKSTAGE = "Backstage passes to a TAFKAL80ETC concert";
    constexpr const char* NONAME = "noname";
}

class Item
{
public:
    string name;
    int sellIn;
    int quality;

    Item(string name, int sellIn, int quality)
        : name(name), sellIn(sellIn), quality(quality)
    {}

    void decrementSellIn(void);
    void incrementQuality(void);
    void decrementQuality(void);
    void clearQuality(void);

private:
    const int MAX_QUALITY = 50;
    const int MIN_QUALITY = 0;
};