//extPersonType.

#ifndef H_extPersonType
#define H_extPersonType

#include <string>
#include "addressType.h"
#include "dateType.h"
#include "personType.h"

class extPersonType: public personType {
public:

	void printInfo() const;

	addressType getAddress();

	string getStatus() const;
	string getPhoneNumber() const;

	dateType getDOB();

	extPersonType(string fName = "", string lName = "", int day = 1, int month = 1, 
			int year = 2000, string street = "", string c = "",
			string s = "", string z = "", string phone = "",
			string pStatus = "");

private:
	addressType address;
	dateType dob;
	string phoneNumber;
	string personStatus;
};

void extPersonType::printInfo() const {
	cout << "Name: ";
	personType::print();
	cout << endl;

	cout << "Date of Birth: ";
	dob.printDate();
	cout << endl;

	cout << "Phone Number: " << phoneNumber << endl;
	cout << "Person Type: " << personStatus << endl;

	cout << "Address: " << endl;
	address.print();
	cout << endl;
}

addressType extPersonType::getAddress() {
	return address;
}

string extPersonType::getPhoneNumber() const {
	return phoneNumber;
}

string extPersonType::getStatus() const {
	return personStatus;
}

dateType extPersonType::getDOB() {
	return dob;
}

extPersonType::extPersonType(string fName, string lName, int day, int month,
		int year, string street, string c, string s, string z, string phone,
		string pStatus) {
	personType::setName(fName, lName);
	dob.setDate(day, month, year);
	address.setAddress(street, c, s, z);
	phoneNumber = phone;
	personStatus = pStatus;
}

#endif