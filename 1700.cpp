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
	for (int List_i = 0; List_i < MultitapSize; ++List_i)
	{
		if (Multitap[List_i] == FindNum)
			return List_i;//있을시에 해당 index값인 List_i리턴
	}
	return -1;//없을시에 -1 리턴
}
int FindLastUsedPlug(int* Multitap, const vector<int>& Order,int first,int MultitapSize,int FrequencyOfUse)
{
	int LastUsedIndex=0,count=MultitapSize;
	bool* ptr = new bool[MultitapSize];
	for (int List_i = 0; List_i < MultitapSize; ++List_i)
		ptr[List_i] = false;//먼저 사용하는것을 true로 만들고 제일 나중에 사용하는걸 false로 만들기 위해 false로 초기화
	for (int List_i = first+1 ; List_i < FrequencyOfUse; ++List_i)//first+1부터 검색시작
	{
		int index = FindUsingPlug(Multitap, Order[List_i], MultitapSize);
		if (index == -1) //찾는값이 없을시 루프의 끝으로 이동
			continue;
		if (!ptr[index])
		{
			ptr[index] = true;
			count--;
		}
		for (int Just_j = 0; Just_j < MultitapSize; ++Just_j)
		{
			if(ptr[Just_j]==false)
				LastUsedIndex=Just_j;
		}
		
		for (int Just_j = 0; Just_j < MultitapSize; ++Just_j)
			cout << "bool[" << Just_j << "] : " << ptr[Just_j] << endl;
		cout<<"Count : " << count << endl;
		if (count == 1)
		{
			for (int Just_j = 0; Just_j < MultitapSize; ++Just_j)
				if (ptr[Just_j] == false)
					return Just_j;
		}
	}

	//이 함수는 모든 플러그가 멀티탭에 꽂혀있는것을 상정하므로 무조건 어떤 인덱스값중 하나를 리턴해야한다.
	delete[] ptr; //동적할당된 메모리 초기화
	return LastUsedIndex;
}

void PlugCurrentNum(int* Multitap, int CurrentNum, int MultitapSize)
{
	for (int List_i = 0; List_i < MultitapSize; ++List_i)
	{
		if (Multitap[List_i] == 0)
		{
			Multitap[List_i] = CurrentNum;
			break; //실수한 부분 break를 안하면 전부다 같은 플러그로 덮어씌어져서 오작동을 일으킨다.
		}
	}
}
int main(void)
{
	//------------------------------------------------------------------------------------------------------------------
	//문제에서 제시한 입력받기
	int NumofHoles, FrequencyOfUse;
	vector<int> OrderOfUse;
	cin >> NumofHoles >> FrequencyOfUse;
	for (int List_i = 0; List_i < FrequencyOfUse; ++List_i)
	{
		int TempToPush;
		cin >> TempToPush;
		OrderOfUse.push_back(TempToPush);
	}
	//멀티탭 구현
	int* Multitap = new int[NumofHoles];
	for (int List_i = 0; List_i < NumofHoles; List_i++)
		Multitap[List_i] = 0;//0(꽂혀있지 않음)으로 초기화

	//------------------------------------------------------------------------------------------------------------------
	//풀이 시작
	int PlugCount = 0;//플러그를 뽑은 횟수
	for (int List_i = 0; List_i < FrequencyOfUse; ++List_i)
	{
		cout << List_i << "회차-------------------------------------------------\n";
		if (FindUsingPlug(Multitap,OrderOfUse[List_i],NumofHoles)!=-1)//현재 사용순서의 번호가 플러그에 꽂혀있는 상태면
		{
			cout << "FindUsingPlug\n";
			for (int Just_j = 0; Just_j < NumofHoles; Just_j++)
			{
				cout << "Multitap[" << Just_j << "] : " << Multitap[Just_j]<<endl;
			}
			cout << "PlugCount : " << PlugCount << endl;
			continue;//루프의 끝으로 이동 
		}//이 아니고
		else if (IsAllPluged(Multitap,NumofHoles))//모든 플러그가 꽂혀있다면
		{
			cout << "IsAllPluged" << endl;
			int LastUsedPlug=FindLastUsedPlug(Multitap, OrderOfUse, List_i,NumofHoles,FrequencyOfUse);//가장 나중에 쓰이는 플러그 찾기.
			Multitap[LastUsedPlug] = OrderOfUse[List_i];//가장 나중에 쓰이는 플러그를 뽑고 지금 쓸 플러그를 꽂는다.
			++PlugCount; //플러그를 뽑았으므로 카운트 증가
		}
		else // 플러그가 안 혹은 덜 꽂혀있고 현재 사용순서의 번호가 플러그에 꽂혀있지 않다면
		{
			PlugCurrentNum(Multitap, OrderOfUse[List_i], NumofHoles);//플러그를 꽂는다.
		}
		for (int Just_j = 0; Just_j < NumofHoles; Just_j++)
		{
			cout << "Multitap[" << Just_j << "] : " << Multitap[Just_j] << endl;
		}
		cout << "PlugCount : " << PlugCount << endl;
	} 
	//------------------------------------------------------------------------------------------------------------------
	//출력 구문
	cout << PlugCount;

	//프로그램 종료구문
	delete[] Multitap;
	return 0;
}