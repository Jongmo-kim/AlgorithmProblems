#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
bool vaild(vector<int>& v,vector<char>& c)
{
	for (int List_i = 0; List_i < c.size(); List_i++)
	{
		if (c[List_i] == '>' && v[List_i] < v[List_i + 1])
			return false;
		else if (c[List_i] == '<' && v[List_i] > v[List_i + 1])
			return false;
	}
	return true;
}
int main(void)
{
	int NumOfInequality;
	char TempToPush;
	vector<char> v;
	vector<int> c;
	cin >> NumOfInequality;
	for (int List_i = 0; List_i < NumOfInequality; List_i++)
	{
		cin >> TempToPush;
		v.push_back(TempToPush);
	}
	for (int List_i = 9; List_i >= 9 - NumOfInequality; List_i--)
	{
		c.push_back(List_i);
	}
	while (1)
	{
		if (vaild(c,v))
			break;
		prev_permutation(c.begin(),c.end());
	}
	copy(c.begin(), c.end(), ostream_iterator<int>(cout));
	c.clear();
	for (int List_i = 0; List_i <= NumOfInequality; List_i++)
		c.push_back(List_i);
	while (1)
	{
		if (vaild(c,v))
			break;
		next_permutation(c.begin(), c.end());
	}
	cout << endl;
	copy(c.begin(), c.end(), ostream_iterator<int>(cout));

	return 0;
	return 0;
}