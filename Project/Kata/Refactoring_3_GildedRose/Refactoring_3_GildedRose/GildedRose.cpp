#include <memory>
#include "GildedRose.h"

GildedRose::GildedRose(vector<Item>& items) : items(items)
{}

void GildedRose::updateQuality()
{
    for (int i = 0; i < items.size(); i++)
    {
        Item& item = items[i];

        // unique_ptr<ItemOperator> itemOperator (ItemOperatorFactory::getItemOperator(&item));
        ItemOperator* itemOperator = ItemOperatorFactory::getItemOperator(&item);

        itemOperator->updateSellIn();
        itemOperator->updateQuality();

        free(itemOperator);
    }
}
