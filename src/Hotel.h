#ifndef Hotel_H
#define Hotel_H

#include <string>
#include <list>
#include <vector>

using namespace std;
class Room;
class Reservation;

class Hotel
{
public:
	Hotel();
	~Hotel();

	//auxiliary functions
	int sizeofbookings();
	int sizeofrooms();
	void randomResCancel();
	void printResInfo();
	void printRoomInfo();

	//Member Methods
	void addRoom(Room*);
	Room* retrieveRoomByID(int);
	Reservation* retrieveReservationByID(int);
  bool addReservationToRoom(Reservation*, int);
	int HotelAddReservation(Reservation*);
	bool HotelCancel(int);
	void reservationPlan();


	//Function Overload
	double IncomeCalculation(int);
	double IncomeCalculation();

private:
	string name_;
	list<Room*> rooms_;
	list<Reservation*> bookings_;

};
#endif
