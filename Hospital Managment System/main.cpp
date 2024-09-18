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
	int userID;
	string username;
	string password;

public:
	static int IDGenerator;
	User() {

	}

	User(string username, string password) :
		username(username), password(password) {
		userID = IDGenerator++;
	}

	bool setUsername(const string& username) {
		if (username.empty())
			return 0;
		this->username = username;
		return 1;
	}

	bool setPassword(const string& password) {
		if (password.size() < 8)
			return 0;
		this->password = password;
		return 1;
	}

	string getUsername() const {
		return username;
	}

	string getPassword() const {
		return password;
	}
};
int User::IDGenerator = 0;

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
		cout << "***********************\n\n\tSign Up\n\n***********************\n\n";
		int userType;
		User user;
		string tempUsername;
		string tempPassword;
		string tempConfirmPassword;
	
		while (true) {
			cout << "Username: ";
			cin >> tempUsername;
			
			//If the enterd username is empty it returns 0
			if (!user.setUsername(tempUsername)) {
				cout << "Please enter another user name\n";
				continue;
			}
			break;
		}

		while (true) {
			cout << "Password: ";
			cin >> tempPassword;
			cout << "Confirm Password: ";
			cin >> tempConfirmPassword;
			
			//Checking if the entered passwords are equal
			if (tempPassword != tempConfirmPassword) {
				cout << "Passwords don't match\n";
				continue;
			}
			//If the password is weak the condition returns 0
			if (!user.setPassword(tempPassword)) {
				cout << "The password you've enterd is weak\n";
				continue;
			}
			break;
		}

		while (true) {
			cout << "User type (1. Patient/ 2. Admin): ";
			cin >> userType;
			
			if (userType != 1 and userType != 2) {
				cout << "Please enter a valid user type\n";
				continue;
			}
			break;
		}
		//The user is a patient
		if (userType == 1)
			Patient p1(user);
		
		//The user is an admin
		else;
	}
};

int main() {
}