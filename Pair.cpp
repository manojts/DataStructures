#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> vect;
	vect.push_back(2);
	vect.push_back(8);
	vect.push_back(3);
	vect.push_back(5);
	vect.push_back(6);
	vect.push_back(-2);
	int sum = 14;
	map<int, int> m;
	for(int i = 0;i<vect.size();i++){
		int x = sum - vect[i];
		if(m.find(x)!=m.end()){
			cout<<x<<","<<vect[i]<<endl;
			break;
		}
		m[vect[i]] = 1;
	} 
	
}