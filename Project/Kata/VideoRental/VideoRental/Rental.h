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

	int getDaysRented();
	Movie getMovie();

private:
	Movie movie;
	int daysRented;
};