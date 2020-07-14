#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
bool cmp(int x, int y)
{
	return x > y;
}
int main(void)
{
	string N;
	cin >> N;
	vector<int> v;
	int temp=0;
	for (int List_i = 0; List_i < N.size(); List_i++)
		v.push_back(static_cast<int>(N[List_i]) - 48);
	vector<int>::iterator iter = find(v.begin(), v.end(), 0);
	
	if (v.end() == iter)
	{
		cout << "-1";
		return 0;
	}
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		temp += (*iter);
	}
	if (temp % 3 != 0)
	{
		cout << "-1";
		return 0;
	}

	sort(v.begin(), v.end(),cmp);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout));
	return 0;
}