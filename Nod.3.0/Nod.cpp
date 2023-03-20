#include <iostream>
using namespace std;

/*—оставить программу нахождени€ наибольшего общего делител€
четырех натуральных чисел.*/

// returns number of dividers, filling arr
int find_dividers(int namber, int* arr, int SIZE)
{
	int index = 0;
	
	for (int i = 1; i <= namber; i++)
	{
		if (i + 1 == SIZE)
		{
			cout << "Error, please enter a number less than " << i << endl;
			return 0;
		}

		if (namber % i == 0)
			arr[index++] = i;
	}
	return index;
}

//returns fool len massiv
int zero_namber(int* arr, int SIZE)
{
	int index = 0;
	for (; index < SIZE; index++)
		arr[index] = index;
	return index;
}

//Returns the value and len of an array of equal divisors
int finf_ecvol_elems(int* arr, int* two, int* resault, int first, int sekond, int SIZE)
{
	int index = 0;
	for (int i = 0; i < first; i++)
	{
		for (int k = 0; k < sekond; k++)
		{
			if (two[k] > arr[i])
				break;

			if (arr[i] == two[k])
				resault[index++] = arr[i];
		}
	}
	return index;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, c, d;

	cout << "Enter 4 natural numbers." << endl;
	cin >> a >> b >> c >> d;

	if (a == 0 && b == 0 && c == 0 && d == 0)
	{
		cout << "Zero is divisible by all numbers";
		return;
	}

	const int SIZE = 1000;
	int arr[SIZE], two[SIZE], thre[SIZE], four[SIZE], five[SIZE];

	int arr_len = find_dividers(a, arr, SIZE);
	int two_len = find_dividers(b, two, SIZE);
	int thre_len = find_dividers(c, thre, SIZE);
	int four_len = find_dividers(d, four, SIZE);

	if (a == 0)
		arr_len = zero_namber(arr, SIZE);
	if (b == 0)
		two_len = zero_namber(two, SIZE);
	if (c == 0)
		thre_len = zero_namber(thre, SIZE);
	if (d == 0)
		four_len = zero_namber(four, SIZE);

	int five_len = finf_ecvol_elems(arr, two, five, arr_len, two_len, SIZE);
	arr_len = finf_ecvol_elems(thre, four, arr, thre_len, four_len, SIZE);
	two_len = finf_ecvol_elems(five, arr, two, five_len, arr_len, SIZE);

	int resault = 0;
	for (int index = 0; index < two_len; index++)
	{
		if (two[index] > resault)
			resault = two[index];
	}
	cout << "GCD of four numbers = " << resault << endl;
}