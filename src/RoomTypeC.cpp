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
	for (int i = reserved.getArrival(); i < (reserved.getArrival() + reserved.getDays()); i++) {	//Check availability and capacity of the room
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
		cout << "Reservation was made " << endl;
	}
	else {
		cout << "No reservation was made " << endl;
	}
	return state;
}
