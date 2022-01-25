#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[7]={100, 80, 60, 70, 60, 75, 85};
	vector<int> res;
	stack<int> s;
	stack<int> sindex;
	int size = 7;

	for(int i=0;i<size;i++)
	{
		if(s.empty())
		{
			res.push_back(-1);
		}
		if(!s.empty() && s.top()>arr[i])
		{
			res.push_back(sindex.top());
		}
		else if(!s.empty() && s.top()<=arr[i])
		{
			while(!s.empty() && s.top()<=arr[i])
			{
				s.pop();
				sindex.pop();
			}
			if(s.empty()){
				res.push_back(-1);
			}
			else{
				res.push_back(sindex.top());
			}
		}
		s.push(arr[i]);
		sindex.push(i);
	}
	for(int i=0;i<res.size();i++){
		cout<<i-res[i]<<" ";
	}
}