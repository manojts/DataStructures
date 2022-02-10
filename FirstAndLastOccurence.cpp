#include <bits/stdc++.h>
using namespace std;
void FindFirstLastOccurence(int size, int arr[], int element)
{
	int start =0;
	int end = size -1;
	int mid;
	int first, last;
	int count = 0;
	while(start<=end){
		mid = (start + end )/2;
		if(arr[mid] == element){
			first = mid;
			end = mid - 1;
		}
		else if(arr[mid]<element)
			start = mid + 1;
		else
			end = mid - 1;
	}

	start = 0, end = size - 1;
	while(start<=end){
		mid = (start + end )/2;
		if(arr[mid] == element){
			last = mid;
			start = mid + 1;
		}
		else if(arr[mid]<element)
			start = mid + 1;
		else
			end = mid - 1;
	}
	
	count = last - first + 1;
	cout<<first<<", "<<last<<endl;
	cout<<"No of occurences "<<count<<endl;
}
int main()
{
	int size = 20;
	int arr[20] ;
	for(int i=0;i<20;i++){
		arr[i] = 4;
	}
	
	FindFirstLastOccurence(size, arr, 4);
}