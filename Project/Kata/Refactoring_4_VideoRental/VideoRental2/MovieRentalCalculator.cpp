#pragma once
#include "Movie.cpp"

class MovieRentalCalculator
{
public:
	static double calculateCost(int movieType, int daysRented);
	static int calculatePoints(int movieType, int daysRented);
};

double MovieRentalCalculator::calculateCost(int movieType, int daysRented)
{
	double cost = 0;

	switch (movieType)
	{
	case Movie::REGULAR:
		cost += 2;
		if (daysRented > 2)
			cost += (daysRented - 2) * 1.5;
		break;
	case Movie::NEW_RELEASE:
		cost += daysRented * 3;
		break;
	case Movie::CHILDRENS:
		cost += 1.5;
		if (daysRented > 3)
			cost += (daysRented - 3) * 1.5;
		break;
	}
	return cost;
}

int MovieRentalCalculator::calculatePoints(int movieType, int daysRented)
{
	if (Movie::NEW_RELEASE == movieType && daysRented > 1) {
		return 2;
	}
	return 1;
}
