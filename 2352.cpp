/*
문제에 처음 접근했을때 여러가지 경우의 수를 생각하느라 힘을 다썻다.
결론적으로 문제에서 요구한 포트를 최대한 많이 구하는 방법은 입력받은 숫자들의 최장 증가 길이 배열을 구함에 따라 나온다 
왜인지 설명하기 위해서 몇가지 설명하자면 문제에서 제공한 이미지를 보면 왼쪽포트와 오른쪽 포트가 있고 왼쪽은 내림차순으로 쭉 정렬되어 있지만,
오른쪽은 무작위로 나오고 있다.
여기서 포트의 개수만 요구하는 문제의 조건에 따라 오른쪽 포트의 번호들이 작은값에서 큰값으로 연속적으로 커지는 배열이 있는 경우가 바로 포트가 꼬이지 않는 부분이 되겠다.
큰값에서 작은값으로 작아진다면 이는 최대한 많이 겹쳐지게 되는 경우가 되고 왜 그렇게 되냐고 한다면
1-4가 꼽힌다고 했을때 그다음의 경우는 2-1 2-2 2-3 2-4 가 나올수 없게된다 2-1~2-3은 겹치기떄문이고 2-4는 포트가 이미 사용중인 상태이기 때문.
따라서 최장 부분 배열을 구하는것이 포트를 최대한 많이 꼽을수 있게 되겠다.

소스는 간단하다. 여러가지 사이트를 찾은 결과를 요약하자면
LIS (Longest Increasing Subsquence)를 찾을때 3가지 정도의 방법이 있는데
첫째는 이중루프를 사용해서 현재 내가 찾고 있는 값과 그이전의 값들을 모두 비교하는 식으로 검사하여 LIS를 찾는것이고
둘째는 하나의 루프와 이중탐색 알고리즘을 사용하는건데, c++에서 제공되는 lower_bound를 이용한다. 배열에서 찾는값이 없으면 찾는값보다 첫번째로 작은걸 선택해 리턴한다.
이중탐색으로 조사하므로 logn의 시간이 걸린다. 그래서 원래의 컸던 값을 그값으로 대체하여 저장한다.
만약 배열에서 제일 큰값이라면 이는 연속적이라는 뜻 이므로 맨뒤에 그 값을 추가한다.
그래서 해당배열의 사이즈가 곧 최대증가수열이다.

셋째는 인덱스 어찌고 방법인데 수열에 대한 정보도 같이 저장하는 방식인데 아직 잘은 모른다.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


int main(void)
{
	int N,TempToPushBack;
	vector<int> v; //조사표
	cin >> N;
	for (int List_i = 0; List_i < N; List_i++)
	{
		cin >> TempToPushBack;
		
		int idx = lower_bound(v.begin(), v.end(), TempToPushBack)-v.begin();//idx를 구한다 v.begin()을 뺴는 이유는 stl countainer의 특성상 v.begin() 을 뺴야하기 떄문.
		
		if (idx == v.size())
			v.push_back(TempToPushBack);
		else
			v[idx] = TempToPushBack;

	}

	cout << v.size();
	return 0;
}