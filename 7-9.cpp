#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

class ZipCode {
public:
	ZipCode() {};
	ZipCode(int inp);
	ZipCode(string inp);
	int BarToZip(string inp);
	string ZipToBar(int inp);
private:
	int zip;
	string bar;
	string ZipConvertBar(int inp[5]);
};

//change zip code to bar code
string ZipCode::ZipToBar(int inp) {
	int zip[5];

	//seperate zip code to five part
	for (int i = 4; i >= 0; i--) {
		zip[i] = inp % 10;
		inp /= 10;
	}
	return ZipConvertBar(zip);
}

/*change zip code to bar code.
* 0 -> 11000
* 1 -> 00011
* 2 -> 00101
* 3 -> 00110
* 4 -> 01001
* 5 -> 01010
* 6 -> 01100
* 7 -> 10001
* 8 -> 10010
* 9 -> 10100
*/
string ZipCode::ZipConvertBar(int inp[5]) {
	for (int i = 0; i < 5; i++) {
		switch (inp[i])
		{
		case 0:
			bar.append("11000", 0, 5);
			break;
		case 1:
			bar.append("00011", 0, 5);
			break;
		case 2:
			bar.append("00101", 0, 5);
			break;
		case 3:
			bar.append("00110", 0, 5);
			break;
		case 4:
			bar.append("01001", 0, 5);
			break;
		case 5:
			bar.append("01010", 0, 5);
			break;
		case 6:
			bar.append("01100", 0, 5);
			break;
		case 7:
			bar.append("10001", 0, 5);
			break;
		case 8:
			bar.append("10010", 0, 5);

			break;
		case 9:
			bar.append("10100", 0, 5);
			break;
		default:
			break;
		}
	}
	return bar;
}

//change bar code to zip code
int ZipCode::BarToZip(string inp) {
	zip = 0;
	int digit;

	//first digit*7 + second digit*4 + third digit*2 + fourth digit*1 + fifth digit*0
	for (int i = 0; i < 5; i++) {
		digit = (inp[i * 5 + 0] - '0') * 7 + (inp[i * 5 + 1] - '0') * 4 + (inp[i * 5 + 2] - '0') * 2 + (inp[i * 5 + 3] - '0') * 1;
		zip *= 10;
		if (digit < 10) 
			zip += digit;
	}
	return zip;
}


int main() {
	int zip;
	string bar;
	char inp;
	ZipCode zipcode;
	cout << "Which code do you want to input (zipcode(z) or barcode(b)) => ";
	cin >> inp;
	if (inp == 'z') {
		cout << "Enter a zip code (ex: 99504)=> ";
		cin >> zip;
		cout << zipcode.ZipToBar(zip) << endl;
	}
	else if (inp == 'b') {
		cout << "Enter a bar code (ex:1010010100010101100001001) => ";
		cin >> bar;
		cout << zipcode.BarToZip(bar) << endl;
	}
	system("pause");
	return 0;
}