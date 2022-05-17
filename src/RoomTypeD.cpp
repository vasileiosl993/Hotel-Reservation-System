#include "stdafx.h"
#include "RoomTypeD.h"
#include "Reservation.h"

using namespace std;

RoomTypeD::RoomTypeD()
{
}


RoomTypeD::~RoomTypeD()
{
}

void RoomTypeD::setPrice(double p) {
	price_per_person_ = p;
}

double RoomTypeD::billing() {
	int i = 0;
	double totalcost = 0;
	do {
		if (availability_[i] != nullptr) {
			totalcost += (availability_[i]->getNumber()*price_per_person_);
		}
		i++;
	} while (i < 30);
	totalcost = totalcost*(0.7);
	return totalcost;
}