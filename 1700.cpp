#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool IsAllPluged(int* Multitap,int MultitapSize)
{
	for (int List_i = 0; List_i < MultitapSize; ++List_i)
	{
		if (Multitap[List_i] == 0)//���� �μ����ϳ��� 0�̶�� �� �������� �ʴٸ�
			return false;
	}
	return true;//������ �ٵ��� �����ִ°� �����Ƿ� 
}
int FindUsingPlug(int* Multitap, int FindNum, int MultitapSize)
{
	for (int List_i = 0; List_i < MultitapSize; ++List_i)
	{
		if (Multitap[List_i] == FindNum)
			return List_i;//�����ÿ� �ش� index���� List_i����
	}
	return -1;//�����ÿ� -1 ����
}
int FindLastUsedPlug(int* Multitap, const vector<int>& Order,int first,int MultitapSize,int FrequencyOfUse)
{
	int LastUsedIndex=0,count=MultitapSize;
	bool* ptr = new bool[MultitapSize];
	for (int List_i = 0; List_i < MultitapSize; ++List_i)
		ptr[List_i] = false;//���� ����ϴ°��� true�� ����� ���� ���߿� ����ϴ°� false�� ����� ���� false�� �ʱ�ȭ
	for (int List_i = first+1 ; List_i < FrequencyOfUse; ++List_i)//first+1���� �˻�����
	{
		int index = FindUsingPlug(Multitap, Order[List_i], MultitapSize);
		if (index == -1) //ã�°��� ������ ������ ������ �̵�
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

	//�� �Լ��� ��� �÷��װ� ��Ƽ�ǿ� �����ִ°��� �����ϹǷ� ������ � �ε������� �ϳ��� �����ؾ��Ѵ�.
	delete[] ptr; //�����Ҵ�� �޸� �ʱ�ȭ
	return LastUsedIndex;
}

void PlugCurrentNum(int* Multitap, int CurrentNum, int MultitapSize)
{
	for (int List_i = 0; List_i < MultitapSize; ++List_i)
	{
		if (Multitap[List_i] == 0)
		{
			Multitap[List_i] = CurrentNum;
			break; //�Ǽ��� �κ� break�� ���ϸ� ���δ� ���� �÷��׷� ��������� ���۵��� ����Ų��.
		}
	}
}
int main(void)
{
	//------------------------------------------------------------------------------------------------------------------
	//�������� ������ �Է¹ޱ�
	int NumofHoles, FrequencyOfUse;
	vector<int> OrderOfUse;
	cin >> NumofHoles >> FrequencyOfUse;
	for (int List_i = 0; List_i < FrequencyOfUse; ++List_i)
	{
		int TempToPush;
		cin >> TempToPush;
		OrderOfUse.push_back(TempToPush);
	}
	//��Ƽ�� ����
	int* Multitap = new int[NumofHoles];
	for (int List_i = 0; List_i < NumofHoles; List_i++)
		Multitap[List_i] = 0;//0(�������� ����)���� �ʱ�ȭ

	//------------------------------------------------------------------------------------------------------------------
	//Ǯ�� ����
	int PlugCount = 0;//�÷��׸� ���� Ƚ��
	for (int List_i = 0; List_i < FrequencyOfUse; ++List_i)
	{
		cout << List_i << "ȸ��-------------------------------------------------\n";
		if (FindUsingPlug(Multitap,OrderOfUse[List_i],NumofHoles)!=-1)//���� �������� ��ȣ�� �÷��׿� �����ִ� ���¸�
		{
			cout << "FindUsingPlug\n";
			for (int Just_j = 0; Just_j < NumofHoles; Just_j++)
			{
				cout << "Multitap[" << Just_j << "] : " << Multitap[Just_j]<<endl;
			}
			cout << "PlugCount : " << PlugCount << endl;
			continue;//������ ������ �̵� 
		}//�� �ƴϰ�
		else if (IsAllPluged(Multitap,NumofHoles))//��� �÷��װ� �����ִٸ�
		{
			cout << "IsAllPluged" << endl;
			int LastUsedPlug=FindLastUsedPlug(Multitap, OrderOfUse, List_i,NumofHoles,FrequencyOfUse);//���� ���߿� ���̴� �÷��� ã��.
			Multitap[LastUsedPlug] = OrderOfUse[List_i];//���� ���߿� ���̴� �÷��׸� �̰� ���� �� �÷��׸� �ȴ´�.
			++PlugCount; //�÷��׸� �̾����Ƿ� ī��Ʈ ����
		}
		else // �÷��װ� �� Ȥ�� �� �����ְ� ���� �������� ��ȣ�� �÷��׿� �������� �ʴٸ�
		{
			PlugCurrentNum(Multitap, OrderOfUse[List_i], NumofHoles);//�÷��׸� �ȴ´�.
		}
		for (int Just_j = 0; Just_j < NumofHoles; Just_j++)
		{
			cout << "Multitap[" << Just_j << "] : " << Multitap[Just_j] << endl;
		}
		cout << "PlugCount : " << PlugCount << endl;
	} 
	//------------------------------------------------------------------------------------------------------------------
	//��� ����
	cout << PlugCount;

	//���α׷� ���ᱸ��
	delete[] Multitap;
	return 0;
}