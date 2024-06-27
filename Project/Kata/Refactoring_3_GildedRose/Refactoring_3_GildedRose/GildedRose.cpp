#include "GildedRose.h"

GildedRose::GildedRose(vector<Item>& items) : items(items)
{}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        Item& item = items[i];

        updateSellIn(item);

        if (item.name == AGED_BRIE)
        {
            getQualityAgeBrie(item);
        }
        else if (item.name == BACKSTAGE)
        {
            getQualityBackstage(item);
        }
        else if (item.name == SULFURAS)
        {
            getQualitySulfuras(item);
        }
        else
        {
            getQualityNormal(item);
        }
    }
}

void GildedRose::updateSellIn(Item& item)
{
    if (item.name != SULFURAS)
    {
        item.sellIn--;
    }
}

void GildedRose::getQualityNormal(Item& item)
{
    decrementQuality(item.quality);

    if (item.sellIn < 0)
    {
        decrementQuality(item.quality);
    }
}

void GildedRose::getQualitySulfuras(Item& item)
{
    incrementQuality(item.quality);
}

void GildedRose::getQualityBackstage(Item& item)
{
    if (item.sellIn < 0)
    {
        clearQuality(item.quality);
        return;
    }

    incrementQuality(item.quality);

    if (item.sellIn < 10)
    {
        incrementQuality(item.quality);
    }

    if (item.sellIn < 5)
    {
        incrementQuality(item.quality);
    }
    return;
}

void GildedRose::getQualityAgeBrie(Item& item)
{
    incrementQuality(item.quality);
    if (item.sellIn < 0)
    {
        incrementQuality(item.quality);
    }
}

void GildedRose::incrementQuality(int& quality)
{
    if (quality < 50)
    {
        quality++;
    }
}

void GildedRose::decrementQuality(int& quality)
{
    if (0 < quality)
    {
        quality--;
    }
}

void GildedRose::clearQuality(int& quality)
{
    quality = 0;
}