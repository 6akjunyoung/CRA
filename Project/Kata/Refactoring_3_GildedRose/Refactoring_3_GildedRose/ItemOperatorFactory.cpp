#include "ItemOperatorFactory.h"

ItemOperator* ItemOperatorFactory::getItemOperator(Item * item)
{
    if (item->name == ITEM::SULFURAS)
    {
        return new SulfurasItemOperator(item);
    }
    if (item->name == ITEM::BACKSTAGE)
    {
        return new BackstageItemOperator(item);
    }
    if (item->name == ITEM::AGED_BRIE)
    {
        return new AgeBrieItemOperator(item);
    }
    return new ItemOperator(item);
}