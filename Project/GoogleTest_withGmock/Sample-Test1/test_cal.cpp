#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../GoogleTest_withGmock/cal.cpp"

using namespace testing;
using namespace std;

class MockCalculator : public Cal
{
public:
    MOCK_METHOD(int, getSum, (int a, int b), ());
    MOCK_METHOD(int, getValue, (), ());
};

class MockString : public string
{
public:
    MOCK_METHOD(int, length, (), ());
};

TEST(MOCK_TEST, StringLength)
{
    MockString mockString;
    EXPECT_CALL(mockString, length()).WillRepeatedly(Return(500));

    EXPECT_EQ(500, mockString.length());
    EXPECT_EQ(500, mockString.length());
}

TEST(CalTest, CalMock)
{
    MockCalculator mock_cal;
    EXPECT_CALL(mock_cal, getSum(_, _)).Times(2);

    EXPECT_EQ(0, mock_cal.getSum(1, 2));
    EXPECT_EQ(0, mock_cal.getSum(1, 2));
}

TEST(CalTest, CalMock2)
{
    MockCalculator mock_cal;
    EXPECT_CALL(mock_cal, getSum(1, 2))
        .WillRepeatedly(Return(100));

    EXPECT_EQ(100, mock_cal.getSum(1, 2));
    EXPECT_EQ(100, mock_cal.getSum(1, 2));
    EXPECT_EQ(100, mock_cal.getSum(1, 2));

    EXPECT_CALL(mock_cal, getSum(Ne(1), 6))
        .Times(4)
        .WillOnce(Return(1))
        .WillOnce(Return(10))
        .WillRepeatedly(Return(100));

    EXPECT_EQ(1, mock_cal.getSum(2, 6));
    EXPECT_EQ(10, mock_cal.getSum(3, 6));
    EXPECT_EQ(100, mock_cal.getSum(4, 6));
    EXPECT_EQ(100, mock_cal.getSum(5, 6));
}

TEST(CalTest, CalMock3)
{
    Cal cal;
    MockCalculator mock_cal;
    EXPECT_CALL(mock_cal, getValue())
        .Times(2)
        .WillRepeatedly(Return(10000));

    EXPECT_THAT(cal.getValue(), Eq(0));
    EXPECT_THAT(mock_cal.getValue(), Eq(10000));
    EXPECT_THAT(mock_cal.getValue(), Eq(10000));
}
