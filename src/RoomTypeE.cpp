#include "stdafx.h"
#include "RoomTypeE.h"
#include "Reservation.h"


RoomTypeE::RoomTypeE()
{
}


RoomTypeE::~RoomTypeE()
{
}

//Methods

bool RoomTypeE::cancel(int id) {
	for (int i = 0; i < 30; i++) {
		if (availability_[i] != nullptr && getCapacity() < 3 && availability_[i]->getID() == id) {
			availability_[i] = nullptr;
		}
	}
	return true;
}