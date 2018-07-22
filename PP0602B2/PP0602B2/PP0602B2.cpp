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
		if (i == maxX - 1 && status == direction::DOWN || i == 0 && status == direction::UP) //max border of i
		{
			//when it's is not in the last column
			if (j < maxY - 1) {
				//moving one column forward
				j++;
				//change direction
				changeDirection(status, j);
			}
			else if (j == maxY - 1){ //here it means that we are in last column
				//check if we are in the last member
				if ((j % 2 == 1 && i == 0) || (j % 2 == 0 && i == maxX - 1)) {
					arr[0][0] = bufor;
					return;
				}
				else {
					if (status == direction::DOWN)
						i++;
					else i--;
				}
			}
		}
		else {
			if (status == direction::DOWN)
				i++;
			else i--;
		}
	}
}