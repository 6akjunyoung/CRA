#include "RentalCalculator.h"

#define UNUSED_PARAM(x) (x)

RentalCalculator* RentalCalculatorFactory::getRentalCalculator(int category)
{
    switch (category)
    {
    case Movie::REGULAR:
        return new RentalCalculator();
    case Movie::NEW_RELEASE:
        return new NewReleaseRentalCalculator();
    case Movie::CHILDRENS:
        return new ChildrenRentalCalculator();
    default:
        break;
    }

    return nullptr;
}

double RentalCalculator::getCost(int daysRented)
{
    double amount = 2;

    if (daysRented > 2)
    {
        amount += (daysRented - 2) * 1.5;
    }
    return amount;
}

int RentalCalculator::getPoint(int daysRented)
{
    UNUSED_PARAM(daysRented);

    return 1;
}

double NewReleaseRentalCalculator::getCost(int daysRented)
{
    return daysRented * 3;
}

int NewReleaseRentalCalculator::getPoint(int daysRented)
{
    if (daysRented > 1)
    {
        return 2;
    }
    return 1;
}

double ChildrenRentalCalculator::getCost(int daysRented)
{
    double amount = 1.5;
    if (daysRented > 3)
        amount += (daysRented - 3) * 1.5;
    return amount;
}
