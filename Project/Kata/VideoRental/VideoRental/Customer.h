#pragma once

#include <vector>
#include "Movie.h"
#include "Rental.h"

using std::string;
using std::vector;

class Customer {
public:
    Customer(const string& name) : name(name) {}

    void addRental(Rental arg);
    string getName();
    string statement();

private:
    string name;
    vector<Rental> rentals;

    string to_string_with_short_precision(double tar);
};