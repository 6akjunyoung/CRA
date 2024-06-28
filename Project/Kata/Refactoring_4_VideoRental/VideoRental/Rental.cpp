#include <memory>
#include "Rental.h"
#include "RentalCalculator.h"

string Rental::getMovieTitle()
{
	return movie.getTitle();
}

double Rental::getCost()
{
    std::unique_ptr<RentalCalculator> rentalCalculator (RentalCalculatorFactory::getRentalCalculator(movie.getCategory()));
    if (nullptr == rentalCalculator)
    {
        return 0;
    }

    return rentalCalculator->getCost(daysRented);
}

int Rental::getPoint()
{
    std::unique_ptr<RentalCalculator> rentalCalculator(RentalCalculatorFactory::getRentalCalculator(movie.getCategory()));
    if (nullptr == rentalCalculator)
    {
        return 0;
    }

    return rentalCalculator->getPoint(daysRented);
}
