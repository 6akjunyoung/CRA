#include <vector>
#include "Customer.h"

void Customer::addRental(Rental arg)
{
    rentals.push_back(arg);
}

string Customer::statement()
{
    string result = "";
    vector<string> titleList;
    vector<double> costList;

    for (Rental rental : rentals)
    {
        titleList.push_back(rental.getMovieTitle());
        costList.push_back(rental.getCost());
    }

    double totalAmount = getTotalAmount();
    int totalPoint = getTotalPoints();

    result += getHeader(name);
    result += getMainContents(titleList, costList);
    result += getFooter(totalAmount, totalPoint);

    return result;
}

string Customer::getHeader(string customerName)
{
    return "Rental Record for " + customerName + "\n";
}

string Customer::getMainContents(vector<string> titleList, vector<double> costList)
{
    string result = "";

    for (int i = 0; i < titleList.size(); i++)
    {
        result += "\t" + titleList[i] + "\t" + to_string_with_short_precision(costList[i]) + "\n";
    }
    return result;
}

string Customer::getFooter(double cost, int point)
{
    return "Amount owed is " + to_string_with_short_precision(cost) + "\n" +
        "You earned " + std::to_string(point) + " frequent renter points";
}

double Customer::getTotalAmount()
{
    double totalAmount = 0;
    for (Rental rental : rentals)
    {
        totalAmount += rental.getCost();
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
