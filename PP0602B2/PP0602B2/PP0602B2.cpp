#include "stdafx.h" ///to comment
#include <iostream>

using namespace std;

//main function to slove problem
void moveElements(int **, int, int);

//use latter to don't make to much work on data
void output(int **, int, int);

//input data to our system
void input(int **, int, int);

//swap elements in array
inline void swap(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}

int main()
{
	int t, l, k;
	int **arr = nullptr;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		//number of rows, number of columns
		cin >> l >> k;
		//create new array
		arr = new int *[l];

		//initialize array
		for (size_t j = 0; j < l; j++)
			arr[j] = new int[k];

		input(arr, l, k);
		moveElements(arr, l, k);
		output(arr, l, k);
		delete arr;
	}
	system("pause"); ///to comment
    return 0;
}

void input(int **arr, int l, int k) {
	int x; 
	for (size_t j = 0; j < l; j++)
	{
		for (size_t it = 0; it < k; it++)
		{
			cin >> x;
			arr[j][it] = x;
		}
	}
}

void output(int **arr, int l, int k) {
	for (size_t j = 0; j < l; j++)
	{
		for (size_t it = 0; it < k; it++)
			cout << arr[j][it] << " ";
		cout << endl;
	}
}

void moveElements(int ** arr, int maxX, int maxY) {
	enum class direction {UP, DOWN} status = direction::DOWN;

	//lambda changing direction
	auto changeDirection = [](direction &obj, int x) {obj = (x%2 == 1) ? direction::UP : direction::DOWN;};

	int bufor = arr[0][0];
	int i = 1, j = 0;

	//interation of our index dependent of direction
	auto interate = [&]() {if (status == direction::DOWN) i++; else i--; };
	
	while (true)
	{
		swap(arr[i][j], bufor);
		
		//If it have to turn right or not
		if ((i == maxX - 1 && status == direction::DOWN) || (i == 0 && status == direction::UP)) //max border of i
		{
			//when it's is not in the last column
			if (j < maxY - 1) {
				//moving one column forward
				j++;
				//change direction
				changeDirection(status, j);
			}
			else if (j == maxY - 1 && (j % 2 == 1 && i == 0) || (j % 2 == 0 && i == maxX - 1)){ //here it means that we are in last column
				//move the last elements to first place
				arr[0][0] = bufor;
				//end of funciton
				return;
				
			}
			else
				interate();
		}
		else
			interate();
	}
}
