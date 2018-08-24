//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#define FOR(i,n) for(int i = 0; i < n; i++)

using namespace std;
template <typename T> 
T get() 
{
	T result;
	cin>>result;
	return result;
}

int gMaxSteps(const vector<int> xArray) 
{
	int i = 0;
	int lSteps = 0;
	while(i < xArray.size()-1)
	{
		if (xArray[i] <= 0) 
			return -1;

		int lMaxSteps = xArray[i];
		if (i + lMaxSteps >= xArray.size()-1) 
		{
			lSteps++;
			break;
		}
		int lMaxNum = INT_MIN;
		int lNextIndex = i;
		for (int j = i+1; j < i+1+lMaxSteps; j++) 
		{
			if (xArray[j] >= lMaxNum)
			{	
				lMaxNum = xArray[j];
				lNextIndex = j;
			}
		}
		i = lNextIndex;
		lSteps++;
	}
	return lSteps;
}

int main() 
{
	std::ios_base::sync_with_stdio(false);
	int lTest = get<int>();
	FOR(i, lTest) 
	{
		int n = get<int>();
		vector<int> lArray(n, 0);
		FOR(j, n) 
		{
			int e = get<int>();
			lArray[j] = e;
		}
		cout<<gMaxSteps(lArray)<<"\n";
	}
}
