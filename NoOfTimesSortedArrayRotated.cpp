#include <bits/stdc++.h>
using namespace std;
int CountNumRotation(int array[], int size)
{
	int start = 0;
	int end = size - 1;
	int prev;
	int next;
	int mid;
	while(start <= end)
	{
		mid = (start + end) / 2;
		prev = (mid - 1 + size) % size;
		next = (mid + 1 + size) % size;
		if(array[mid] <= array[prev] && array[mid] <= array[next])
		{
			return mid;
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
}
int main(){
	int size = 10;
	int arr[] = {5,6,7,8,9,12,1,2,3,4};
	int count = CountNumRotation(arr, size);
	cout<<"The array is rotated right side " <<count<<endl;
	cout<<"The array is rotated left side " <<(size - count)<<endl;

}