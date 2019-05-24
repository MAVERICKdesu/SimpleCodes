template<class T>
void QuickSort(int l,int r,T arr[])
{
	if (l >= r)
		return ;
	T base = arr[r];
	T pl = l, pr = r;
	while (pl != pr)
	{
		while(pl<pr && arr[pl]<=base)
		{
			++pl;
		}
		arr[pr] = arr[pl];
		while(pl<pr && arr[pr] >= base)
		{
			--pr;
		}
		arr[pl] = arr[pr];
	}
	arr[pr] = base;
	QuickSort(l, pr-1,arr);
	QuickSort(pr+1, r, arr);
}
