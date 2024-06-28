#include "Customer.h"

void Customer::addRental(Rental arg)
{
    rentals.push_back(arg);
}

string Customer::getName() {
    return name;
}

string Customer::statement()
{
    string result = "Rental Record for " + getName() + "\n";

    for (Rental rental : rentals)
    {
        result += "\t" + rental.getMovie().getTitle() +
                  "\t" + to_string_with_short_precision(getAmountOf(rental)) + "\n";
    }

    result += "Amount owed is " + to_string_with_short_precision(getTotalAmount()) + "\n";
    result += "You earned " + std::to_string(getTotalPoints()) + " frequent renter points";

    return result;
}

double Customer::getTotalAmount()
{
    double totalAmount = 0;
    for (Rental rental : rentals)
    {
        totalAmount += getAmountOf(rental);
    }
    return totalAmount;
}

int Customer::getTotalPoints()
{
    int frequentRenterPoints = 0;
    for (Rental rental : rentals)
    {
        frequentRenterPoints += getPointsOf(rental);
    }
    return frequentRenterPoints;
}

double Customer::getAmountOf(Rental& rental)
{
    double thisAmount = 0;

    //determine amounts for rental
    switch (rental.getMovie().getCategory())
    {
    case Movie::REGULAR:
        thisAmount += getRegularMovieAmount(rental.getDaysRented());
        break;
    case Movie::NEW_RELEASE:
        thisAmount += getNewReleaseMovieAmount(rental.getDaysRented());
        break;
    case Movie::CHILDRENS:
        thisAmount += getChildrenMovieAmount(rental.getDaysRented());
        break;
    }
    return thisAmount;
}

double Customer::getChildrenMovieAmount(int daysRented)
{
    double amount = 1.5;
    if (daysRented > 3)
        amount += (daysRented - 3) * 1.5;
    return amount;
}

double Customer::getNewReleaseMovieAmount(int daysRented)
{
    return daysRented * 3;
}

double Customer::getRegularMovieAmount(int daysRented)
{
    double amount = 2;

    if (daysRented > 2)
    {
        amount += (daysRented - 2) * 1.5;
    }
    return amount;
}

int Customer::getPointsOf(Rental& rental)
{
    int rentalPoints = 1;

    if (rental.getMovie().getCategory() == Movie::NEW_RELEASE)
    {
        if (rental.getDaysRented() > 1)
        {
            rentalPoints++;
        }
    }
    return rentalPoints;
}

string Customer::to_string_with_short_precision(double tar)
{
    char buf[20] = { 0 };
    sprintf_s(buf, sizeof(buf), "%.1f", tar);
    return string(buf);
}
