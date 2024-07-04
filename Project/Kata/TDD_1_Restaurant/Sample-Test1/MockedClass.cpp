#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../TDD_1_Restaurant/MailSender.cpp"
#include "../TDD_1_Restaurant/SmsSender.cpp"
#include "../TDD_1_Restaurant/BookingScheduler.cpp"

#include <iostream>
#include <stdexcept>

using namespace std;

class MockedCustomer : public Customer
{
public:
	MockedCustomer(string name, string phoneNumber) : Customer{ name, phoneNumber } {}
	MOCK_METHOD(string, getEmail, (), ());
};

class TestableBookingScheduler : public BookingScheduler
{
public:
	TestableBookingScheduler(int capacityPerHour, tm dateTime)
		: BookingScheduler{ capacityPerHour }, dateTime{ dateTime }
	{}

protected:
	time_t getNow() override
	{
		return mktime(&dateTime);
	}

private:
	tm dateTime;
};

class TestableMailSender : public MailSender
{
public:
	void sendMail(Schedule* schedule)
	{
		cout << "Send E-mail (TEST)" << endl;
		sendMethodIsCalled = true;
	}

	bool isSendMethodCalled()
	{
		return sendMethodIsCalled;
	}

private:
	bool sendMethodIsCalled = false;
};

class TestableSmsSender : public SmsSender
{
public:
	void send(Schedule* schedule) override
	{
		cout << "Send SMS (TEST)" << endl;
		sendMethodIsCalled = true;
	}

	bool isSendMethodCalled()
	{
		return sendMethodIsCalled;
	}

private:
	bool sendMethodIsCalled = false;
};