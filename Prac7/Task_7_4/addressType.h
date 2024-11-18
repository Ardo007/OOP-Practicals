
#ifndef H_addressType
#define H_addressType

#include <string>
  
using namespace std;

class addressType
{
public:
    addressType(string sAddress = "", string c = "", string s = "", string z = "");

    void setAddress(string sAddress, string c, string s, string z);

    void getDetails(string& sAddress, string& c, string& s, string& z);

    void print() const;

private:
    string streetAddress;
    string city;
    string state;
    string zip;
};

void addressType::print() const
{
    cout << streetAddress;
    cout << city << ", " << state << ", " << zip << endl;
}

void addressType::setAddress(string sAddress, string c, string s, string z)
{
    streetAddress = sAddress;
    city = c;
    state = s;
    zip = z;
}


void addressType::getDetails(string& sAddress, string& c, string& s, string& z)
{
    sAddress = streetAddress ;
    c = city;
    s = state;
    z = zip;
}

addressType::addressType(string sAddress, string c, string s, string z)
{
    streetAddress = sAddress;
    city = c;
    state = s;
    zip = z;
}

#endif
