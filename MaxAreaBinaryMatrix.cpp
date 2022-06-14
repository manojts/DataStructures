#include <bits/stdc++.h>
using namespace std;
/*
	Convert 2d binary array to values
*/
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
	return res;
}
int MaxAreaHistogram(int InputArray[], int size)
{
	vector<int> NSR;
	NSR = findNSR(InputArray, size);
	vector<int> NSL;
	NSL = findNSL(InputArray, size);
	int maxArea = 0;
	for(int i=0;i<NSR.size();i++)
	{
		int res = (NSR[i] - NSL[i] - 1) * InputArray[i];
		if(maxArea < res)
		{
			maxArea = res;
		}
	}
	return maxArea;
}
int main()
{
	int array[4][4] = {
		{ 0, 1, 1, 0 },
      	{ 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
    int column = 4;
    int row = 4;
    int InputArray[row][column];
    int result = 0;
    cout<<"Converting 2d binary array to values"<<endl;
    for(int i=0;i<row;i++)
    {
    	for(int j=0;j<column;j++)
    	{
    		if(i==0)
    		{
    			InputArray[i][j]=array[i][j];
    			cout<<InputArray[i][j]<<" ";
    		}
    		else
    		{
    			if(array[i][j]==0)
    			{
    				InputArray[i][j] = 0;
    			}
    			else
    			{
    				InputArray[i][j] = InputArray[i-1][j] + array[i][j];
    			}
    			cout<<InputArray[i][j]<<" ";
    		}
    	}
    	cout<<endl;
    	int max = MaxAreaHistogram(InputArray[i], column);
    	if(max>result)
    	{
    		result = max;
    	}
    }
    cout<<"Final Answer is "<< result<<endl;

}