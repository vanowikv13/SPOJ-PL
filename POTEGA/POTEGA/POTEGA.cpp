#include "stdafx.h" ///only for VS
#include <string>
#include <iostream>

using namespace std;

//add two number in string type (for really big number) // function return reference to first argument because in this will be sum
string add(string, string);

//function add nuber one in fron of number until there will not be sum 10
int addForward(string&, int);

//x to pow y
string pow(string, int);

string multiplication(string, int);

//later make it as operator++ in class
char addOneToThisNumber(char &value);

//pow big number
void pow_big();

int main()
{
	//start program
	pow_big();

	///delete while sending
	cin.get();
    return 0;
}

//realize better this function
int addForward(string& value, int i) {
	do {
		if (i == 0) {
			if (value[i] == '9') {
				value[i] = '0';
				value = "1" + value;
				return 1;
			}
			else
				addOneToThisNumber(value[i]);
		}
		else if (value[i] != '9')
			addOneToThisNumber(value[i]);
		else
			value[i] = '0';
		i--;
	} while (i >= 0 && value[i] == '9');
	
	return 0;
}

string add(string first, string second) {

	//checking which number is bigger with number of digits
	string sum = (first.size() > second.size()) ? first : second, &y = (sum == first) ? second : first;

	for (int i = y.size() - 1, j = sum.size() -1; i >= 0; i--, j--) {
		//conversion char to int
		string sum_digits = to_string(static_cast<int>(sum[j] - '0') + static_cast<int>(y[i] - '0'));

		//this is when we will send one to the front
		if (sum_digits.size() == 2) {
			//second value always is going for place previvious one
			sum[j] = sum_digits[1];

			//index of the sum number is euqul to zero than it's should be just normal operation
			if (j == 0)
				sum = "1" + sum;
			else
				j+= addForward(sum, j - 1);
		}
		else
			sum[j] = sum_digits[0];
	}

	return sum;
}

string multiplication(string x, int y) {
	string sum = x; 
	for (int i = 1; i < y; i++)
		sum = add(sum, x);
	return sum;
}

string pow(string x, int y) {

}

char addOneToThisNumber(char &value)
{
	value = static_cast<char>((static_cast<int>(value - '0') + 1)) + '0';
	return value;
}

//main function working program
void pow_big()
{
	
	string x; unsigned int y;
	while (cin >> x >> y)
		cout << pow(x, y) << endl;
	
	///tests
	string z, t;
	while (cin >> z >> t)
		cout << add(z, t) << endl;
		
}
