//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
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

int insertionIndex(const vector<int>& xArray, int x) 
{
	int start = 0;
	int end = xArray.size()-1;
	while(start < end - 1) 
	{
		int mid = start + ((end-start)>>1);
		if (xArray[mid] >= x) 
			end = mid;
		else 
			start = mid; 
	}
	
	return (x <= xArray[start])? start : end;	
	//return end;
}

int LIS(const vector<int>& xArray) 
{
	vector<int> LSIArray;
	LSIArray.reserve(xArray.size());
	int index = 0;
	LSIArray.push_back(xArray[0]);
	index++;
	for (int i = 1; i < xArray.size(); i++) 	
	{
		if (xArray[i] < LSIArray[index-1]) 
		{
			int insertIndex = insertionIndex(LSIArray, xArray[i]);
			LSIArray[insertIndex] = xArray[i];
		}	
		else if (xArray[i] > LSIArray[index-1])  
		{
			LSIArray.push_back(xArray[i]);
			index++;
		}
	}
	//cout<<"\n";
	//for(auto v:LSIArray) 
	//	cout<<v<<" ";
	//	
	//cout<<"\n";
	return index;
}

int main() 
{
	std::ios_base::sync_with_stdio(false);
	int lTest = get<int>();
	FOR(i, lTest) 
	{
		int n = get<int> ();
		if (n > 0) 
		{
			vector<int> lArray(n,-1);
			FOR(j, n) 
			{
				lArray[j] = get<int>();
			}	
			cout<<LIS(lArray)<<"\n";
		}
		else 
			cout<<0<<"\n";
	}
}
