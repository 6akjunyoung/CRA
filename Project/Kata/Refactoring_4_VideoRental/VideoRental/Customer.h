#pragma once

#include <vector>
#include "Rental.h"

using std::string;
using std::vector;

class Customer {
public:
    Customer(const string& name) : name(name) {}

    void addRental(Rental arg);
    string statement();

private:
    string name;
    vector<Rental> rentals;

    string getHeader(string customerName);
    string getMainContents(vector<string> titleList, vector<double> costList);
    string getFooter(double cost, int point);

    double getTotalAmount();
    int getTotalPoints();

    string to_string_with_short_precision(double tar);
};