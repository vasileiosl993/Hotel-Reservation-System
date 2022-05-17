#include "stdafx.h"
#include "Hotel.h"
#include "Room.h"
#include "Reservation.h"
#include <list>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;


Hotel::Hotel()
{
}


Hotel::~Hotel()
{
}

//auxiliary functions
int Hotel::sizeofbookings() {
	return bookings_.size();
}

int Hotel::sizeofrooms() {
	return rooms_.size();
}

void Hotel::randomResCancel() {
	vector<Reservation*> res(bookings_.begin(), bookings_.end());
	vector<Reservation*>::iterator it = res.begin();
	
	if (res.size() >= 1) {
		advance(it, rand() % res.size());
		cout << "By chance, ";
		HotelCancel((*it)->getID());
	}

}
void Hotel::printResInfo() {
	vector<Reservation*> res(bookings_.begin(), bookings_.end());
	for (int i = 0; i < res.size(); i++) {
		cout << setw(16) << left << res[i]->getID() << "| " << setw(15) << left << res[i]->getName() << "| " << setw(4) << left << res[i]->getRoom()->getID() << endl;
	}
}

void Hotel::printRoomInfo() {
	vector<Room*> room(rooms_.begin(), rooms_.end());
	for (int i = 0; i < room.size(); i++) {
		cout << setw(16) << left << room[i]->getID() << left << "| " << setw(14) << right << room[i]->occupancy() << "%| " << setw(4) << left << IncomeCalculation(room[i]->getID()) << endl;
	}
}

//Member Methods
void Hotel::addRoom(Room* room) {
	rooms_.push_back(room);
}

Room* Hotel::retrieveRoomByID(int id) {
	list<Room*>::iterator it;

	for(it = rooms_.begin(); it != rooms_.end(); ++it)
	{
		if ((*it)->getID() == id) { 
			return (*it);			
		}
	}
	return nullptr;
}

Reservation* Hotel::retrieveReservationByID(int id) {
	list<Reservation*>::iterator it;

	for (it = bookings_.begin(); it != bookings_.end(); ++it)
	{
		if ((*it)->getID() == id) {
			return (*it);
		}
	}
	return nullptr;
}

bool Hotel::addReservationToRoom(Reservation* res, int id){
	if (retrieveRoomByID(id) && retrieveRoomByID(id)->addReservation(res)) {	//It must be checked if the retrieveRoomByID() returns object and not nullptr!
		bookings_.push_back(res);
		cout << "The reservation was made in the room with id number: " << id << endl;
		return true;
	}
	cout << "No reservation was made! " << endl;
	return false;
}

int Hotel::HotelAddReservation(Reservation* res){
	list<Room*>::iterator it;
	
	for (it = rooms_.begin(); it != rooms_.end(); ++it) 
	{
		if ((*it)->addReservation(res)) {
			cout << "The reservation was made in the room with id number: " << (*it)->getID() << endl;
			bookings_.push_back(res);
			return (*it)->getID();;
		}
	}
	cout << "No reservation was made! "<< endl;
	return 0;
}

bool Hotel::HotelCancel(int id) {
	list<Reservation*>::iterator it;

	for (it = bookings_.begin(); it != bookings_.end(); ++it)
	{
		if ((*it) == retrieveReservationByID(id)) {
			(*it)->getRoom()->cancel(id);
			bookings_.erase(it);
			cout << "Cancellation confirmed! " << endl;
			return true;
		}
		cout << "Τhe cancellation was not confirmed! " << endl;
		return false;
	}
}

void Hotel::reservationPlan() {		//plan printing
	list<Room*>::iterator it;

	cout << setw(8) << "ROOM ";
	for (int i = 1; i < 31; i++) {
		cout << setw(3) << left << i ;
	}
	cout << endl << endl;
	for (it = rooms_.begin(); it != rooms_.end(); ++it) {
		cout << setw(8) << left << (*it)->getID();
		for (int i = 0; i < 30; i++) {
			if ((*it)->getAvail(i) == nullptr) {
				cout << setw(3) << left << "_ ";
			}
			else {
				cout << setw(3) << left << "* ";
			}
		}
		cout << endl << endl;
	}
}

//Function Overload
double Hotel::IncomeCalculation(int id) {
	double result = 0.0;
	if (retrieveRoomByID(id)) {		//It must be checked if the retrieveRoomByID() returns object and not nullptr!
		result = retrieveRoomByID(id)->billing();
		return result;
	}
	return 0;
}

double Hotel::IncomeCalculation() {
	list<Room*>::iterator it;
	double result = 0.0;

	for (it = rooms_.begin(); it != rooms_.end(); ++it) {
		result += (*it)->billing();
	}
	return result;
}
