#include "Item.h"

void Item::decrementSellIn(void)
{
    sellIn--;
}

void Item::incrementQuality(void)
{
    if (quality < MAX_QUALITY)
    {
        quality++;
    }
}

void Item::decrementQuality(void)
{
    if (MIN_QUALITY < quality)
    {
        quality--;
    }
}

void Item::clearQuality(void)
{
    quality = 0;
}
