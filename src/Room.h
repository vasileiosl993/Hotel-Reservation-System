#ifndef Room_H
#define Room_H

class Reservation;
using namespace std;

class Room
{
public:
	Room();
	~Room();

	//functions
	void setCapacity(int);
	virtual void setPrice(double);

	int getID();
	int getCapacity();
	double getPrice();
	Reservation* getAvail(int);

	//Member methods
	virtual bool addReservation(Reservation*);
	virtual double billing();
	virtual bool cancel(int);
	float occupancy();

private:
	static int id_;
	unsigned int room_id_;
	int capacity_;
	double price_per_person_;
	
protected:
	Reservation* availability_[30];

};
#endif