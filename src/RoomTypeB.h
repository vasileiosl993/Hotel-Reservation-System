#ifndef RoomTypeB
#define RoomTypeB_H

#include "RoomTypeA.h"
class RoomTypeB :
	public RoomTypeA
{
public:
	RoomTypeB();
	~RoomTypeB();

	//functions
	void setDiscountDay(double);

	//Methods
	bool cancel(int);
	double billing();


private:
	double discount_per_day_;
};
#endif