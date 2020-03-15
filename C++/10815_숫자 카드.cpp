/*
	1920번과 같은 문제-이분탐색
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<algorithm>

int N, M;

using namespace std;

bool BinarySearch(int *arr,int num,int s,int e);

int main(void) {
	
	scanf("%d", &N);

	int *arr = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);

	scanf("%d", &M);
	int find;
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &find);
		if (BinarySearch(arr, find, 0, N-1 ) == true)
			printf("1 ");
		else
			printf("0 ");
	}
}

bool BinarySearch(int *arr, int num, int s, int e) {
	int mid = (s + e) / 2;

	bool res;
	if (s > e) {
		return false;
	}
	else
	{
		if (arr[mid] > num) {
			res = BinarySearch(arr, num, s, mid-1);
		}
		else if (arr[mid] < num) {
			res = BinarySearch(arr, num, mid+1, e);
		}
		else {
			return true;
		}
	}
	return res;
}

int sort() {
	for  (int  = 0; i < n; i++)
	{

	}
}