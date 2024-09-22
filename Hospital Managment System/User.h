#ifndef USER_H
#define USER_H
#include<string>

using namespace std;

class User {
private:
	string username;
	string password;

public:
	User();

	User(const string&, const string&);

	void setUsername(const string&);

	void setPassword(const string&);

	string getUsername() const;

	string getPassword() const;

	virtual bool userType() const;
	
};
#endif