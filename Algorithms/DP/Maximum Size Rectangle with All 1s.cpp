#include <bits/stdc++.h>
int areaOfHistogram(vector<int> &hist , int size){
	vector<int> left(size , 0);
	stack<int> st;
	int area = 0;
	for(int i=0;i<size;i++)
	{
		while(!st.empty() && hist[st.top()] >= hist[i]) st.pop();
		if(st.empty())left[i] = 0;
		else left[i] = st.top() + 1;
		st.push(i);
	}
	while(!st.empty())st.pop();

	for(int i=size-1;i>=0;i--)
	{
		while(!st.empty() && hist[st.top()] >= hist[i])
			st.pop();
		int right;
		if(st.empty())right = size-1;
		else right = st.top() - 1;
		area = max(area , (right - left[i] + 1) * hist[i]);
		st.push(i);
	}

	return area;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	vector<int> histogram(m , 0);
	int area = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mat[i][j] == 1)
				histogram[j] += 1;
			else histogram[j] = 0;
		}
		area = max(area , areaOfHistogram(histogram,  histogram.size()));
	}
	return area;
}