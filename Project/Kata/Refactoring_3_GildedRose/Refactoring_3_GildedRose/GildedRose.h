#pragma once
#include <string>
#include <vector>
#include "ItemOperatorFactory.h"

using namespace std;

class GildedRose
{
public:
    vector<Item>& items;
    GildedRose(vector<Item>& items);

    void updateQuality();
};