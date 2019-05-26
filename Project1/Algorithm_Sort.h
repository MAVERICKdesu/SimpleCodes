//QuickSort, BubbleSort, StraightInsertionSort, ShellSort, MergeSort
#include<iostream>
using namespace std;
template<class T>
void QuickSort(int l, int r, T arr[])
{
	if (l >= r)
		return;
	T base = arr[r];
	T pl = l, pr = r;
	while (pl != pr)
	{
		while (pl < pr && arr[pl] <= base)
			++pl;
		arr[pr] = arr[pl];
		while (pl < pr && arr[pr] >= base)
			--pr;
		arr[pl] = arr[pr];
	}
	arr[pr] = base;
	QuickSort(l, pr - 1, arr);
	QuickSort(pr + 1, r, arr);
}

template<class T>
void BubbleSort(int l, int r, T arr[])
{
	T temp;
	for (int i = l; i < r; ++i)
		for (int j = l; j < r - i; ++j)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

template<class T>
void StraightInsertionSort(int l, int r, T arr[])
{
	for (int crr = l + 1; crr <= r; ++crr)
	{
		int p;
		T temp = arr[crr];
		for (p = crr - 1; p >= l && arr[p] > temp; --p)
			arr[p + 1] = arr[p];
		arr[p + 1] = temp;
	}
}

template<class T>
void ShellSort(int l, int r, T arr[])
{
	int increment = r - l + 1;
	do
	{	increment = increment / 3 + 1;
		for (int start = l; start < l + increment; ++start)
		{
			int nmax = (r - start) / increment;
			for (int crr = start + increment; crr <= start + increment * nmax; crr += increment)
			{
				int p;
				T temp = arr[crr];
				for (p = crr - increment; p >= start && arr[p] > temp; p -= increment)
					arr[p + increment] = arr[p];
				arr[p + increment] = temp;
			}
		}
		
	} while (increment > 1);
}

template<class T>
void MergeSort(int l, int r, T arr[])
{
	if (l == r)
		return;
	int mid = (l + r) / 2, lenth = r - l + 1;
	MergeSort(l, mid, arr);
	MergeSort(mid + 1, r, arr);
	T* temp = new T[lenth];
	for (int p1 = l, p2 = mid + 1, i = 0; i < lenth; ++i)
		if (p1 <= mid && p2 <= r)
			temp[i] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
		else
			if (p1 > mid)
				temp[i] = arr[p2++];
			else
				temp[i] = arr[p1++];
	for (int i = 0; i < lenth; ++i)
		arr[i + l] = temp[i];
}