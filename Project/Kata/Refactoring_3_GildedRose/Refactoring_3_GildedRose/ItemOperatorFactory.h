#pragma once
#include "ItemOperator.h"

class ItemOperatorFactory
{
public:
    static ItemOperator* getItemOperator(Item* item);
};