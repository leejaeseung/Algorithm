#include<iostream>
#include<algorithm>
#include<deque>
#include<utility>
using namespace std;

int N, M;
pair<int, int> bus[101];
deque<pair< int, int> > dq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int t, p;
		cin >> t >> p;

		bus[i] = make_pair(t, p);
	}

	int time = 0;
	int station = 0;
	int idx = 0;
	int answer = 0;

	for (int time = 0; time < 1000; time++)
	{
		while (!dq.empty() && dq.back().first <= time) {
			if (idx == M)
				answer = dq.back().second;
			dq.pop_back();
		}
		if (dq.empty()) {
			station = 0;
		}
		while (dq.size() < N && bus[idx].first <= time && idx < M && station < N) {
			station++;
			dq.push_front(make_pair(time + bus[idx++].second, station));
		}
	}

	cout << answer;
}