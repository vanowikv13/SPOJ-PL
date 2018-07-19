#include "stdafx.h"
#include <iostream>
using namespace std;

unsigned long long int typedef big;

big powerMod(big b, big e, big m) {
	big x = 1;

	while (e > 0) {
		if (e % 2 == 1) {
			x = (b*x) % m;
			e = e - 1;
		}
		else {
			b = (b * b) % m;
			e = e / 2;
		}

	}
	return x;
}

int main() {

	int numberOfCases;
	cin >> numberOfCases;
	big numbers[3];
	for (size_t j = 0; j < numberOfCases; j++)
	{
		for (size_t i = 0; i < 3; i++)
		{
			cin >> numbers[i];
		}
		cout << powerMod(numbers[0], numbers[1], numbers[2]) << endl;
	}
	return 0;
}