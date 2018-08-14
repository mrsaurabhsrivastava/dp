//https://www.youtube.com/watch?v=sVAB0p58tlg&t=
//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#define FOR(i,n) for(int i = 0; i < n; i++)
#define DEBUG 0

using namespace std;

struct node 
{
	int dWeight;
	int dValue;
};

int gCompare(node* n1, node* n2) 
{
	return n1->dWeight < n2->dWeight ? 1 : 0;
}
 
int gMaxValuePossibleForGivenWeight(node** xData, int xSize, int xWeight) 
{
	sort(xData, xData+xSize, gCompare);
#if DEBUG	
	FOR(i, xSize) 
	{
		cout<<xData[i]->dWeight<<" ";
	}
	cout<<"\n";
#endif
	// size 0 to n and weight 0 n
	int lMem[xSize][xWeight+1];
	for (int i = 0; i < xSize; i++) 
	{
		for (int j = 0; j <= xWeight; j++) 
		{
			if (j == 0) 
			{
				// Weight is 0
				lMem[i][j] = 0;
				continue;
			}
			int lCurrWeight = j;
			if (lCurrWeight < xData[i]->dWeight) 
			{
				// xData[i]->dWeight will not contribute in this 
				// Copy above cell
				if (i)  
					lMem[i][j] = lMem[i-1][j];
				else 
					lMem[i][j] = 0;
			}
			else 
			{
				int lWeightDiff = lCurrWeight-xData[i]->dWeight;
				if (i)
					lMem[i][j] = max(lMem[i-1][j], lMem[i-1][lWeightDiff]+xData[i]->dValue);
				else 
					lMem[i][j] = xData[i]->dValue;
					
			}
		}
	}
	return lMem[xSize-1][xWeight];	
}


int main() 
{
	std::ios_base::sync_with_stdio(false);
	int lTests;
	cin>>lTests;
	FOR(i, lTests) 
	{
		int lSize, lWeight;
		cin>>lSize>>lWeight;
		node** lData = new node*[lSize+1];
		//lData[0] = new node;
		//lData[0]->dWeight = 0;
		//lData[0]->dValue = 0;
		for (int j = 0; j < lSize; j++) 
		{
			lData[j] = new node; 
			//cin>>lData[j]->dWeight;
			cin>>lData[j]->dValue;
		}
		for (int j = 0; j < lSize; j++) 
		{
			//cin>>lData[j]->dValue;
			cin>>lData[j]->dWeight;
		}
		
		cout<<gMaxValuePossibleForGivenWeight(lData, lSize, lWeight)<<"\n";

	}
	return 0;
}
