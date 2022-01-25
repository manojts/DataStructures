#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[4]={1,3,2,4};
	vector<int> res;
	stack<int> s;
	int size = 4;

	for(int i=0;i<size;i++)
	{
		if(s.empty())
		{
			res.push_back(-1);
		}
		if(!s.empty() && s.top()<arr[i])
		{
			res.push_back(s.top());
		}
		else if(!s.empty() && s.top()>=arr[i])
		{
			while(!s.empty() && s.top()>=arr[i])
			{
				s.pop();
			}
			if(s.empty()){
				res.push_back(-1);
			}
			else{
				res.push_back(s.top());
			}
		}
		s.push(arr[i]);
	}
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
}