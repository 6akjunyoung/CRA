#include "pch.h"
#include "../VideoRental/Customer.cpp"
#include "../VideoRental/Rental.cpp"
#include "../VideoRental/Movie.cpp"
#include "../VideoRental/RentalCalculator.cpp"

using std::string;

class CustomerTest : public testing::Test {
protected:
    static const string NAME_FORTEST;
    static const string TITLE_FORTEST;
    static const int INVALID_CATEGORY;

    string getHeader(string name = NAME_FORTEST)
    {
        return ("Rental Record for " + name + "\n");
    }

    string getMainContent(double fee, string title = TITLE_FORTEST)
    {
        return ("\t" + title + "\t" + to_string_from_double(fee) + "\n");
    }

    string getFooter(double totalAmount, int totalPoint)
    {
        return ("Amount owed is " + to_string_from_double(totalAmount) + "\n" +
                "You earned " + std::to_string(totalPoint) + " frequent renter points");
    }

    string to_string_from_double(double tar)
    {
        char buf[20] = { 0 };
        sprintf_s(buf, sizeof(buf), "%.1f", tar);
        return string(buf);
    }
};

const string CustomerTest::NAME_FORTEST = "NAME_NOT_IMPORTANT";
const string CustomerTest::TITLE_FORTEST = "TITLE_NOT_IMPORTANT";
const int CustomerTest::INVALID_CATEGORY = 0xFF;

TEST_F(CustomerTest, BasicTest) {
    Customer customer = Customer(string("Bob"));
    customer.addRental(Rental(Movie(string("Jaws"), Movie::REGULAR), 2));
    customer.addRental(Rental(Movie(string("Golden Eye"), Movie::REGULAR), 3));
    customer.addRental(Rental(Movie(string("Short New"), Movie::NEW_RELEASE), 1));
    customer.addRental(Rental(Movie(string("Long New"), Movie::NEW_RELEASE), 2));
    customer.addRental(Rental(Movie(string("Bambi"), Movie::CHILDRENS), 3));
    customer.addRental(Rental(Movie(string("Toy Story"), Movie::CHILDRENS), 4));

    std::cout << getHeader("Bob");
    std::cout << string("Rental Record for Bob\n");

    string expected = "" +
        getHeader("Bob") +
        getMainContent(2, "Jaws") +
        getMainContent(3.5, "Golden Eye") +
        getMainContent(3, "Short New") +
        getMainContent(6, "Long New") +
        getMainContent(1.5, "Bambi") +
        getMainContent(3, "Toy Story") +
        getFooter(19, 7);

    EXPECT_EQ(expected, customer.statement());
}

TEST_F(CustomerTest, StatementForNoRental) {
    //arrange
    Customer customer = Customer(NAME_FORTEST);

    //act
    string statement = customer.statement();

    //assert
    EXPECT_EQ(statement, getHeader() + getFooter(0, 0));
}

TEST_F(CustomerTest, StatementForRegularMovieRentalForLessThan3Days) {
    // arrange
    Customer customer = Customer(NAME_FORTEST);
    Movie movie = Movie(TITLE_FORTEST, Movie::REGULAR);
    int daysRented = 2;
    Rental rental = Rental(movie, daysRented);
    customer.addRental(rental);

    // act
    string statement = customer.statement();

    // assert
    EXPECT_EQ(statement, getHeader()
        + getMainContent(2)
        + getFooter(2, 1));
}

TEST_F(CustomerTest, StatementForRegularMovieRentalForMoreThan2Days) {
    // arrange
    Customer customer = Customer(NAME_FORTEST);
    Movie movie = Movie(TITLE_FORTEST, Movie::REGULAR);
    int daysRented = 3;
    Rental rental = Rental(movie, daysRented);
    customer.addRental(rental);

    // act
    string statement = customer.statement();

    // assert
    EXPECT_EQ(statement, getHeader()
        + getMainContent(3.5)
        + getFooter(3.5, 1));
}

