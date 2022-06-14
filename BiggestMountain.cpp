#include <bits/stdc++.h>
using namespace std;
// Identify the peaks 
int main(){
	int array[] = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
	int size = 16;
	int result;
	for(int i=1;i<=size-2; ){
		// if it is a peak
		if(array[i]>array[i-1] && array[i]>array[i+1]){
			int count = 1;
			int j=i;
			while(j>=1 && array[j]> array[j-1]){
				count++;
				j--;
			}
			while(i<size-1 && array[i]> array[i+1]){
				i++;
				count++;
			}
			result= count>result? count:result;
		}
		else{
			i++; // if it is not a peak
		}
	}
	cout<<result<<endl;
}