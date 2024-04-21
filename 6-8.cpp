#include <iostream>
#include <cstdlib>
using namespace std;

class Money {
private:
    int dollars;
    int cents;
public:
    Money() {};
    void input();
    double monetary();
    void setDollars(int newdollars);
    int getDollars();
    void setCents(int newcents);
    int getCents();
};

//Mutator of dollars
void Money::setDollars(int newdollars) {
    dollars = newdollars;
}

//Accessor of dollars
int Money::getDollars() {
    return dollars;
}

//Mutator of cents
void Money::setCents(int newcents) {
    cents = newcents;
}

//Accessor of cents
int Money::getCents() {
    return cents;
}

//input function
void Money::input() {
    do {
        cout << "Enter how many dollars => ";
        cin >> dollars;
        setDollars(dollars);
    } while (dollars < 0);
    do {
        cout << "Enter how many cents => ";
        cin >> cents;
        setCents(cents);
    } while (cents < 0);

}

//compute the monetary amount
double Money::monetary() {
    double money;

    //dallars=cents*0.01
    money = getDollars() + getCents() * 0.01;
    return money;
}

int main() {
    Money money;
    money.input();
    cout << "Your monetary is $" << money.monetary() << endl;
    system("pause");
    return 0;
}
