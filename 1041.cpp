/*
�ֻ����� ������ ���´ٰ� ����ؼ� ������ Ǯ�� ������ �ȴ�.
���� �Ǽ��� �κ��� �ֻ����� Ư¡���� �߻��ߴ�.
�ֻ����� �������� ���� 
	D
  E A B F
	C
A�� F�� ���ֺ��� �־� �ֻ����� �𼭸���  A��F�� ���̰Բ� �������� ����
���� A�� F , B�� E ���� ���ֺ��� ���� �Ű�Ἥ �ڵ��ϸ� �����.
1���� ���̴� ��� 2���� ���̴� ��� 3���� ���̴� ��츦 ���� ������ ����ϸ� �ȴ�.
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
			if (!((i == 0 || j == 5) & (i == 1 || j == 4) & (i == 2 || j == 3))) // ���ǽ� �Ǽ� &�� ��Ʈ������ �̹Ƿ� ���� �ǵ��� AND������ ���� �ʴ´�.
				min2 = min(v[i] + v[j], min2);
	sort(v.begin(), v.end());
	cout << "v.begin : " << *v.begin() << endl;
	cout << "min2 :" << min2 << endl;
	cout << "min3 : " << min3 << endl;

	cout<<((*v.begin()) * (5 * (n) * (n)-(16 * n) + 12)) + (min2 * (8 * n - 12)) + (min3 * 4);
	
	return 0;
}
//���⺻
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
			if (!((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3))) //������
				min2 = min(v[i] + v[j], min2);

	sort(v.begin(), v.end());
	cout << "v.begin : " << *v.begin() << endl;
	cout << "min2 :" << min2 << endl;
	cout << "min3 : " << min3 << endl;

	cout << ((*v.begin()) * (5 * (n) * (n)-(16 * n) + 12)) + (min2 * (8 * n - 12)) + (min3 * 4);

	return 0;
}
