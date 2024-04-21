#include <iostream>
#include <cstdlib>
using namespace std;

class Pizza {
private:
    char type;
    char size;
    int pepperoni;
    int cheese;
public:
    Pizza() {};
    void setType(char newtype);
    char getType();
    void setSize(char newsize);
    char getSize();
    void setPepperoni(int newpepperoni);
    int getPepperoni();
    void setCheese(int newcheese);
    int getCheese();
    void outputDescription();
    int computePrice();

};

//Mutator of type
void Pizza::setType(char newtype) {
    type = newtype;
}

//Accessor of type
char Pizza::getType() {
    return type;
}

//Mutator of size
void Pizza::setSize(char newsize) {
    size = newsize;
}

//Accessor of size
char Pizza::getSize() {
    return size;
}

//Mutator of pepperoni
void Pizza::setPepperoni(int newpepperoni) {
    pepperoni = newpepperoni;
}

//Accessor of pepperoni
int Pizza::getPepperoni() {
    return pepperoni;
}

//Mutator of cheese
void Pizza::setCheese(int newcheese) {
    cheese = newcheese;
}

//Accessor of cheese
int Pizza::getCheese() {
    return cheese;
}


//output the textual description of the pizza
void Pizza::outputDescription() {
    cout << "Type: ";
    if (getType() == 'd')
        cout << "deep fish\n";
    else if (getType() == 'h')
        cout << "hand tossed\n";
    else
        cout << "pan\n";
    cout << "Size: ";
    if (getSize() == 's')
        cout << "small\n";
    else if (getSize() == 'm')
        cout << "medium\n";
    else
        cout << "large\n";
    cout << "Number of pepperoni: " << getPepperoni() << "\nNumber of cheese topping: " << getCheese() << endl;
}


//compute the prize of the pizza
int Pizza::computePrice() {
    int price;

    /*Small=$10
      Medium=$14
      Large=$17
    */
    if (getSize() == 's')
        price = 10;
    else if (getSize() == 'm')
        price = 14;
    else
        price = 17;

    //$2 per topping
    price += (getPepperoni() + getCheese()) * 2;
    return price;
}

int main() {
    Pizza pizza;
    char type;
    char size;
    int pepperoni;
    int cheese;
    do {
        cout << "Choose the type of pizza (deep dish (d) or hand tossed (h) or pan (p)) => ";
        cin >> type;
        pizza.setType(type);

    } while (pizza.getType() != 'd' && pizza.getType() != 'h' && pizza.getType() != 'p');
    do {
        cout << "Choose the size of pizza (small (s) or medium (m) or large (l)) => ";
        cin >> size;
        pizza.setSize(size);

    } while (pizza.getSize() != 's' && pizza.getSize() != 'm' && pizza.getSize() != 'l');
    do {
        cout << "Choose how many pepperoni you want to put => ";
        cin >> pepperoni;
        pizza.setPepperoni(pepperoni);

    } while (pizza.getPepperoni() < 0);
    do {
        cout << "Choose how many cheese topping you want to put => ";
        cin >> cheese;
        pizza.setCheese(cheese);

    } while (pizza.getCheese() < 0);
    pizza.outputDescription();
    cout << "Your price is: $" << pizza.computePrice() << endl;
    system("pause");
    return 0;
}
