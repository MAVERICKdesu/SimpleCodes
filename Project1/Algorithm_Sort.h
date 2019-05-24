//QuickSort, BubbleSort, StraightInsertionSort, ShellSort
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

template<class T = int>
void StraightInsertionSort(int l, int r, T arr[])
{
	for (int crr = l + 1; crr <= r; ++crr)
	{
		int p, temp = arr[crr];
		for (p = crr - 1; p >= l && arr[p] > temp; --p)
			arr[p + 1] = arr[p];
		arr[p + 1] = temp;
	}

}

template<class T = int>
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
				int p, temp = arr[crr];
				for (p = crr - increment; p >= start && arr[p] > temp; p -= increment)
					arr[p + increment] = arr[p];
				arr[p + increment] = temp;
			}
		}
		
	} while (increment > 1);
}