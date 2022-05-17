#include "stdafx.h"
#include "RoomTypeA.h"
#include "Reservation.h"

using namespace std;

RoomTypeA::RoomTypeA()
{
}


RoomTypeA::~RoomTypeA()
{
}

//functions
void RoomTypeA::setPrice(double d) {
	price_per_day_ = d;
}

double RoomTypeA::getPriceDay() {
	return price_per_day_;
}

//Methods
double RoomTypeA::billing() {
	double totalcost = 0;
	for (int i = 0; i < 30; i++) {
		if (availability_[i] != nullptr) {
			totalcost += price_per_day_;
		}
	}
	return totalcost;
}