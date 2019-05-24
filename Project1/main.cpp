#include<iostream>
#include<time.h>
#include"Algorithm_QuickSort.h"
#define SIZE 1000

using namespace std;
int main()
{
	int a[SIZE + 1];
	srand((unsigned)time(NULL));
	for (int i = 0; i < SIZE; i++)
		a[i] = rand();
	QuickSort<int>(0, SIZE-1, a);
	for (int i = 0; i < SIZE; ++i)
		cout << a[i] << endl;
	return 0;
}