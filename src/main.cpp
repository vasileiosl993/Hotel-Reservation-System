#include "stdafx.h"
#include "Hotel.h"
#include "Room.h"
#include "Reservation.h"
#include "RoomTypeA.h"
#include "RoomTypeB.h"
#include "RoomTypeC.h"
#include "RoomTypeD.h"
#include "RoomTypeE.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

#include "CharGenerator.h"	//Header for the cgener()


#define maxpeople 5	//Larger room in capacity.
#define maxdaysarr 30	//Μaximum arrival number.
#define maxdaysstay 29	//Μaximum number of stay.

using namespace std;


int main() 
{
	//---Rooms---
	
	//1.			//Creating rooms.
	Room Blue;
	Blue.setCapacity(4);
	Blue.setPrice(15.00);

	//2.
	Room Green;
	Green.setCapacity(5);
	Green.setPrice(13.50);

	//3.
	RoomTypeA Red;
	Red.setCapacity(2);
	Red.setPrice(70.50);

	//4.
	RoomTypeA Yellow;
	Yellow.setCapacity(4);
	Yellow.setPrice(60.00);

	//5.
	RoomTypeB Brown;
	Brown.setCapacity(6);
	Brown.setPrice(55.00);
	Brown.setDiscountDay(4.20);

	//6.
	RoomTypeB White;
	White.setCapacity(1);
	White.setPrice(80.60);
	White.setDiscountDay(6.20);

	//7.
	RoomTypeC Black;
	Black.setCapacity(6);
	Black.setPrice(12.50);
	Black.setMinPeople(3);
	Black.setMinDays(7);

	//8.
	RoomTypeC Pink;
	Pink.setCapacity(3);
	Pink.setPrice(11.00);
	Pink.setMinPeople(2);
	Pink.setMinDays(5);

	//9.
	RoomTypeD Purple;
	Purple.setCapacity(3);
	Purple.setPrice(6.60);

	//10.
	RoomTypeD Magenda;
	Magenda.setCapacity(4);
	Magenda.setPrice(4.50);

	//11.
	RoomTypeE Turquoise;
	Turquoise.setCapacity(5);
	Turquoise.setPrice(13.30);

	//12.
	RoomTypeE Veraman;
	Veraman.setCapacity(2);
	Veraman.setPrice(14.00);


	//---Hotel---

	Hotel Conte_Del_Mare;		//Αddition of rooms to the hotel.

	Conte_Del_Mare.addRoom(&Blue);
	Conte_Del_Mare.addRoom(&Green);
	Conte_Del_Mare.addRoom(&Red);
	Conte_Del_Mare.addRoom(&Yellow);
	Conte_Del_Mare.addRoom(&Brown);
	Conte_Del_Mare.addRoom(&White);
	Conte_Del_Mare.addRoom(&Black);
	Conte_Del_Mare.addRoom(&Pink);
	Conte_Del_Mare.addRoom(&Purple);
	Conte_Del_Mare.addRoom(&Magenda);
	Conte_Del_Mare.addRoom(&Turquoise);
	Conte_Del_Mare.addRoom(&Veraman);

	int j = 0;
	srand(time(NULL));
	int k;	

	do {
		if (j == 0) {
			string s1 = cgener(rand() % 12 + 3);
			Reservation* res_pointer = new Reservation();	//Create a reservation with a random name.
			res_pointer->setName(s1);
			res_pointer->setNumber(rand() % maxpeople + 1);
			res_pointer->setArrival(rand() % maxdaysarr);
			res_pointer->setDays(rand() % maxdaysstay + 1);

			Conte_Del_Mare.HotelAddReservation(res_pointer);
		}

		if (j == 0 && rand() % 100 < 25) {
			Conte_Del_Mare.randomResCancel();
		}

		cout << endl;
		cout << "What do you want to do: " << endl << endl;
		cout << "1. Next Iteration" << endl
			 << "2. Add Reservation" << endl
			 << "3. Cancel Reservation" << endl
			 << "4. Show Reservations" << endl
			 << "5. Show Rooms" << endl
			 << "6. Βooking Plan View" << endl
			 << "7. Revenue Projection" << endl
			 << "8. Exit" << endl << endl;

		Reservation* input = new Reservation;	
		cin >> j;	//input options
		cout << endl;
		string s; //input name
		int a;	  //input arrival
		int d;	  //input number of days
		int p;	  //input number of people
		char ch;  //input check for random reservation
		int i;	  //input id

		switch (j) {
		case 1:
			j = 0;
			break;
		case 2:
			cout << "Reservation name: " << endl;
			cin >> s;
			cout << "Day of arrival: " << endl;
			cin >> a;
			a -= 1;	 //to match availability
			cout << "Days of stay: " << endl;
			cin >> d;
			cout << "Number of people: " << endl;
			cin >> p;

			//Create reservation with
			input->setName(s);
			input->setArrival(a);
			input->setDays(d);
			input->setNumber(p);

			cout << "Do you want to book a specific room? (y/n)" << endl;
			cin >> ch;

			if (ch == 'y') {
				cout << "Give the id of the room:" << endl;
				cin >> i;
				Conte_Del_Mare.addReservationToRoom(input, i);
			}
			else {
				Conte_Del_Mare.HotelAddReservation(input);
			}

			break;
		case 3:
			cout << "Give the id of the arrival:" << endl;
			cin >> i;
			Conte_Del_Mare.HotelCancel(i);
			break;
		case 4:
			cout << setw(16) << left << "Arrival ID" << "| " << setw(15) << left << "Customer Name" << "| " << setw(4) << left << "ID" << endl;
			if (Conte_Del_Mare.sizeofbookings() >= 1) {
				Conte_Del_Mare.printResInfo();
			}
			break;
		case 5:
			cout << setw(16) << left << "Room ID" << "| " << setw(15) << left << "Fullness" << "| " << setw(6) << left << "Income" << endl;
			if (Conte_Del_Mare.sizeofrooms() >= 1) {
				Conte_Del_Mare.printRoomInfo();
			}
			break;
		case 6:
			Conte_Del_Mare.reservationPlan();
			break;
		case 7:
			cout << "Do you want to see the revenue of a specific room? (y/n)" << endl;
			cin >> ch;
			if(ch=='y'){
				cout << "Give the id of the room: " << endl;
				cin >> i;
				cout << "Room revenue with id" << i << " is: " << Conte_Del_Mare.IncomeCalculation(i) << endl;
			}
			else {								
				cout << "Τhe hotel revenue from all rooms is: " << Conte_Del_Mare.IncomeCalculation() << endl;
			}
			break;
		case 8:
			break;
		default:
			cout << "Give one of the 8 options." << endl;
		}

	} while (j != 8);
	return 0;
}
