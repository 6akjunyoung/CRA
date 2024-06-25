#pragma once
#include <string>
#include <exception>

#define interface struct

using namespace std;

interface Flyable {
    virtual void Fly() = 0;
};

interface Bird {
    virtual void Molt() = 0;
};

class Eagle : public Bird, public Flyable {
public:
    Eagle(int initial_feather_count) {
        number_of_feathers_ = initial_feather_count;
    }

    void Fly() override {
        current_location_ = "in the air";
    }

    void Molt() override {
        number_of_feathers_ -= 1;
    }

private:
    string current_location_;
    int number_of_feathers_;
};

class Penguin : public Bird {
public:
	Penguin(int initial_feather_count) {
		number_of_feathers_ = initial_feather_count;
	}

	void Molt() override {
		number_of_feathers_ -= 1;
	}

	void swim() {
		current_location_ = "in the water";
	}

private:
	string current_location_;
	int number_of_feathers_;
};