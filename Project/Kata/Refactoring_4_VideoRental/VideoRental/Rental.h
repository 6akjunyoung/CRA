#pragma once
#include "Movie.h"

class Rental
{
public:
	Rental(Movie& movie, int days_rented)
		: movie(movie),
		daysRented(days_rented)
	{
	}

	string getMovieTitle();

	double getCost();
	int getPoint();

private:
	Movie movie;
	int daysRented;
};