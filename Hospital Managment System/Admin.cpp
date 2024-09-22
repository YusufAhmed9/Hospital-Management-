#include"User.h"
#include"Admin.h"

using namespace std;

Admin::Admin(User user) : User(user) {}

bool Admin::userType() const {
	return false;
}