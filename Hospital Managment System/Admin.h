#ifndef ADMIN_H
#define ADMIN_H

#include"User.h"

using namespace std;

class Admin : public User {
private:
public:
	Admin(User);

	bool userType() const override;
};
#endif