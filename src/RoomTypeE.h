#ifndef RoomTypeE
#define RoomTypeE_H

#include "Room.h"
class RoomTypeE :
	public Room
{
public:
	RoomTypeE();
	~RoomTypeE();

	//Methods
	bool cancel(int);

private:
	int people_;
};

#endif