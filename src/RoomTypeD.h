#ifndef RoomTypeD
#define RoomTypeD_H

#include "Room.h"


class RoomTypeD:
	public Room
{
public:
	RoomTypeD();
	~RoomTypeD();

	//Methods
	void setPrice(double);
	double billing();

private:
	double price_per_person_;
};

#endif