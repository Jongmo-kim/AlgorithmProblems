/*
�ִ� ȸ�� ������ ���� ����� ã�� ���ؼ� ���������� �־��� ��κ� ���� �����ϱⰡ ����� �������� �����Ұ��� ���Ƽ� ù ���ٿ� �������.
�� ��, ������ ���鼭 ù��° �����ϴ� ���߿��� ���� ����ð��� �������� �������� �� ���� ����ð��� �������� ������ �ִ� ȸ�� ������ ã�´�.

�� ����ð��� ���� �������� �����ϴ��� �� ������ �մ����� ���̱� ���� �ٸ� ���ٹ���� �����ڸ�
ù°�� ���۽ð��� �������� �����ϸ� ����ð��� ���� �������� �ִ� ��찡 �־� �ִ� ȸ�� ���� ã�⿡�� �������ϴ�.
��°�� ȸ�� �ð��� ����Ͽ� ���� ª���ͳ��� ���ϴ°ǵ� �̴� �� ȸ�ǰ� �����������ִٰ� �����Ҷ� �� ��ȸ�ǵ��� ���۰� ���� ���ݿ� �������� ȸ�ǰ� �ִٰ� �ϸ� �ʿ������� ª��ȸ�ǰ� �ϳ����� �� ���������ۿ� ����.
���� ù��, �Ѥ��� �ݷʸ� ����ð��� ���� �������� �����ϴ°��� ���س��� �ֱ⿡ �̿� �մ��ϴٰ� �����ߴ�.

�̸� ���翡 �ּ��� �������Ͽ� �� �̷��� ����� ���������� ����ϴ� �׸��� �˰����̶�� �Ѵ�.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
/*namespace std {
	template <class T1, class T2>
	std::ostream& operator<<(std::ostream& out, const std::pair< T1, T2>& rhs)
	{
		out << "first: " << rhs.first << " second: " << rhs.second;
		return out;
	}
}*/
bool cmp(pair<int,int> f,pair<int, int> s)
{
	if (f.second == s.second)
		return f.first < s.first;
	else
		return f.second < s.second;
}
int main(void)
{
	vector<pair<int, int>> MeetingTimes;
	int NumberOfMeetings,TempToMeetingTimesStart,TempToMeetingTimesEnd,CountOfMeeting=0,TempToCalNextMeeting=0;
	cin >> NumberOfMeetings;
	for (int List_i = 0; List_i < NumberOfMeetings; List_i++)
	{
		cin >> TempToMeetingTimesStart;
		cin >> TempToMeetingTimesEnd;
		MeetingTimes.push_back(pair<int,int>(TempToMeetingTimesStart,TempToMeetingTimesEnd));
	}
	sort(MeetingTimes.begin(), MeetingTimes.end(), cmp);
	//copy(MeetingTimes.begin(), MeetingTimes.end(), ostream_iterator<pair<int,int>>(cout,"\n"));
	
	for (int List_i = 0; List_i < NumberOfMeetings; List_i++)
	{
		if (MeetingTimes[List_i].first>= TempToCalNextMeeting)
		{
			TempToCalNextMeeting = MeetingTimes[List_i].second;
			CountOfMeeting++;
		}
	}
	cout << CountOfMeeting;
	return 0; 
}
