#include <bits/stdc++.h>
using namespace std;
int BinarySearchfn(int arr[], int size, int element){
	int start = 0;
	int end = size -1 ;
	int mid;
	while(start<=end){
		//mid = start + (end - start)/2;
		mid = (start + end)/2;
		if(arr[mid] == element){
			return mid;
		}
		else if(arr[mid]<element){
			start = mid + 1;
		}
		else{
			end  = mid - 1;
		}
	}
	return -1;
}
int main(){
	int size;
	size = 10;
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int res = BinarySearchfn(arr,size, 2);
	cout<<"Element found at index "<<res; 
}
