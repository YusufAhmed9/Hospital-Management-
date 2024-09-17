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
	Patient(User user) : User(user) {}

	void reserve(Reservation reservation) {
		reservations.push_back(reservation);
	}
};

class Admin : public User {
private:

};

class DataBase {
public:
	void mainInterface() {
		int type;
			cout << "Welcome to HMS\n\n"
				<< "1. Login\n"
				<< "2. Sign Up\n";
			
			cin >> type;
			
			while (type <= 0 or type > 2) {
				cout << "Error: please enter a valid option\n";
				cout << "Welcome to HMS\n"
					<< "1. Login\n"
					<< "2. Sign Up\n";
				cin >> type;
			}

			if (type == 1)
				login();
			else
				signUp();
	}
	void login() {

	}

	void signUp() {
		int userType;
		User user;
		string tempUsername;
		string tempPassword;
		string tempConfirmPassword;
		string tempUserID;
	
		cout << "Username: ";
		cin >> tempUsername;

		cout << "Password: ";
		cin >> tempPassword;
		cout << "Confirm Password: ";
		cin >> tempConfirmPassword;

		cout << "User ID: ";
		cin >> tempUserID;

		cout << "User type (1. Patient/ 2. Admin): ";
		cin >> userType;

		if (tempPassword != tempConfirmPassword) {
			cout << "Passwords don't match\n";
			signUp();
		}
		user.setUsername(tempUsername);
		user.setPassword(tempPassword);
		user.setUserID(tempUserID);
	}
};

int main() {
}