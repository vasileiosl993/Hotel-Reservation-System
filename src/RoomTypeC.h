#ifndef RoomTypeC
#define RoomTypeC_H

#include "Room.h"
class RoomTypeC :
	public Room
{
public:
	RoomTypeC();
	~RoomTypeC();

	//functions
	void setMinPeople(int);
	void setMinDays(int);

	//Methods
	bool addReservation(Reservation&);


private:
	int min_people_;
	int min_days_;
};
#endif
