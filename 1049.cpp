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

	if (*Each.begin() * 6 <= *Set.begin()) //기타줄의 갯수가 세트의 가격보다 저렴하거나 같을때
	{
		cout << *Each.begin() * NumOfNeed;
		return 0;
	}
	else //통상적인경우 : 세트가 낱개로 사는것보다 저렴할때
	{

		Mod = NumOfNeed % 6; // 세트로 못사는 나머지 계산
		if (Mod * (*Each.begin()) < *Set.begin())// 나머지의 가격의 합이 세트의 가격보다 낮다면 즉 나머지는 낱개로 살때가 유리하면
		{
			cout << (Mod *static_cast<double>(*Each.begin())) + (floor((NumOfNeed / 6.0)+0.5)) * *Set.begin();//floor( ... +0.5) mod가 0일때 나누기 연산의 특성상 0.999..이 결과값으로 저장될수 잇어서 이를 타개하고자 0.5를 더해 내린다(=반올림)
		}
		else {//낱개로사는것보단 세트로 사는것이 유리하다면

			cout << (ceil(NumOfNeed / 6.0)) * (*Set.begin());
		}
		return 0;
	}
}