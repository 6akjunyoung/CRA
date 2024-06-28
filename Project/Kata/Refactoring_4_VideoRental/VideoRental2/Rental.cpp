#pragma once
#include "Movie.cpp"
#include "MovieRentalCalculator.cpp"

class Rental
{
public:
	Rental(Movie& movie, int days_rented)
		: movie(movie),
		daysRented(days_rented)
	{
		updateCost();
		updatePoint();
	}

	string getTitle()
	{
		return movie.getTitle();
	}

	double getCost()
	{
		return cost;
	}

	int getPoint()
	{
		return point;
	}

private:
	Movie movie;
	int daysRented;

	double cost;
	int point;

	void updateCost()
	{
		cost = MovieRentalCalculator::calculateCost(movie.getPriceCode(), daysRented);
	}
	void updatePoint()
	{
		point = MovieRentalCalculator::calculatePoints(movie.getPriceCode(), daysRented);
	}
};