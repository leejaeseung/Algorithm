/*
문제
Many Westerners think Korea is a mere Eastern country which hangs like a grapefruit next to China. However, Koreans have kept their unique ethnicity, struggling all the time not to be "a shrimp among whales"; Chinese to the west, Japanese to the east, "barbarian" tribes, and expanding Russia to the north. Bruce Cumings argued that a vast majority of Koreans look through the lens of race, thinking they have some essential quality making them and only them real Koreans, tracing a unique, homogeneous bloodline back some five thousand years, a story called Tan-gun mythology; 'Koreans do this, Koreans do that' in a shorthand. After a fratricidal war, it was divided into North and South Korea, creating Demilitarized Zone. South Korea had no friend in the region and became a de facto island. During the Cold War, Communist countries supported its enemy, North Korea, and Japan was the last candidate because of their colonial history. Its extremely low ethnic diversity(158th out of 159 countries; North Korea ranked 159th) and cultural diversity(152nd) is understandable given its experience of occupation and war.

Though the homogeneity of South Korea played a crucial role in the miracle of its economic development, it has also been a growing concern. A certain amount of diversity is necessary to encourage to understand different perspectives within the society and dispel negative stereotypes and personal biases about different groups. Learning about others helps to recognize and respect minorities, which we all are in some categories. Better understanding leads to the facilitation of collaboration and cooperation in the workplace.

The lack of other diversities left solely one inevitable diversity—gender—and called forth the recent fierce conflict between two traditional genders in South Korea, where only men are subject to two years of the savage conscription and its aftermath and women struggle with deeply imbued Confucianism, 37% of wage gap, and the paucity of sister politicians. Another recent case, Yemeni refugees, reveals a deeper nuance. In spite of the prevailing grievance over asylum seekers around the world, a polling estimates that between 49% and 56% of the general Korean population oppose granting asylum to the Yemeni refugees. But in a surprising result, the opposition among Korean youth in their 20s and 30s are considerably higher—70% and 60% respectively, despite the increased number of lawful foreigners in the country. The discord between men and women has contributed to avoiding marriage among youngsters, lowering overall fertility rate, a staggering figure of 0.96 in 2018. Now, for Koreans, embracing outsiders is not only a matter of morality or economic growth but also a matter of their survival in the future.

Jason, writing an essay about this issue, wants to exemplify the heterogeneity of the groups around him. You are asked to provide a program to calculate the heterogeneity of a group. He decided to use Gini-index. It is defined as, , where  is the relative frequency of class . Let's help him out.

입력
The class of an entity, , is given line by line. For all ,  consists only of alphabets and is case-sensitive, and its length is not longer than 10.

The number of entities, , is not greater than 100,000.

출력
Print Gini-index of the given group. Its relative error or absolute error must be less than .

풀이:
맵을 이요하여 풀이하였습니다.
새롭게 알게된 거 : 
1. 맵은 iterator로 for(auto& i) 를 통해 각 객체를 가져올 수 있다. i 에 pair가 담기게 됨.
2. cin의 EOF 처리 = while(cin >> s) 로 하면 EOF를 만나면 false를 반환한다.
*/
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>

map<string, double> m;
string str[100001];

int main(void) {
	FIO;

	int j = 0;
	double all = 0;
	
	while (cin >> str[j++]);

	for (int i = 0; i < j; i++)
	{
		if (str[i] == "")	continue;
		if (m.find(str[i]) == m.end()) 
			m.insert(make_pair(str[i], 1));
		else
			m[str[i]]++;
		all++;
	}
	double sum = 0;
	for (int i = 0; i < j; i++)
	{
		if (m[str[i]] == 0)	continue;
		if (m.find(str[i]) == m.end())	continue;

		sum = sum + pow((double)(m[str[i]] / all), (double)2);
		m[str[i]] = 0;
	}
	cout.precision(6);
	cout << 1.00 - sum;
}