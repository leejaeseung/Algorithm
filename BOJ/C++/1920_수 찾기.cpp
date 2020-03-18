/*
	문제
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1≤M≤100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수들의 범위는 int 로 한다.

출력
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.
	풀이 :
	간단한 이분 탐색을 이용한 문제이다.
	함수를 int형으로 선언하는 바람에 재귀를 돌때마다 4바이트씩 잡아먹어 메모리 초과가 떠서 bool형으로 바꿔주었다.
	기수 정렬도 사용해봤으나 메모리 문제로 실패
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
//#include<string.h>
//#include<math.h>
#include<algorithm>

using namespace std;

int p = 10;
int k = 10;
int sizes;
int N, M;
int *arr;

//void Sort(unsigned int *arr);
bool BinarySearch( int num,int s,int e);

int main(void) {

	scanf("%d", &N);

	arr = (int*)malloc(sizeof(int)*N);
	
	for (int i = 0; i < N; i++)
	{
 		scanf("%d", &arr[i]);
	}
	sizes = N;
	sort(arr, arr + N);
	
	scanf("%d", &M);
	int find;
	for (int i = 0; i < M; i++)
	{
		scanf("%d",&find);
		if (BinarySearch(find, 0, sizes - 1) == true)
			printf("1\n");
		else
			printf("0\n");
	}
	free(arr);
	return 0;
}

bool BinarySearch(int num,int s,int e) {

	bool res;
	if (s > e) {
			return false;
	}
	else
	{
		if (arr[(s + e) / 2] > num) {
			res = BinarySearch(num, s, (s + e) / 2 - 1);
		}
		else if (arr[(s + e) / 2] < num) {
			res=BinarySearch(num, (s + e) / 2 + 1, e);
		}
		else {
			return true;
		}
	}
	return res;
}

/*void Sort(unsigned int *arr) {
	unsigned int *count, *temp;
	unsigned int pval,index;

	count = (unsigned int*)malloc(sizeof(unsigned int)*k);
	temp = (unsigned int*)malloc(sizeof(unsigned int)*sizes);

	for (int n = 0; n < p; n++)
	{
		for (int i = 0; i < k; i++) {
			count[i] = 0;
		}
		pval = (unsigned int)pow((double)k, (double)n);
		for (int i = 0; i < sizes; i++)
		{
			index = (unsigned int)(arr[i] / pval) % k;
			count[index] = count[index] + 1;
		}
		for (int i = 1; i < k; i++)
		{
			count[i] = count[i] + count[i - 1];
		}
		for (int i = sizes-1; i >= 0; i--)
		{
			index = (unsigned int)(arr[i] / pval) % k;
			temp[count[index] - 1] = arr[i];
			count[index] = count[index] - 1;
		}
		memcpy(arr, temp, sizes * sizeof(unsigned int));
	}
	free(count);
	free(temp);
}*/