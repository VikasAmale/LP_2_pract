 
#include <iostream>

 using namespace std;
 int main()
 {
 	int arr[100], n, temp = 0;

 	cout << "Enter the value of n" << endl;
 	cin >> n;

 	cout << "Enter the number of elements " << endl;
 	for (int i = 0; i < n; i++)
 	{
 		cin >> arr[i];
 	}

 	//selection sort logic

 	for (int i = 0; i < n - 1; i++)
 	{
 		int min = i;
 		for (int j = i + 1; j < n; j++)
 		{
 			if (arr[j] < arr[min])
 				min = j;
 		}

 		temp = arr[i];
 		arr[i] = arr[min];
 		arr[min] = temp;
 	}

 	cout << "Sorted array using selection sort:" << endl;
 	for (int i = 0; i < n; i++)
 	{
 		cout << arr[i] << " ";
 	}

 	return 0;
 }