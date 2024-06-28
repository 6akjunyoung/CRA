#pragma once
#include <iostream>
#include "Movie.h"

#define interface struct

class RentalCalculator
{
public:
	virtual double getCost(int daysRented);
	virtual int getPoint(int daysRented);
};

class NewReleaseRentalCalculator : public RentalCalculator
{
public:
	double getCost(int daysRented) override;
	int getPoint(int daysRented) override;
};

class ChildrenRentalCalculator : public RentalCalculator
{
public:
	double getCost(int daysRented) override;
};

class RentalCalculatorFactory
{
public:
	static RentalCalculator* getRentalCalculator(int category);
};