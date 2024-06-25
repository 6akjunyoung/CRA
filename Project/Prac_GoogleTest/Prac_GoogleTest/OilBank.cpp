#include "Vehicle.cpp"

class OilBank
{
public:
	void refuel(Vehicle* car)
	{
		car->SetRemainingFuel(car->GetMaxFuel());
	}
};