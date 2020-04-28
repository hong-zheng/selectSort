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
	时间复杂度：最坏时间复杂度,当数据逆序时O(n^2)；平均 O(n^2)；最好O(n^2)
	空间复杂度：O(1)
	稳定性：稳定
	数据敏感度：不敏感
*/
void selectSort(int arr[], int len){
	for (int i = 0; i < len; i++){
		int start = i;
		int min = i;
		// 从剩余的元素中找最小值
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
	printf("选择排序所费时间为:>%d\n", end - begin);
	begin = clock();
	select(arr, num);
	end = clock();
	display(arr, num);
	printf("排好序之后的再排所费时间为:>%d\n", end - begin);
}
int main(){
	testSelect();
	//testShell();
	//testTime();
	//test();
	system("pause");
	return 0;
}