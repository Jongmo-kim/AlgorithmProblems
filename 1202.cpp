#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

/*
https://www.acmicpc.net/problem/1202
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.

상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다.
상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다.
가방에는 최대 한 개의 보석만 넣을 수 있다.

상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)

다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)

다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)

모든 숫자는 양의 정수이다.

//해결 방안
보석점에 보석이 N개 있다고 했을때  각 보석마다 무게와 가격이 있다.
상덕이는 가장 가격이 비싼 보석을 훔치고 싶으므로 가격을 기준으로 높은값부터 정렬한다.

그후, 상덕이는 자신의 가방들을 최대한 많은 무게를 버티는 가방을 낮은값으로 설정하여 정렬하자.
 그렇다면 가방의 열중 맨첫번째 있는 가방은 가장 적은 무게를 버틸것이다.

각각 정렬한 보석점에 있는 보석들과, 상덕이가 가진 가방들의 무게를 고려하여
무게를 버틴다면 그 다음 보석과, 그 다음 가방으로 넘어가서 진행하면 되겠다.

그렇게 진행한다면 상덕이가 벌수 있는 최대 가격이 나올것같다.

//틀린 이유
어떻게 진행 했는지 기억은 잘 나지 않지만 내 최후의 방법은
for문을 두개 사용하여 하나의 가방마다 맞는 보석들을 찾고 
찾았으면 다음 가방으로 넘어가서 다시 처음부터 하나씩 찾는 방법을 사용 했다.
하지만 첫시도에 시간초과가 떠서 실패했다.
결국 검색을해 해결했다.

//정답
https://dyngina.tistory.com/24
https://jaimemin.tistory.com/760
를 참고 했다.
priority_queue 우선순위 큐 라는 자료구조가 있다. 
이는 queue의 일종이긴한데 그것과 달리 값을 넣고 그값을 빼낼때 최소 혹은 최대부터 빠진다.
최대부터 빠지는것을 Max Heap 최소부터 빠지는것을 Min Heap이라고 한다.
단점이라하면 여태껏 넣은수들의 최대 혹은 최소밖에 모르는 단점이 있다.
같은 대략적인 내용을 찾았고
소스같은경우는 블로그를 참고하여 해결했다.
아직 자료구조에 익숙치 않아서 조금더 많은 공부가 필요하겠다.
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
	for (int List_Bag = 0; List_Bag < NumOfBag; ++List_Bag) // 가방을 다쓸때까지 반복
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
