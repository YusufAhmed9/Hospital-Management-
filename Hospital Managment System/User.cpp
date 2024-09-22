#include<string>
#include"User.h"

using namespace std;

User::User() :
	username("Username"), password("Password") {
}

User::User(const string& username, const string& password) :
	username(username), password(password) {
}

void User::setUsername(const string& username) {
	this->username = username;
}

void User::setPassword(const string& password) {
	this->password = password;
}

string User::getUsername() const {
	return username;
}

string User::getPassword() const {
	return password;
}
bool User::userType() const {
	return false;
}