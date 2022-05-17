#include "stdafx.h"
#include "Room.h"
#include "Reservation.h"
#include <iostream>
#include <iomanip>

using namespace std;
int Room::id_ = 100;

Room::Room()
{
	for (int i = 0; i < 30; i++) {
		availability_[i] = nullptr;
	}

	room_id_ = id_++; 
}


Room::~Room()
{
}


//set

void Room::setCapacity(int c) {
	capacity_ = c;
}

void Room::setPrice(double d) {
	price_per_person_ = d;
}

//get
int Room::getID() {
	return room_id_;
}

int Room::getCapacity() {
	return capacity_;
}

double Room::getPrice() {
	return price_per_person_;
}

//Methods
bool Room::addReservation(Reservation* reserved) {
	bool state=true;
	if (reserved->getArrival() + reserved->getDays() > 29) { return false; }
	for (int i = reserved->getArrival(); i < (reserved->getArrival() + reserved->getDays()); i++) {	  //Check availability and capacity of the room
		if (availability_[i] != nullptr || reserved->getNumber() > capacity_){
			state = false;
			break;
		}
	}
	if (state == true) {
		for (int i = reserved->getArrival(); i < (reserved->getArrival() + reserved->getDays()); i++) {
			availability_[i] = reserved;
		}
		reserved->setRoom((this));
	}
	return state;
}

double Room::billing() {
	int i = 0;
	double totalcost = 0;
	do {
		if (availability_[i] != nullptr) {
			totalcost += (availability_[i]->getNumber()*price_per_person_);
		}
		i++;
	} while (i < 30);
	return totalcost;
}

bool Room::cancel(int id) {
	for (int i = 0; i < 30; i++) {
		if (availability_[i] != nullptr && availability_[i]->getID() == id){
			availability_[i] = nullptr;
		}
	}
	return true;
}

float Room::occupancy(){
	int o = 0;
	float out = 0;
	for (int i = 0; i < 30; i++) {
		if (availability_[i] != nullptr) {
			o++;
		}
	}
	out = o*(100/30);
	return out;
}

Reservation* Room::getAvail(int i) {
	return availability_[i];
}
