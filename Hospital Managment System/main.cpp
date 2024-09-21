#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

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
	string username;
	string password;

public:
	User():
		username("Username"), password("Password"){
	}

	User(string username, string password) :
		username(username), password(password) {
	}

	void setUsername(const string& username) {
		this->username = username;
	}

	void setPassword(const string& password) {
		this->password = password;
	}

	string getUsername() const {
		return username;
	}

	string getPassword() const {
		return password;
	}

	virtual bool userType() const{ // A function to tell if the
							 // The user is a patient '1'
							// or an admin '0'
		return false;
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

	bool userType() const override {
		return true;
	}
};

class Admin : public User {
private:
public:
	Admin(User user) : User(user) {}

	bool userType() const override {
		return false;
	}
};

class DataBase {
private:
	void loadToFile(const string& fileName, User* user) const{
		//To count number of rows
		//To make an ID for each user
		ifstream in(fileName);
		int row = 0;
		string temp;
		while (getline(in, temp))
			++row;
		temp.clear();


		// Id format : User type(A admin, P patient) + Row number
		ofstream file(fileName, ios::app);
		temp.push_back(user->userType() ? 'P' : 'A');
		temp.push_back(row + '0');

		file << temp << ',';
		file << user->getUsername() << ',';
		file << user->getPassword() << ',';
		file << user->userType() << ',';
		file << '\n';
		file.close();
	}

	bool userExists(const string& fileName,const string& username) const {
		ifstream file(fileName);


		return false;
	}

	void login() {
		cout << "***********************\n\n\Login\n\n***********************\n\n";
		string username;
		string password;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
	}

	void signUp() {
		cout << "***********************\n\n\tSign Up\n\n***********************\n\n";
		User user;
		string tempUsername;
		string tempPassword;
		string tempConfirmPassword;
	
		while (true) {
			cout << "Username: ";
			cin >> tempUsername;
			
			if (tempUsername.empty()) {
				cout << "Please enter another user name\n";
				continue;
			}

			user.setUsername(tempUsername);
			break;
		}

		while (true) {
			cout << "Password: ";
			cin >> tempPassword;

			cout << "Confirm Password: ";
			cin >> tempConfirmPassword;
			
			if (tempPassword != tempConfirmPassword) {
				cout << "Passwords don't match\n";
				continue;
			}

			if (tempPassword.size() < 8) {
				cout << "The password you've enterd is weak\n";
				continue;
			}
			user.setPassword(tempPassword);
			break;
		}

		User* user1;

		ifstream file("Data.txt");
		int row = 0;
		string temp;
		while (getline(file, temp))
			++row;

		//The user is an admin "Because it is the first user"
		if (row == 0)
			user1 = new Admin(user);

		//The user is a patient
		else
			user1 = new Patient(user);

		loadToFile("Data.csv", user1);

		delete user1;
	}
public:
	void mainInterface() {
		int type;
			cout << "Welcome to HMS\n\n"
				<< "1. Login\n"
				<< "2. Sign Up\n";
			cout << "Enter choice: ";
			cin >> type;
			
			while (type != 1 and type != 2) {
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
};

int main() {
	DataBase DB;
	DB.mainInterface();
}