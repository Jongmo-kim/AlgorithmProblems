/*
주사위를 여러개 놓는다고 상상해서 문제를 풀어 나가면 된다.
내가 실수한 부분은 주사위의 특징에서 발생했다.
주사위의 전개도를 볼때 
	D
  E A B F
	C
A는 F와 마주보고 있어 주사위를 모서리에  A와F가 보이게끔 놓을수가 없다
따라서 A와 F , B와 E 같이 마주보는 면을 신경써서 코딩하면 됬었다.
1면이 보이는 경우 2면이 보이는 경우 3면이 보이는 경우를 각각 나누어 계산하면 된다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	long long unsigned int min3, min2, n, x;
	int temp[4][2] = { 0,1 , 0,4 , 1,5 , 4,5 };
	vector<long long unsigned int> v;
	cin >> n;
	for (int i = 0; i < 6; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	if (n == 1)
	{
		sort(v.begin(), v.end());
		cout << ((*v.begin()) + (*(v.begin() + 1)) + (*(v.begin() + 2)) + (*(v.begin() + 3)) + (*(v.begin() + 4)));
		return 0;
	}
	min2 = v[0] + v[1];
	min3 = v[2] + v[0] + v[1];
	for (int i = 0; i < 4; i++)
	{
		if ((v[2] + v[temp[i][0]] + v[temp[i][1]]) > (v[3] + v[temp[i][0]] + v[temp[i][1]]))
			min3 = min(v[3] + v[temp[i][0]] + v[temp[i][1]], min3);
		else
			min3 = min(v[2] + v[temp[i][0]] + v[temp[i][1]], min3);
	}
	for (int i = 0; i < 6; i++)
		for (int j = i + 1; j < 6; j++)
			if (!((i == 0 || j == 5) & (i == 1 || j == 4) & (i == 2 || j == 3))) // 조건식 실수 &은 비트연산자 이므로 내가 의도한 AND연산이 되지 않는다.
				min2 = min(v[i] + v[j], min2);
	sort(v.begin(), v.end());
	cout << "v.begin : " << *v.begin() << endl;
	cout << "min2 :" << min2 << endl;
	cout << "min3 : " << min3 << endl;

	cout<<((*v.begin()) * (5 * (n) * (n)-(16 * n) + 12)) + (min2 * (8 * n - 12)) + (min3 * 4);
	
	return 0;
}
//제출본
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	long long unsigned int min3, min2, n, x;
	int temp[4][2] = { 0,1 , 0,4 , 1,5 , 4,5 };
	vector<long long unsigned int> v;
	cin >> n;
	for (int i = 0; i < 6; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	if (n == 1)
	{
		sort(v.begin(), v.end());
		cout << ((*v.begin()) + (*(v.begin() + 1)) + (*(v.begin() + 2)) + (*(v.begin() + 3)) + (*(v.begin() + 4)));
		return 0;
	}
	min2 = v[0] + v[1];
	min3 = v[2] + v[0] + v[1];
	for (int i = 0; i < 4; i++)
	{
		if ((v[2] + v[temp[i][0]] + v[temp[i][1]]) > (v[3] + v[temp[i][0]] + v[temp[i][1]]))
			min3 = min(v[3] + v[temp[i][0]] + v[temp[i][1]], min3);
		else
			min3 = min(v[2] + v[temp[i][0]] + v[temp[i][1]], min3);
	}
	for (int i = 0; i < 6; i++)
		for (int j = i + 1; j < 6; j++)
			if (!((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3))) //수정함
				min2 = min(v[i] + v[j], min2);

	sort(v.begin(), v.end());
	cout << "v.begin : " << *v.begin() << endl;
	cout << "min2 :" << min2 << endl;
	cout << "min3 : " << min3 << endl;

	cout << ((*v.begin()) * (5 * (n) * (n)-(16 * n) + 12)) + (min2 * (8 * n - 12)) + (min3 * 4);

	return 0;
}
