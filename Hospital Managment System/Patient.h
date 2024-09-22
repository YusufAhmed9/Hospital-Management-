#ifndef PATIENT_H
#define PATIENT_H

#include"User.h"
#include<vector>
#include "Reservation.h"

using namespace std;

class Patient : public User {
private:
	vector<Reservation>reservations;
public:
	Patient(User user);

	void reserve(Reservation reservation);

	bool userType() const override;
};
#endif