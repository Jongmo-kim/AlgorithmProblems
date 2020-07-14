#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N,Temp;
	vector<int> v;
	cin >> N;
	for (int List_i = 0; List_i < N; List_i++)
	{
		cin >> Temp;
		int idx = lower_bound(v.begin(), v.end(), Temp)-v.begin();

		if (idx == v.size())
			v.push_back(Temp);
		else
			v[idx] = Temp;
	}
	cout << N-v.size() ;
	return 0;
}