TEST_F(CustomerTest, StatementForNewReleaseMovie) {
    // arrange
    Customer customer = Customer(NAME_FORTEST);
    Movie movie = Movie(TITLE_FORTEST, Movie::NEW_RELEASE);
    int daysRented = 1;
    Rental rental = Rental(movie, daysRented);
    customer.addRental(rental);

    // act
    string statement = customer.statement();

    // assert
    EXPECT_EQ(statement, getHeader()
        + string("\tTITLE_NOT_IMPORTANT\t3.0\n")
        + string("Amount owed is 3.0\n")
        + string("You earned 1 frequent renter points"));
}

TEST_F(CustomerTest, StatementForChildrensMovieRentalMoreThan3Days) {
    // arrange
    Customer customer = Customer(NAME_FORTEST);
    Movie movie = Movie(TITLE_FORTEST, Movie::CHILDRENS);
    int daysRented = 4;
    Rental rental = Rental(movie, daysRented);
    customer.addRental(rental);

    // act
    string statement = customer.statement();

    // assert
    EXPECT_EQ(statement, getHeader()
        + string("\tTITLE_NOT_IMPORTANT\t3.0\n")
        + string("Amount owed is 3.0\n")
        + string("You earned 1 frequent renter points"));
}

TEST_F(CustomerTest, StatementForChildrensMovieRentalMoreThan4Days) {
    // arrange
    Customer customer = Customer(NAME_FORTEST);
    Movie movie = Movie(TITLE_FORTEST, Movie::CHILDRENS);
    int daysRented = 3;
    Rental rental = Rental(movie, daysRented);
    customer.addRental(rental);

    // act
    string statement = customer.statement();

    // assert
    EXPECT_EQ(statement, getHeader()
        + string("\tTITLE_NOT_IMPORTANT\t1.5\n")
        + string("Amount owed is 1.5\n")
        + string("You earned 1 frequent renter points"));
}

TEST_F(CustomerTest, StatementForNewReleaseMovieRentalMoreThan1Day) {
    // arrange
    Customer customer = Customer(NAME_FORTEST);
    Movie movie = Movie(TITLE_FORTEST, Movie::NEW_RELEASE);
    int daysRented = 2;
    Rental rental = Rental(movie, daysRented);
    customer.addRental(rental);

    // act
    string statement = customer.statement();

    // assert
    EXPECT_EQ(statement, getHeader()
        + string("\tTITLE_NOT_IMPORTANT\t6.0\n")
        + string("Amount owed is 6.0\n")
        + string("You earned 2 frequent renter points"));
}

TEST_F(CustomerTest, StatementForFewMovieRental) {
    // arrange
    Customer customer = Customer(NAME_FORTEST);
    Movie regularMovie = Movie(TITLE_FORTEST, Movie::REGULAR);
    Movie newReleaseMovie = Movie(TITLE_FORTEST, Movie::NEW_RELEASE);
    Movie childrensMovie = Movie(TITLE_FORTEST, Movie::CHILDRENS);
    customer.addRental(Rental(regularMovie, 1));
    customer.addRental(Rental(newReleaseMovie, 4));
    customer.addRental(Rental(childrensMovie, 4));

    // act
    string statement = customer.statement();

    // assert
    EXPECT_EQ(statement, getHeader()
        + string("\tTITLE_NOT_IMPORTANT\t2.0\n")
        + string("\tTITLE_NOT_IMPORTANT\t12.0\n")
        + string("\tTITLE_NOT_IMPORTANT\t3.0\n")
        + string("Amount owed is 17.0\n")
        + string("You earned 4 frequent renter points"));
}

TEST_F(CustomerTest, StatementForInvalidCategory) {
    // arrange
    Customer customer = Customer(NAME_FORTEST);
    Movie invalidMovie = Movie(TITLE_FORTEST, INVALID_CATEGORY);

    customer.addRental(Rental(invalidMovie, 1));

    // act
    string statement = customer.statement();

    // assert
    EXPECT_EQ(statement, getHeader()
        + string("\tTITLE_NOT_IMPORTANT\t0.0\n")
        + string("Amount owed is 0.0\n")
        + string("You earned 0 frequent renter points"));
}