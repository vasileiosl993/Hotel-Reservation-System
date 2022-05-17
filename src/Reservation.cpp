#include "stdafx.h"
#include "Room.h"
#include "Reservation.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;
int Reservation::id_ = 1;

Reservation::Reservation()
{
	room_ = nullptr;
	res_id_ = id_++;
	}


Reservation::~Reservation()
{
}

//set
void Reservation::setName(string name) {
	customer_ = name;
}

void Reservation::setArrival(int a) {
	arrival_ = a;
}

void Reservation::setDays(int d) {
	days_ = d;
}

void Reservation::setNumber(int n) {
	number_of_people_ = n;
}

void Reservation::setRoom(Room* room) {
	room_ = room;
}

//get
int Reservation::getID() {
	return res_id_;
}

string Reservation::getName() {
	return customer_;
}
int Reservation::getArrival() {
	return arrival_;
}

int Reservation::getDays() {
	return days_;
}

int Reservation::getNumber() {
	return number_of_people_;
}

Room* Reservation::getRoom() {
	return room_;
}

//Member methods
void Reservation::reserve(Room* room1)
{
	room_ = room1;
}