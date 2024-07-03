class Account
{
public:
    Account(int money) : balance(money)
    { }

    int getBalance()
    {
        return balance;
    }

    void deposit(int money)
    {
        balance += money;
    }

    void withdraw(int money)
    {
        balance -= money;
    }

    void applyInterest()
    {
        balance += getInterest(balance);
    }

    void setInterest(double InterestRateInPercent)
    {
        interestRate = (InterestRateInPercent / 100);
    }

    int getPredictedBalanceAfter(int year)
    {
        double expectedBalance = balance;
        for (int i = 0; i < year; i++)
        {
            expectedBalance += getInterest(expectedBalance);
        }
        return static_cast<int>(expectedBalance);
    }

private:
    int balance = 0;
    double interestRate = 0.05;

    int getInterest(int targetBalance)
    {
        return (targetBalance * interestRate);
    }
};