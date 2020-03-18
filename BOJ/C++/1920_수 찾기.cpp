/*
	����
N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N(1��N��100,000)�� �־�����. ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����. ���� �ٿ��� M(1��M��100,000)�� �־�����. ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�. ��� �������� ������ int �� �Ѵ�.

���
M���� �ٿ� ���� ����Ѵ�. �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.
	Ǯ�� :
	������ �̺� Ž���� �̿��� �����̴�.
	�Լ��� int������ �����ϴ� �ٶ��� ��͸� �������� 4����Ʈ�� ��ƸԾ� �޸� �ʰ��� ���� bool������ �ٲ��־���.
	��� ���ĵ� ����غ����� �޸� ������ ����
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