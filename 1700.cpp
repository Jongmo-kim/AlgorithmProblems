#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool IsAllPluged(int* Multitap,int MultitapSize)
{
	for (int List_i = 0; List_i < MultitapSize; ++List_i)
	{
		if (Multitap[List_i] == 0)//만약 인수중하나가 0이라면 즉 꽂혀있지 않다면
			return false;
	}
	return true;//루프를 다돌고 꽂혀있는게 없으므로 
}
int FindUsingPlug(int* Multitap, int FindNum, int MultitapSize)
{

}
int FindLastUsedPlug(int* Multitap, const vector<int>& Order,int first,int MultitapSize)
{
	int LastUsedIndex=0;//플러그중 두개이상이 안쓰일 경우를 위해 루프 밖에서 선언
	bool* ptr = new bool[MultitapSize];
	for (int List_i = 0; List_i < MultitapSize; ++List_i)
		ptr[List_i] = false;//먼저 사용하는것을 true로 만들고 제일 나중에 사용하는걸 false로 만들기 위해 false로 초기화
	for (int List_i = first + 1; List_i < MultitapSize; ++List_i)//first+1부터 검색시작
	{
		int index=FindUsingPlug(Multitap, Order[List_i], MultitapSize);
		ptr[index] = true;
		LastUsedIndex = -1;// 예외상황 확인을 위해 -1로 초기화
		int count=0;
		for (int Just_j = 0; Just_j < MultitapSize; ++Just_j)//bool 배열중 1개이상의 false가 있는지 확인하는 루프
		{
			if (ptr[Just_j] == false)
			{
				LastUsedIndex = Just_j;
				if (count++ == 2)//2개이상의 false가 있으면 값을 못찾았으므로 루프 종료
					break;
			}
		}
		if (count == 1)//count가 1로 위의 Just루프가 종료되었다면 이는 1개의 값만이 false이고 이는 제일 나중에 사용되는걸 의미하므로
		{
			delete[] ptr; //동적할당된 메모리 초기화
			return LastUsedIndex;
		}
	}
	//만약 위의 루프에서 함수가 리턴되지 않았다면 사용순서중 2개이상이 플러그에서 안쓰인다는 얘기가 된다  그러므로 
	//LastUsedIndex를 리턴한다. 그안의 순서는 상관없다. 어차피 2개이상이 플러그에서 안쓰이므로 
	delete[] ptr; //동적할당된 메모리 초기화
	return LastUsedIndex;
}

void PlugCurrentNum(int* Multitap, int CurrentNum, int MultitapSize)
{

}
int main(void)
{
	int NumofHoles, FrequencyOfUse;
	vector<int> OrderOfUse;
	cin >> NumofHoles >> FrequencyOfUse;
	for (int List_i = 0; List_i < FrequencyOfUse; ++List_i)
	{
		int TempToPush;
		cin >> TempToPush;
		OrderOfUse.push_back(TempToPush);
	}//문제에서 제시한 입력 받기
	//멀티탭 구현
	int* Multitap = new int[NumofHoles];
	for (int List_i = 0; List_i < NumofHoles; List_i++)
		Multitap[List_i] = 0;//0(꽂혀있지 않음)으로 초기화

	//풀이 시작
	int PlugCount = 0;//플러그를 뽑은 횟수
	for (int List_i = 0; List_i < FrequencyOfUse; ++List_i)
	{
		if (FindUsingPlug(Multitap,OrderOfUse[List_i],NumofHoles))//현재 사용순서의 번호가 플러그에 꽂혀있는 상태면
		{
			continue;//루프의 끝으로 이동 
		}//이 아니고
		else if (IsAllPluged(Multitap,NumofHoles))//모든 플러그가 꽂혀있다면
		{
			int LastUsedPlug=FindLastUsedPlug(Multitap, OrderOfUse, List_i,NumofHoles);//가장 나중에 쓰이는 플러그 찾기.
			Multitap[LastUsedPlug] = OrderOfUse[List_i];//가장 나중에 쓰이는 플러그를 뽑고 지금 쓸 플러그를 꽂는다.
			++PlugCount; //플러그를 뽑았으므로 카운트 증가
		}
		else // 플러그가 안 혹은 덜 꽂혀있고 현재 사용순서의 번호가 플러그에 꽂혀있지 않다면
		{
			PlugCurrentNum(Multitap, OrderOfUse[List_i], NumofHoles);//플러그를 꽂는다.
		}
	} 
	//출력 구문
	cout << PlugCount;

	//프로그램 종료구문
	delete[] Multitap;
	return 0;
}