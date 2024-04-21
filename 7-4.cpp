#include <iostream>
#include <cstdlib>
using namespace std;

class HotDogStand {
public:
	HotDogStand();
	HotDogStand(int ID, int sold);
	int getID();
	int getSold();
	static int getTotal();
	void setID(int ID);
	void setSold(int sold);
	void JustSold();

private:
	int ID;
	int sold;
	static int total;
};


int HotDogStand::total = 0;

//initialize ID and sold to 0
HotDogStand::HotDogStand() :ID(0), sold(0) {};

//initialize ID and sold
HotDogStand::HotDogStand(int ID, int sold) :ID(ID), sold(sold) {
	total += sold;
}

//Mutator of the ID
void HotDogStand::setID(int ID) {
	this->ID = ID;
}

//Mutator of the sold
void HotDogStand::setSold(int sold) {
	this->sold = sold;
}

//Accessor of the ID
int HotDogStand::getID() {
	return ID;
}

//Accessor of the sold
int HotDogStand::getSold() {
	return sold;
}

//Accessor of the total
int HotDogStand::getTotal() {
	return total;
}

//compute the number of sold and total sold
void HotDogStand::JustSold() {
	sold++;
	total++;
}



int main() {
	int num, ID, sold;
	HotDogStand h;
	bool add = true;
	cout << "Enter how many stands there are (at least 3) => ";
	cin >> num;
	cout << "\nEnter the ID for stand A => ";
	cin >> ID;
	cout << "Enter the hot dogs the stand sold => ";
	cin >> sold;
	HotDogStand standA(ID, sold);
	cout << "\nEnter the ID for stand B => ";
	cin >> ID;
	cout << "Enter the hot dogs the stand sold => ";
	cin >> sold;
	HotDogStand standB(ID, sold);
	cout << "\nEnter the ID for stand C => ";
	cin >> ID;
	cout << "Enter the hot dogs the stand sold => ";
	cin >> sold;
	HotDogStand standC(ID, sold);

	//Whether sold more hot dogs
	do {
		cout << "Do you sold more hot dogs? (yes enter 1, no enter 0) => ";
		cin >> add;
		if (add) {
			cout << "Which stand sold => ";
			cin >> ID;
			if (ID == standA.getID())
				standA.JustSold();
			else if (ID == standB.getID())
				standB.JustSold();
			else if(ID== standC.getID())
				standC.JustSold();
		}
	} while (add);
	cout << "\n-------------------------------------------------\n\n";
	cout << "Stand " << standA.getID() << " sold " << standA.getSold() << " hot dogs.\n";
	cout << "Stand " << standB.getID() << " sold " << standB.getSold() << " hot dogs.\n";
	cout << "Stand " << standC.getID() << " sold " << standC.getSold() << " hot dogs.\n";
	cout << "The total number of hot dogs sold by all hot dog stands are " << h.getTotal() << endl;
	system("pause");
	return 0;
}