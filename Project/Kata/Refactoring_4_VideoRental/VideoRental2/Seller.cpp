#pragma once

#include <vector>
#include "Rental.cpp"

using namespace std;

class Seller
{
public:
    void addRental(Rental arg)
    {
        rentals.push_back(arg);
    }

    const string getBill(string customerName)
    {
        double totalAmount = 0;
        int totalpoints = 0;

        totalpoints = getTotalPoints();
        totalAmount = getTotalCost();

        return makeBill(customerName, totalAmount, totalpoints);
    }

    int getTotalPoints()
    {
        int points = 0;
        for (Rental each : rentals) {
            points += each.getPoint();
        }
        return points;
    }

    double getTotalCost()
    {
        double totalAmount = 0;
        for (Rental each : rentals) {
            totalAmount += each.getCost();
        }
        return totalAmount;
    }

    const string makeBill(std::string& customerName, double totalAmount, int frequentRenterPoints)
    {
        string result = "Rental Record for " + customerName + "\n";
        for (Rental each : rentals) {
            result += "\t" + each.getTitle() + "\t" + to_string_from_double(each.getCost()) + "\n";
        }
        result += "Amount owed is " + to_string_from_double(totalAmount) + "\n";
        result += "You earned " + std::to_string(frequentRenterPoints) + " frequent renter points";

        return result;
    }

private:
    vector<Rental> rentals;
    string to_string_from_double(double tar)
    {
        char buf[20] = { 0 };
        sprintf_s(buf, sizeof(buf), "%.1f", tar);
        return string(buf);
    }
};