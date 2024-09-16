#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Reservation {

};
class User {
private:
	string userID;
	string username;
	string password;
};
class Patient : public User {
private:
	vector< Reservation>reservations;
};
int main() {
}