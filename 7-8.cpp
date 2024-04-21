#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	vector <int> grade;
	int histogram[101];
	int score;
	int max = 0;

	//initialize the histogram array
	for (int i = 0; i < 101; i++)
		histogram[i] = 0;
	do {
		cout << "Enter the grade and enter -1 to stop  => ";
		cin >> score;

		//add the score to the grade vector
		grade.push_back(score);
		if (grade.back() == -1)
			break;
		histogram[grade.back()]++;

		//search the max score
		if (grade.back() > max)
			max = grade.back();
	} while (grade.back() != -1);

	//print the histogram of the grade
	for (int i = 0; i < max; i++) {
		if (histogram[i] > 0) {
			cout << histogram[i] << " grade(s) of " << i << endl;
		}
	}
	system("pause");
	return 0;
}