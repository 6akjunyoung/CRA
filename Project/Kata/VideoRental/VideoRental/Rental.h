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

	double getCharge();
	int getPoint();

private:
	Movie movie;
	int daysRented;

	double getRegularMovieAmount(int dyasRented);
	double getNewReleaseMovieAmount(int daysRented);
	double getChildrenMovieAmount(int daysRented);
};