#include "ItemOperator.h"

void ItemOperator::updateQuality(void)
{
    item->decrementQuality();

    if (item->sellIn < 0)
    {
        item->decrementQuality();
    }
}

void ItemOperator::updateSellIn(void)
{
    item->decrementSellIn();
}

void SulfurasItemOperator::updateQuality(void)
{
    item->incrementQuality();
}

void SulfurasItemOperator::updateSellIn(void)
{
    ;
}

void BackstageItemOperator::updateQuality(void)
{
    if (item->sellIn < 0)
    {
        item->clearQuality();
        return;
    }

    item->incrementQuality();

    if (item->sellIn < 10)
    {
        item->incrementQuality();
    }

    if (item->sellIn < 5)
    {
        item->incrementQuality();
    }
    return;
}

void AgeBrieItemOperator::updateQuality(void)
{
    item->incrementQuality();
    if (item->sellIn < 0)
    {
        item->incrementQuality();
    }
}
