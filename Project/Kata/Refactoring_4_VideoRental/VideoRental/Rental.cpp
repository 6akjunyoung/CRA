#include "Rental.h"

string Rental::getMovieTitle()
{
	return movie.getTitle();
}

double Rental::getCharge()
{
    double amount = 0;

    //determine amounts for rental
    switch (movie.getCategory())
    {
    case Movie::REGULAR:
        amount += getRegularMovieAmount(daysRented);
        break;
    case Movie::NEW_RELEASE:
        amount += getNewReleaseMovieAmount(daysRented);
        break;
    case Movie::CHILDRENS:
        amount += getChildrenMovieAmount(daysRented);
        break;
    }
    return amount;
}

int Rental::getPoint()
{
    int rentalPoints = 1;

    if (movie.getCategory() == Movie::NEW_RELEASE)
    {
        if (daysRented > 1)
        {
            rentalPoints++;
        }
    }
    return rentalPoints;
}

double Rental::getChildrenMovieAmount(int daysRented)
{
    double amount = 1.5;
    if (daysRented > 3)
        amount += (daysRented - 3) * 1.5;
    return amount;
}

double Rental::getNewReleaseMovieAmount(int daysRented)
{
    return daysRented * 3;
}

double Rental::getRegularMovieAmount(int daysRented)
{
    double amount = 2;

    if (daysRented > 2)
    {
        amount += (daysRented - 2) * 1.5;
    }
    return amount;
}
