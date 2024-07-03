#include "pch.h"
#include "../Prac_GoogleTest/account.cpp"

class AccountTest : public testing::Test
{
public:
    Account account{ 10000 };

protected:
    void checkBalance(int expected)
    {
        int ret = account.getBalance();
        EXPECT_EQ(expected, ret);
    }
};

TEST_F(AccountTest, CreateAccountInit10000)
{
    checkBalance(10000);
}

TEST_F(AccountTest, Deposit)
{
    account.deposit(500);
    checkBalance(10500);
}

TEST_F(AccountTest, Withdraw)
{
    account.withdraw(600);
    checkBalance(9400);
}

TEST_F(AccountTest, CompoundInterest)
{
    account.applyInterest();
    checkBalance(10500);

    account.applyInterest();
    checkBalance(11025);
}

TEST_F(AccountTest, SetInterestRate)
{
    account.setInterest(7);
    checkBalance(10000);

    account.applyInterest();
    checkBalance(10700);
}

TEST_F(AccountTest, GetExpectedBalance)
{
    account.setInterest(10);
    checkBalance(10000);

    int balance = account.getPredictedBalanceAfter(3);
    EXPECT_EQ(13310, balance);
}