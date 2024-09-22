#include"User.h"
#include"Patient.h"

Patient::Patient(User user) : User(user) {}

void Patient::reserve(Reservation reservation) {
	reservations.push_back(reservation);
}

bool Patient::userType() const {
	return true;
}