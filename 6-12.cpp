#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

class BoxOfProduce {
private:
    string product[5];
    string pickproduct[3];
public:
    BoxOfProduce() {};
    void output();
    void setPickproduct(string newpickproduct, int index);
    string getPickproduct(int index);
    void setProduct(string newproduct, int index);
    string getProduct(int index);
    void swap(int choose, int substition);

};

//Mutator of the prudoct you pick
void BoxOfProduce::setPickproduct(string newpickproduct, int index) {
    pickproduct[index] = newpickproduct;
}

//Accessor of the product you pick
string BoxOfProduce::getPickproduct(int index) {
    return pickproduct[index];
}

//Mutator of the prudoct
void BoxOfProduce::setProduct(string newproduct, int index) {
    product[index] = newproduct;
}

//Accessor of the product
string BoxOfProduce::getProduct(int index) {
    return product[index];
}

//output the list of the product you pick
void BoxOfProduce::output() {
    cout << "\nThe contents of the box is: \n";
    for (int i = 0; i < 3; i++)
        cout << i + 1 << " " << pickproduct[i] << endl;
}

//change the product
void BoxOfProduce::swap(int choose, int substition) {
    pickproduct[choose - 1] = product[substition - 1];
}


int main(void) {
    srand(time(NULL));
    BoxOfProduce box;
    string product[5];
    int random;
    int choose, substition;

    //open the file
    fstream file;
    file.open("input.txt", ios::in);

    //read the file and store in the array
    cout << "All item: \n";
    for (int i = 0; i < 5; i++) {
        file >> product[i];
        box.setProduct(product[i], i);
        cout << i + 1 << " " << product[i] << endl;
    }

    //randomly select the product
    for (int i = 0; i < 3; i++) {
        random = rand() % 5;
        box.setPickproduct(product[random], i);
    }

    box.output();


    //choose which product want to change
    do {
        cout << "Choose the index of product you want to change (1~3)(enter -1 to stop) => ";
        cin >> choose;

        //choose which product want to add
        if (choose != -1) {
            cout << "Enter the index of the product you want to add (1~5) => ";
            cin >> substition;
            box.swap(choose, substition);
            box.output();
        }
    } while (choose != -1);

    box.output();

    file.close();
    system("pause");
    return 0;
}
