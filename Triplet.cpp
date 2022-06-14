#include <bits/stdc++.h>
using namespace std;
int main(){
	int array[6] = {1,2,3,6,4,5};
	int size = 6;
	int sum = 10;
	sort(array, array+size);
	for(int i=0;i<size-2;i++){
		int l=i+1;
		int r = size-1;
		while(l<r){
			if(array[l] + array[r] + array[i] == sum){
				cout<<array[i]<< ","<< array[l]<<","<<array[r]<<endl;
				r--;
				l++;
			}
			else if(array[i]+ array[r]+array[l]>sum){
				r--;
			}
			else{
				l++;
			}
		}
	}
}