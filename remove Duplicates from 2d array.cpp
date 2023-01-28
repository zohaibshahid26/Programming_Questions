#include<iostream>
using namespace std;
int *resize(int* arr, int& size)
{
	size++;
	int* temp = new int[size];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	delete []arr;
	arr = temp;
	return arr;
}
int main()
{
	bool isDuplicate[21];
	for (int i = 0; i < 21; i++)
		isDuplicate[i] = false;
	int num;
	int n;
	cin >> n;

	int *size = new int[n];
	for(int i=0;i<n;i++)
	{
		size[i] = 0;
	}
	int** arr = new int*[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[0];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		while (num != -1)
		{
			if (isDuplicate[num] == false)
			{
				arr[i] = resize(arr[i], size[i]);
				arr[i][size[i] - 1] = num;
				isDuplicate[num] = true;
			}
			cin >> num;
		}
		for (int i = 0; i < 21; i++)
			isDuplicate[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < size[i]; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < n; i++)
	{
		delete []arr[i];
		arr[i] = nullptr;
	}
	delete[]arr;
	arr = nullptr;
}