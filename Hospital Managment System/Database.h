#ifndef DATABASE_H
#define DATABASE_H

#include"User.h"
#include<string>
#include<iostream>

using namespace std;

class Database {
private:
	int countRowsInFile(const string&) const;

	bool fileIsEmpty(const string&) const;

	void loadToFile(const string&, User*) const;

	bool userInfoChecking(const string&, const string&) const;

	bool userInfoChecking(const string&, const string&, const string&) const;

	void login();

	void signUp();

public:
	void mainInterface();
};

#endif