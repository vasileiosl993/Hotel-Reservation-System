#include "stdafx.h"
#include "RoomTypeB.h"
#include "Reservation.h"
#include <iostream>

using namespace std;

RoomTypeB::RoomTypeB()
{
}


RoomTypeB::~RoomTypeB()
{
}

//function
void RoomTypeB::setDiscountDay(double d) {
	discount_per_day_ = d;
}

//Methods
bool RoomTypeB::cancel(int i) {
	cout << "Can't cancel, false" << endl;
	return false;
}

double RoomTypeB::billing() {
	int r = 1;
	double price_per_day_ = getPriceDay();
	double totalcost = 0;
	double discount_check = price_per_day_;
	double halfprice = price_per_day_*0.5;
	for (int j = 0; j < 30; j += r) {
		r = 1;
		if (availability_[j] != nullptr) {
			double total = 0;
			for (int i = j + 1; i < 30; i++) {
				if (availability_[i] != nullptr && availability_[j]->getID() == availability_[i]->getID()) {
					r++;
					if (discount_check >= halfprice) {
						total += (price_per_day_ - (i - j)*discount_per_day_);
						discount_check = total;
					}
					else {
						total = discount_check;
					}
				}
				else {
					break;
				}
			}
			totalcost += price_per_day_ + total;
		}
	}
	return totalcost;
}