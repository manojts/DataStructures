#include <bits/stdc++.h>
using namespace std;
int CountNumRotation(int array[], int size, int element)
{
	int start = 0;
	int end = size - 1;
	int prev;
	int next;
	int mid;
	int minElementIndex;
	int minElement;
	while(start <= end)
	{
		mid = (start + end) / 2;
		prev = (mid - 1 + size) % size;
		next = (mid + 1 + size) % size;
		if(array[mid] <= array[prev] && array[mid] <= array[next])
		{
			minElementIndex = mid;
			break;
		}
		else if(array[mid] <= array[end])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	start = 0;
	end = minElementIndex;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(array[mid]==element)
		{
			return mid;
		}
		else if(array[mid]<element)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	start = minElementIndex+1;
	end = size-1;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(array[mid]==element)
		{
			return mid;
		}
		else if(array[mid]<element)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return -1;
}
int main(){
	int size = 10;
	int arr[] = {5,6,7,8,9,12,1,2,3,4};
	int res = CountNumRotation(arr, size, 8);
	cout<<"Element is found at " <<res<<endl;

}