/*
최대 회의 갯수를 갖는 방법을 찾기 위해선 여러가지가 있었고 대부분 내가 구현하기가 힘들고 논리적으로 생각할것이 많아서 첫 접근에 힘들었다.
그 후, 정답을 보면서 첫번째 시작하는 것중에서 가장 종료시간이 빠른것을 선택한후 그 다음 종료시간이 빠른것을 선택해 최대 회의 갯수를 찾는다.

왜 종료시간이 가장 빠른것을 선택하는지 그 이유가 합당함을 보이기 위해 다른 접근방법을 말하자면
첫째로 시작시간이 빠른것을 선택하면 종료시간이 가장 늦을수도 있는 경우가 있어 최대 회의 갯수 찾기에는 부적합하다.
둘째로 회의 시간을 계산하여 가장 짧은것끼리 비교하는건데 이는 긴 회의가 연속적으로있다고 가정할때 그 긴회의들의 시작과 종료 간격에 걸쳐지는 회의가 있다고 하면 필연적으로 짧은회의가 하나쯤은 더 적어질수밖에 없다.
따라서 첫쨰, 둘쨰의 반례를 종료시간이 가장 빠른것을 선택하는것은 구해낼수 있기에 이에 합당하다고 생각했다.

이를 현재에 최선의 선택을하여 후 미래의 결과도 좋아질것을 기대하는 그리디 알고리즘이라고 한다.

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
