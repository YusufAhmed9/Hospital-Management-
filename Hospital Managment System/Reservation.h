#ifndef RESERVATION_H
#define RESERVATION_H

#include<string>
#include "Date.h"

using namespace std;

class Reservation {
private:
	string reservationID;
	string hospitalID;
	string reservationType;
	Date reservationDay;
};
#endif // !RESERVATION_H
