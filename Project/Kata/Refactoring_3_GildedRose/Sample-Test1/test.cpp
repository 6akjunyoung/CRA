#include "pch.h"
#include "../Refactoring_3_GildedRose/GildedRose.cpp"

class GildedRoseTest : public testing::Test {

};

TEST_F(GildedRoseTest, Foo) {
    vector<Item> items;
    items.push_back(Item("Foo", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Foo", app.items[0].name);
}