#include "stdafx.h"
#include "RoomTypeC.h"
#include "Reservation.h"
#include <iostream>

using namespace std;

RoomTypeC::RoomTypeC()
{
}


RoomTypeC::~RoomTypeC()
{
}

//set
void RoomTypeC::setMinPeople(int p) {
	min_people_ = p;
}

void RoomTypeC::setMinDays(int d) {
	min_days_ = d;
}

//Methods

bool RoomTypeC::addReservation(Reservation& reserved) {
	bool state = true;
	if (reserved.getArrival() + reserved.getDays() > 29) { return false; }
	for (int i = reserved.getArrival(); i < (reserved.getArrival() + reserved.getDays()); i++) {	//Elegxos an to dwmatio einai diathesimo kai xwrane ta atoma
		if (availability_[i] != nullptr || reserved.getNumber() > getCapacity() || reserved.getDays() < min_days_ || reserved.getNumber() < min_people_) {
			state = false;
			break;
		}
	}
	if (state == true) {
		for (int i = reserved.getArrival(); i < (reserved.getArrival() + reserved.getDays()); i++) {
			availability_[i] = &reserved;
		}
		reserved.setRoom(reserved.getRoom());
		cout << "Egine krathsh" << endl;
	}
	else {
		cout << "Den egine krathsh" << endl;
	}
	return state;
}