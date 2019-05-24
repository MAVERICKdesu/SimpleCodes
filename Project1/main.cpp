#include<iostream>
#include<time.h>
#include"Algorithm_Sort.h"
#define SIZE 10

using namespace std;
int main()
{
	int a[SIZE + 1];
	srand((unsigned)time(NULL));
	for (int i = 0; i < SIZE; i++)
		a[i] = rand();
	for (int i = 0; i < SIZE; ++i)
		cout << a[i] << endl;
	cout << endl;
	ShellSort(0,SIZE-1, a);
	for (int i = 0; i < SIZE; ++i)
		cout << a[i] << endl;
	cin >> a[0];
	return 0;
}