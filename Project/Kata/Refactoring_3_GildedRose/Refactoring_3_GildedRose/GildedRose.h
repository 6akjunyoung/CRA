#pragma once
#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality)
    {}
};

class GildedRose
{
public:
    vector<Item>& items;
    GildedRose(vector<Item>& items);

    void updateQuality();

private:
    const string SULFURAS = "Sulfuras, Hand of Ragnaros";
    const string AGED_BRIE = "Aged Brie";
    const string BACKSTAGE = "Backstage passes to a TAFKAL80ETC concert";
    const string NONAME = "noname";

    void updateSellIn(Item& item);
    void getQualityNormal(Item& item);
    void getQualitySulfuras(Item& item);
    void getQualityBackstage(Item& item);
    void getQualityAgeBrie(Item& item);

    void incrementQuality(int& quality);
    void decrementQuality(int& quality);
    void clearQuality(int& quality);
};