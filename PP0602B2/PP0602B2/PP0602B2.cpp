#include "stdafx.h" ///to coment
#include <iostream>

using namespace std;

//main function to slove problem
void moveElements(int **, int, int);

//use latter to don't make to much work on data
void write(int **, int, int);

//swap elements in array
inline void swap(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}

int main()
{
	int t, l, k, x;
	int **arr = nullptr;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		//number of rows, number of columns
		cin >> l >> k;
		//array of pointer to array
		arr = new int *[l];

		//initialize array
		for (size_t j = 0; j < l; j++)
			arr[j] = new int[k];

		//initialize array with values
		for (size_t j = 0; j < l; j++)
		{
			for (size_t it = 0;  it < k;  it++)
			{
				cin >> x;
				arr[j][it] = x;
			}
		}

		moveElements(arr, l, k);
		write(arr, l, k);
		delete arr;
	}
	system("pause"); ///to coment
    return 0;
}

void write(int **arr, int l, int k) {
	for (size_t j = 0; j < l; j++)
	{
		for (size_t it = 0; it < k; it++)
		{
			cout << arr[j][it] << " ";
		}
		cout << endl;
	}
}

//for now here we have to much code but later I will simplify it
void moveElements(int ** arr, int maxX, int maxY) {
	//reprezentation of to wchich direction will go our function
	enum class direction {UP, DOWN} status = direction::DOWN;

	//lambda changing direction
	auto changeDirection = [](direction &obj, int x) {obj = (x%2 == 1) ? direction::UP : direction::DOWN;};
	
	int bufor = arr[0][0];
	int i = 1, j = 0;
	
	while (true)
	{
		//swap element in array
		swap(arr[i][j], bufor);
		
		//IF it have to turn right or not
		if (i == maxX - 1 || i == 0)
		{
			if (j < maxY - 1 && i != 0) {
				j++;
				changeDirection(status, j);
			}
			else if (j == maxY - 1){
				if((j%2 == 0 && i == maxX - 1) || (j%2 == 1 && i == 0))...
				swap(arr[i][j], bufor);
				arr[0][0] = bufor;
				return;
			}
		}
		else {
			if (status == direction::DOWN)
				i++;
			else i--;
		}
	}
}