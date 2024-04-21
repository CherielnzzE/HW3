#include <iostream>
#include <cstdlib>
using namespace std;

class Weight {
private:
    double pounds;
    double kilograms;
    double ounces;
public:
    Weight() {};
    void setWeightPounds(double newpounds);
    double getWeightPounds();
    void setWeightKilograms(double newkilograms);
    double getWeightKilorams();
    void setWeightOunces(double newounces);
    double getWeightOnunces();
};


//Mutator of pounds
void Weight::setWeightPounds(double newpounds) {
    pounds = newpounds;
}

//Accessor of pounds
double Weight::getWeightPounds() {
    return pounds;
}

//Mutator of kilograms
void Weight::setWeightKilograms(double newkilograms) {
    kilograms = newkilograms;
}

//Accessor of kilograms
double Weight::getWeightKilorams() {
    return kilograms;
}

//Mutator of ounce
void Weight::setWeightOunces(double newounces) {
    ounces = newounces;
}

//Accessor of ounce
double Weight::getWeightOnunces() {
    return ounces;
}

int main(void) {
    Weight weight;
    double weights;
    char input;
    char output;

    do {
        cout << "Choose which unit you want to input (Pounds (p) or Kilograms (k) or Ounce (o)) => ";
        cin >> input;
    } while (input != 'p' && input != 'k' && input != 'o');

    do {
        cout << "Choose which unit you want to output (Pounds (p) or Kilograms (k) or Ounce (o)) => ";
        cin >> output;
    } while (output != 'p' && output != 'k' && output != 'o');

    do {
        cout << "Enter the weight => ";
        cin >> weights;

    } while (weights < 0);

    /* 1 pound = 16 ounces
       1 kilogram = 2.21 pounds
    */
    if (input == 'p') {
        weight.setWeightPounds(weights);
        cout << weight.getWeightPounds() << " Pounds = ";
        if (output == 'p')
            cout << weight.getWeightPounds() << " Pounds\n";
        else if (output == 'k')
            cout << weight.getWeightPounds() / 2.21 << " Kilograms\n";
        else
            cout << weight.getWeightPounds() * 16 << " Ounces\n";
    }
    else if (input == 'k') {
        weight.setWeightKilograms(weights);
        cout << weight.getWeightKilorams() << " Kilograms = ";
        if (output == 'p')
            cout << weight.getWeightKilorams() * 2.21 << " Pounds\n";
        else if (output == 'k')
            cout << weight.getWeightKilorams() << " Kilograms\n";
        else
            cout << weight.getWeightKilorams() * 16 * 2.21 << " Ounces\n";
    }
    else {
        weight.setWeightOunces(weights);
        cout << weight.getWeightOnunces() << " Kilograms = ";
        if (output == 'p')
            cout << weight.getWeightOnunces() / 16 << " Pounds\n";
        else if (output == 'k')
            cout << weight.getWeightOnunces() / 16 / 2.21 << " Kilograms\n";
        else
            cout << weight.getWeightOnunces() << " Ounces\n";
    }


    system("pause");
    return 0;
}
