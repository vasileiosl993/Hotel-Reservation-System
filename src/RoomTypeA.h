#pragma once

#ifndef RoomTypeA
#define RoomTypeA_H

#include "Room.h"

class RoomTypeA :
	public Room
{
public:
	RoomTypeA();
	~RoomTypeA();
	
	double getPriceDay();
	void setPrice(double);

	//Methods
	virtual double billing();

private:
	double price_per_day_;
};
#endif