//QuickSort, BubbleSort
template<class T = int>
void QuickSort(int l, int r, T arr[])
{
	if (l >= r)
		return;
	T base = arr[r];
	T pl = l, pr = r;
	while (pl != pr)
	{
		while (pl < pr && arr[pl] <= base)
		{
			++pl;
		}
		arr[pr] = arr[pl];
		while (pl < pr && arr[pr] >= base)
		{
			--pr;
		}
		arr[pl] = arr[pr];
	}
	arr[pr] = base;
	QuickSort(l, pr - 1, arr);
	QuickSort(pr + 1, r, arr);
}

template<class T = int>
void BubbleSort(int lenth, T arr[])
{
	T temp;
	for (int i = 0; i < lenth - 1; ++i)
		for (int j = 0; j < lenth - 1 - i; ++j)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}