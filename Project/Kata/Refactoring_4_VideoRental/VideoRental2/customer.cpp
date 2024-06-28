#pragma once

#include <vector>
#include "Seller.cpp"

using std::string;
using std::vector;
class Customer {
public:
    Customer(const string& name) : name(name) { }

    void addRental(Rental arg)
    {
        seller.addRental(arg);
    }

    string statement()
    {
        return seller.getBill(name);
    }

private:
    string name;
    Seller seller;
};