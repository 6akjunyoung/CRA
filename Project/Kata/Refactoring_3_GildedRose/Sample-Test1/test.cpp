#include "pch.h"

#include "../Refactoring_3_GildedRose/GildedRose.cpp"
#include "../Refactoring_3_GildedRose/Item.cpp"
#include "../Refactoring_3_GildedRose/ItemOperator.cpp"
#include "../Refactoring_3_GildedRose/ItemOperatorFactory.cpp"

class GildedRoseTest : public testing::Test {

protected:
    const string SULFURAS = "Sulfuras, Hand of Ragnaros";
    const string AGED_BRIE = "Aged Brie";
    const string BACKSTAGE = "Backstage passes to a TAFKAL80ETC concert";
    const string NONAME = "noname";
};

TEST_F(GildedRoseTest, Foo) {
    vector<Item> items;
    items.push_back(Item("Foo", 0, 0));
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ("Foo", app.items[0].name);
}

TEST_F(GildedRoseTest, ShouldBeNothingWhenNoItem) {
    vector<Item> items;
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(0, items.size());
}

TEST_F(GildedRoseTest, NoName_Sellin0_Quality0) {
    vector<Item> items = { Item(NONAME, 0, 0) };
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST_F(GildedRoseTest, NoName_Sellin0_Quality1) {
    vector<Item> items = { Item(NONAME, 0, 1) };
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST_F(GildedRoseTest, NoName_SellinM2_Quality10) {
    vector<Item> items = { Item(NONAME, -2, 10) };
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(-3, app.items[0].sellIn);
    EXPECT_EQ(8, app.items[0].quality);
}

TEST_F(GildedRoseTest, Sulfuras_Sellin0_Quality80) {
    vector<Item> items = { Item(SULFURAS, 0, 80) };
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(0, app.items[0].sellIn);
    EXPECT_EQ(80, app.items[0].quality);
}

TEST_F(GildedRoseTest, Sulfuras_SellinM2_Quality80) {
    vector<Item> items = { Item(SULFURAS, -2, 80) };
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(-2, app.items[0].sellIn);
    EXPECT_EQ(80, app.items[0].quality);
}

TEST_F(GildedRoseTest, AgedBrie_Sellin0_Quality0) {
    vector<Item> items = { Item(AGED_BRIE, 0, 0) };
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(2, app.items[0].quality);
}

TEST_F(GildedRoseTest, AgedBrie_Sellin0_Quality50) {
    vector<Item> items = { Item(AGED_BRIE, 0, 50) };
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(50, app.items[0].quality);
}

TEST_F(GildedRoseTest, Backstage_Sellin0_Quality0) {
    vector<Item> items = { Item(BACKSTAGE, 0, 0) };
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST_F(GildedRoseTest, Backstage_Sellin0_Quality49) {
    vector<Item> items = { Item(BACKSTAGE, 0, 49) };
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST_F(GildedRoseTest, Backstage_Sellin1_Quality40) {
    vector<Item> items = { Item(BACKSTAGE, 1, 40) };
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(0, app.items[0].sellIn);
    EXPECT_EQ(43, app.items[0].quality);
}

TEST_F(GildedRoseTest, Backstage_Sellin12_Quality0) {
    vector<Item> items = { Item(BACKSTAGE, 12, 0) };
    GildedRose app(items);

    app.updateQuality();

    EXPECT_EQ(11, app.items[0].sellIn);
    EXPECT_EQ(1, app.items[0].quality);
}