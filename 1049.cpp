#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void)
{
	int NumOfNeed, NumOfBrend, EachPrice, SetPrice, Mod;
	cin >> NumOfNeed >> NumOfBrend;
	vector<int> Set;
	vector<int> Each;

	for (int List_i = 0; List_i < NumOfBrend; List_i++)
	{
		cin >> SetPrice >> EachPrice;

		Set.push_back(SetPrice);
		Each.push_back(EachPrice);

	}
	sort(Set.begin(), Set.end());
	sort(Each.begin(), Each.end());

	if (*Each.begin() * 6 <= *Set.begin()) //��Ÿ���� ������ ��Ʈ�� ���ݺ��� �����ϰų� ������
	{
		cout << *Each.begin() * NumOfNeed;
		return 0;
	}
	else //������ΰ�� : ��Ʈ�� ������ ��°ͺ��� �����Ҷ�
	{

		Mod = NumOfNeed % 6; // ��Ʈ�� ����� ������ ���
		if (Mod * (*Each.begin()) < *Set.begin())// �������� ������ ���� ��Ʈ�� ���ݺ��� ���ٸ� �� �������� ������ �춧�� �����ϸ�
		{
			cout << (Mod *static_cast<double>(*Each.begin())) + (floor((NumOfNeed / 6.0)+0.5)) * *Set.begin();//floor( ... +0.5) mod�� 0�϶� ������ ������ Ư���� 0.999..�� ��������� ����ɼ� �վ �̸� Ÿ���ϰ��� 0.5�� ���� ������(=�ݿø�)
		}
		else {//�����λ�°ͺ��� ��Ʈ�� ��°��� �����ϴٸ�

			cout << (ceil(NumOfNeed / 6.0)) * (*Set.begin());
		}
		return 0;
	}
}