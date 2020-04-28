#include "SORT.h"
void display(int arr[], int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap(int arr[],int start,int min){
	int tmp = arr[start];
	arr[start] = arr[min];
	arr[min] = tmp;
}
/*
	ʱ�临�Ӷȣ��ʱ�临�Ӷ�,����������ʱO(n^2)��ƽ�� O(n^2)�����O(n^2)
	�ռ临�Ӷȣ�O(1)
	�ȶ��ԣ��ȶ�
	�������жȣ�������
*/
void selectSort(int arr[], int len){
	for (int i = 0; i < len; i++){
		int start = i;
		int min = i;
		// ��ʣ���Ԫ��������Сֵ
		for (int j = start + 1; j < len; j++){
			if (arr[j] < arr[min])
				min = j;
		}
		if (min != i)
			swap( arr , i ,min);
	}
}
void select(int arr[], int len){
	for (int i = 0; i < len; i++){
		int cur = arr[i];
		int flag = i;
		for (int j = i + 1; j < len; j++){
			if (cur > arr[j]){
				cur = arr[j];
				flag = j;
			}
		}
		if (i != flag)
			swap(arr,i,flag);
	}
}
void testSelect(){
	srand((size_t)time(NULL));
	int num = 0;
	scanf("%d", &num);
	int* arr = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++){
		arr[i] = rand();
	}
	int begin = clock();
	select(arr, num);
	int end = clock();
	display(arr, num);
	printf("ѡ����������ʱ��Ϊ:>%d\n", end - begin);
	begin = clock();
	select(arr, num);
	end = clock();
	display(arr, num);
	printf("�ź���֮�����������ʱ��Ϊ:>%d\n", end - begin);
}
int main(){
	testSelect();
	//testShell();
	//testTime();
	//test();
	system("pause");
	return 0;
}