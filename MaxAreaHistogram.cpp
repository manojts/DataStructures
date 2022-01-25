#include<bits/stdc++.h>
using namespace std;
vector<int> findNSR(int array[], int size)
{
	stack<int> s;
	stack<int> sindex;
	vector<int> res;
	for(int i=size-1;i>=0;i--)
	{
		if(s.empty())
		{
			res.push_back(size);
		}
		if(!s.empty() && s.top()<array[i])
		{
			res.push_back(i+1);
		}
		else if(!s.empty() && s.top() >= array[i])
		{
			while(!s.empty() && s.top() >= array[i])
			{
				s.pop();
				sindex.pop();
			}
			if(s.empty())
			{
				res.push_back(size);
			}
			else
			{
				res.push_back(sindex.top());
			}
		}
		s.push(array[i]);
		sindex.push(i);
		
	}

	reverse(res.begin(), res.end());
	cout<<"Nerest Smaller to Right ";
	for(int i=0;i<res.size() ;i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return res;
}
vector<int> findNSL(int array[], int size)
{
	stack<int> s;
	stack<int> sindex;
	vector<int> res;
	for(int i=0;i<size;i++)
	{
		if(s.empty())
		{
			res.push_back(-1);
		}
		if(!s.empty() && s.top() < array[i])
		{
			res.push_back(sindex.top());
		}
		else if(!s.empty() && s.top() >= array[i])
		{
			while(!s.empty() && s.top()>=array[i])
			{
				s.pop();
				sindex.pop();
			}
			if(s.empty())
			{
				res.push_back(-1);
			}
			else
			{
				res.push_back(sindex.top());
			}
		}

		s.push(array[i]);
		sindex.push(i);



	}
	cout<<"Nearest Smaller to Left ";
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return res;
}
int main()
{
	int array[7] ={6, 2, 5, 4, 5, 1, 6};
	int size = 7;
	vector<int> NSR;
	NSR = findNSR(array, size);
	vector<int> NSL;
	NSL = findNSL(array, size);
	int maxArea = 0;
	for(int i=0;i<NSR.size();i++)
	{
		int res = (NSR[i]-NSL[i]-1)*array[i];
		if(maxArea<res)
		{
			maxArea = res;
		}
	}
	cout<<"Area of Max Histogram is "<< maxArea<<endl;
}
