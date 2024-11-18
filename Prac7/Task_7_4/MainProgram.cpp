#include <iostream>
#include <fstream>
#include <string>
#include "addressBookType.h"

using namespace std;

int main() {
	addressBookType addressBook;
	addressBook.loadData();
	addressBook.print();
	addressBook.saveData();
	return 0;
}

