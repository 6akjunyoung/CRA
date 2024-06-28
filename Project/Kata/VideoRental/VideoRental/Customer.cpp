#include "Customer.h"

void Customer::addRental(Rental arg)
{
    rentals.push_back(arg);
}

string Customer::statement()
{
    string result = "";
    
    result += getHeader();
    result += getMainContents();
    result += getFooter();

    return result;
}

string Customer::getFooter()
{
    return "Amount owed is " + to_string_with_short_precision(getTotalAmount()) + "\n" +
           "You earned " + std::to_string(getTotalPoints()) + " frequent renter points";
}

string Customer::getHeader()
{
    return "Rental Record for " + name + "\n";
}

string Customer::getMainContents()
{
    string result = "";

    for (Rental rental : rentals)
    {
        result += "\t" + rental.getMovieTitle() +
                  "\t" + to_string_with_short_precision(rental.getCharge()) + "\n";
    }
    return result;
}

double Customer::getTotalAmount()
{
    double totalAmount = 0;
    for (Rental rental : rentals)
    {
        totalAmount += rental.getCharge();
    }
    return totalAmount;
}

int Customer::getTotalPoints()
{
    int frequentRenterPoints = 0;
    for (Rental rental : rentals)
    {
        frequentRenterPoints += rental.getPoint();
    }
    return frequentRenterPoints;
}

string Customer::to_string_with_short_precision(double tar)
{
    char buf[20] = { 0 };
    sprintf_s(buf, sizeof(buf), "%.1f", tar);
    return string(buf);
}
