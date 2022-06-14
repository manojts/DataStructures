#include<bits/stdc++.h>
using namespace std;
/*

	Find Maximum Element to Left 
	Find Maximum Element to Right
	Result += Minimum(Left[i], Right[i]) - array[i]

*/
int findMin(int a, int b)
{
	if(a<b)
	{
		return a;
	}
	return b;
}

int main()
{
	int array[]= {3,0,2,0,4};
	int size = 5;
	int left[5];
	int right[5];
	left[0]= array[0];

	for(int i=1;i<size;i++)
	{
		if(array[i]>left[i-1])
		{
			left[i] = array[i];
		}
		else
		{
			left[i] =left[i-1];
		}
	}

	right[size-1]=array[size-1];
	for(int i=size-2;i>=0;i--)
	{
		if(array[i]>right[i+1])
		{
			right[i] = array[i];
		}
		else
		{
			right[i] = right[i+1];
		}
	}

	int water = 0;
	for(int i=0;i<size;i++)
	{
		water += findMin(left[i],right[i])-array[i];
	}
	cout<<water<<endl;
}