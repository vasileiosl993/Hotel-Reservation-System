#ifndef Reservation_H
#define Reservation_H

#include <string>

using namespace std;
class Room;

class Reservation
{
public:
	Reservation() ;
	~Reservation();

	//functions
	void setName(string);
	void setArrival(int);
	void setDays(int);
	void setNumber(int);
	void setRoom(Room*);

	int getID();
	string getName();
	int getArrival();
	int getDays();
	int getNumber();
	Room* getRoom();

	//Member methods
	void reserve(Room*);

private:
	string customer_;	//customer name
	static int id_;
	unsigned int res_id_;	//reservation id
	int arrival_;	//arrival
	int days_;	//days of stay
	int number_of_people_;	//number of people
	Room* room_;	//room

};
#endif
