#define interface struct
interface Car
{
    virtual void go() = 0;
};

class RacingCar : public Car {
public:
    RacingCar(int max_fuel) {
        max_fuel_ = max_fuel;
        remaining_fuel_ = max_fuel;
        power_ = 0;
    }

    void go() override
    {
        Accelerate();
    }

private:
    int max_fuel_;
    int remaining_fuel_;
    int power_;

    void Accelerate() {
        power_++;
        remaining_fuel_--;
    }
};

class Pilot {
public:
    Pilot(Car* firstcar) {
        vehicle_ = firstcar;
    }

    void changeCar(Car* newcar)
    {
        vehicle_ = newcar;
    }

    void IncreaseSpeed() {
        vehicle_->go();
    }

private:
    Car* vehicle_;
};

