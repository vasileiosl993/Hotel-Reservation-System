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

#include "CharGenerator.h"	//Header gia tin cgener()


#define maxpeople 5		//Megalutero dwmatio se capacity.
#define maxdaysarr 30	//Megistos arithmos afiksis.
#define maxdaysstay 29	//Megistos arithmos paramonis.

using namespace std;


int main() 
{
	//---Rooms---
	
	//1.			//Dhmiourgia dwmatiwn.
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

	Hotel Conte_Del_Mare;		//Prosthiki dwmatiwn sto ksenodoxeio.

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
	int k;	//voithitikos gia tis epanalipseis

	do {
		if (j == 0) {
			string s1 = cgener(rand() % 12 + 3);
			Reservation* res_pointer = new Reservation();	//Dhmiourgia krathshs me tuxaio onoma.
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
		cout << "Ti thelete na kanete: " << endl << endl;
		cout << "1. Epomeni epanalipsi" << endl
			 << "2. Prosthiki krathshs" << endl
			 << "3. Akurwsh krathshs" << endl
			 << "4. Provolh krathsewn" << endl
			 << "5. Provolh dwmatiwn" << endl
			 << "6. Provolh planou krathsewn" << endl
			 << "7. Provolh esodwn" << endl
			 << "8. Termatismos" << endl << endl;

		Reservation* input = new Reservation;	//Dhmiourgia reservation* gia input
		cin >> j;	//input options
		cout << endl;
		string s;	//input name
		int a;	//input arrival
		int d;	//input number of days
		int p;	//input number of people
		char ch;	//input check for random reservation
		int i;	//input id

		switch (j) {
		case 1:
			j = 0;
			break;
		case 2:
			cout << "Dwse to onoma ths krathshs: " << endl;
			cin >> s;
			cout << "Dwse tin hmera afikshs:" << endl;
			cin >> a;
			a -= 1;	//gia na tairiazei ston availability
			cout << "Dwse tis hmeres diamonhs:" << endl;
			cin >> d;
			cout << "Dwse ton arithmo twn atomwn:" << endl;
			cin >> p;

			//Dhmiourgia krathshs me inputs
			input->setName(s);
			input->setArrival(a);
			input->setDays(d);
			input->setNumber(p);

			cout << "Theleis na kaneis krathsh se sugkekrimeno dwmatio? (y/n)" << endl;
			cin >> ch;

			if (ch == 'y') {
				cout << "Dwse to id tou dwmatiou:" << endl;
				cin >> i;
				Conte_Del_Mare.addReservationToRoom(input, i);
			}
			else {
				Conte_Del_Mare.HotelAddReservation(input);
			}

			break;
		case 3:
			cout << "Dwse to id ths krathshs:" << endl;
			cin >> i;
			Conte_Del_Mare.HotelCancel(i);
			break;
		case 4:
			cout << setw(16) << left << "Kwdikos Krathshs" << "| " << setw(15) << left << "Onoma Pelath" << "| " << setw(4) << left << "ID" << endl;
			if (Conte_Del_Mare.sizeofbookings() >= 1) {
				Conte_Del_Mare.printResInfo();
			}
			break;
		case 5:
			cout << setw(16) << left << "Kwdikos Dwmatiou" << "| " << setw(15) << left << "Plhrothta" << "| " << setw(6) << left << "Esoda" << endl;
			if (Conte_Del_Mare.sizeofrooms() >= 1) {
				Conte_Del_Mare.printRoomInfo();
			}
			break;
		case 6:
			Conte_Del_Mare.reservationPlan();
			break;
		case 7:
			cout << "Theleis na deis ta esoda sugkekrimenou dwmatiou? (y/n)" << endl;
			cin >> ch;
			if(ch=='y'){
				cout << "Dwse to id tou dwmatiou: " << endl;
				cin >> i;
				cout << "Ta esoda tou dwmatiou me id " << i << " einai: " << Conte_Del_Mare.IncomeCalculation(i) << endl;
			}
			else {								
				cout << "Ta esoda tou ksenodoxeiou apo ola ta dwmatia einai: " << Conte_Del_Mare.IncomeCalculation() << endl;
			}
			break;
		case 8:
			break;
		default:
			cout << "Dwse mia apo tis 8 epiloges." << endl;
		}

	} while (j != 8);
	return 0;
}