#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

/*
https://www.acmicpc.net/problem/1202
�������� ���� ����̴� �������� �б�� ����ߴ�.

����̰� �� ���������� ������ �� N�� �ִ�. �� ������ ���� Mi�� ���� Vi�� ������ �ִ�.
����̴� ������ K�� ������ �ְ�, �� ���濡 ���� �� �ִ� �ִ� ���Դ� Ci�̴�.
���濡�� �ִ� �� ���� ������ ���� �� �ִ�.

����̰� ��ĥ �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� N�� K�� �־�����. (1 �� N, K �� 300,000)

���� N�� �ٿ��� �� ������ ���� Mi�� Vi�� �־�����. (0 �� Mi, Vi �� 1,000,000)

���� K�� �ٿ��� ���濡 ���� �� �ִ� �ִ� ���� Ci�� �־�����. (1 �� Ci �� 100,000,000)

��� ���ڴ� ���� �����̴�.

//�ذ� ���
�������� ������ N�� �ִٰ� ������  �� �������� ���Կ� ������ �ִ�.
����̴� ���� ������ ��� ������ ��ġ�� �����Ƿ� ������ �������� ���������� �����Ѵ�.

����, ����̴� �ڽ��� ������� �ִ��� ���� ���Ը� ��Ƽ�� ������ ���������� �����Ͽ� ��������.
 �׷��ٸ� ������ ���� ��ù��° �ִ� ������ ���� ���� ���Ը� ��ƿ���̴�.

���� ������ �������� �ִ� �������, ����̰� ���� ������� ���Ը� ����Ͽ�
���Ը� ��ƾ�ٸ� �� ���� ������, �� ���� �������� �Ѿ�� �����ϸ� �ǰڴ�.

�׷��� �����Ѵٸ� ����̰� ���� �ִ� �ִ� ������ ���ðͰ���.

//Ʋ�� ����
��� ���� �ߴ��� ����� �� ���� ������ �� ������ �����
for���� �ΰ� ����Ͽ� �ϳ��� ���渶�� �´� �������� ã�� 
ã������ ���� �������� �Ѿ�� �ٽ� ó������ �ϳ��� ã�� ����� ��� �ߴ�.
������ ù�õ��� �ð��ʰ��� ���� �����ߴ�.
�ᱹ �˻����� �ذ��ߴ�.

//����
https://dyngina.tistory.com/24
https://jaimemin.tistory.com/760
�� ���� �ߴ�.
priority_queue �켱���� ť ��� �ڷᱸ���� �ִ�. 
�̴� queue�� �����̱��ѵ� �װͰ� �޸� ���� �ְ� �װ��� ������ �ּ� Ȥ�� �ִ���� ������.
�ִ���� �����°��� Max Heap �ּҺ��� �����°��� Min Heap�̶�� �Ѵ�.
�����̶��ϸ� ���²� ���������� �ִ� Ȥ�� �ּҹۿ� �𸣴� ������ �ִ�.
���� �뷫���� ������ ã�Ұ�
�ҽ��������� ��α׸� �����Ͽ� �ذ��ߴ�.
���� �ڷᱸ���� �ͼ�ġ �ʾƼ� ���ݴ� ���� ���ΰ� �ʿ��ϰڴ�.
*/

class Gem {
public:
	int weight;
	int price;
};

bool cmp(const Gem& g1, const Gem& g2)
{
	
	if (g1.weight < g2.weight)
	{
		return true;
	}
	return false;
}
using namespace std;
int main(void)
{
	priority_queue<int> priorityQueue;
	int NumOfGem, NumOfBag;
	cin >> NumOfGem >> NumOfBag;

	Gem* Gems = new Gem[NumOfGem];
	for (int List_i = 0; List_i < NumOfGem; ++List_i)
	{
		cin >> Gems[List_i].weight >> Gems[List_i].price;
	}
	sort(Gems, Gems + NumOfGem, cmp);

	int* BagList = new int[NumOfBag];
	for (int List_i = 0; List_i < NumOfBag; ++List_i)
	{
		cin >> BagList[List_i];
	}
	sort(BagList, BagList + NumOfBag);
	////////////////////////////////////////////////////////////////////////////////////////
	int List_Gem = 0;
	long long StealedMoney = 0;
	for (int List_Bag = 0; List_Bag < NumOfBag; ++List_Bag) // ������ �پ������� �ݺ�
	{
		while (List_Gem < NumOfGem && Gems[List_Gem].weight <= BagList[List_Bag])
			priorityQueue.push(Gems[List_Gem++].price);

		if (!priorityQueue.empty())
		{
			StealedMoney += priorityQueue.top();
			priorityQueue.pop();
		}
	}

	cout << StealedMoney;
	delete[] Gems;
	delete[] BagList;
	return 0;
}
