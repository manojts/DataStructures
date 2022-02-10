#include<bits/stdc++.h>
using namespace std;
int FindCount(int array[], int size, int element)
{
	int start = 0;
	int end = size - 1;
	int mid;
	int count = 0;
	int first;
	int last;
	while(start<=end)
	{
		mid = (start + end)/2;
		if(array[mid] == element)
		{
			first = mid;
			end = mid - 1;
		}
		else if(array[mid] < element)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	start = 0;
	end = size - 1;
	while(start <= end)
	{
		mid = (start+end)/2;
		if(array[mid] == element)
		{
			last = mid;
			start = mid + 1;
		}
		else if(array[mid] < element)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return (last - first + 1);
}
int main()
{
	int array[] = {1,2,3,4,4,4,4,4,6,7,8,8};
	int size = 12;
	int count = FindCount(array, size, 4);
	cout<<"Count is "<<count<<endl;
}