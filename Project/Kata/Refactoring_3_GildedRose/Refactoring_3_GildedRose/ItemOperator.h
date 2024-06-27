#pragma once
#include "Item.h"

class ItemOperator
{
public:
    ItemOperator(Item* item) : item(item)
    {}

    virtual void updateQuality(void);
    virtual void updateSellIn(void);

protected:
    Item* item;
};

class SulfurasItemOperator : public ItemOperator
{
public:
    SulfurasItemOperator(Item* item)
        : ItemOperator(item)
    {}

    void updateQuality(void) override;
    void updateSellIn(void) override;
};

class BackstageItemOperator : public ItemOperator
{
public:
    BackstageItemOperator(Item* item)
        : ItemOperator(item)
    {}

    void updateQuality(void) override;
};

class AgeBrieItemOperator : public ItemOperator
{
public:
    AgeBrieItemOperator(Item* item)
        : ItemOperator(item)
    {}

    void updateQuality(void) override;
};