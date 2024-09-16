#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Date {


};

class Reservation {
private:
	string reservationID;
	string hospitalID;
	string reservationType;
	Date reservationDay;

};

class User {
private:
	string userID;
	string username;
	string password;
public:
	User() : 
		userID("User ID"), username("Username"), password("Password") {}

	User(string userID, string username, string password) :
		userID(userID), username(username), password(password){}

	void setUsername(string username) {
		this->username = username;
	}

	void setUserID(string userID) {
		this->userID = userID;
	}

	void setPassword(string password) {
		this->password = password;
	}

	string getUsername() {
		return username;
	}

	string getUserID() const {
		return userID;
	}

	string getPassword() const {
		return password;
	}
};

class Patient : public User {
private:
	vector<Reservation>reservations;
public:
	void reserve(Reservation reservation) {
		reservations.push_back(reservation);
	}
};

class Admin : public User {
private:

};

int main() {
}