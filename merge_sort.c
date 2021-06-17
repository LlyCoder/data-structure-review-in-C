// mergesort in C 

#include <stdio.h>
#define LEN 6

void merge_sort(int arr[], int start, int end);
void merge_list(int arr[], int start, int mid, int end);
void print_list(int arr[], int len);

int main() {
	
	int arr[] = {8, 21, 1, 98, 74, 16};
	merge_sort(arr, 0, 5);
	print_list(arr, LEN);
	
	return 0;
}

void merge_sort(int arr[], int start, int end) {
	//分治 
	int mid = (start + end) / 2;
	if (start >= end) return;         //start=end意味着当前线性表只有一个元素，无需排序，大于则约定错误 
	merge_sort(arr, start, mid);
	merge_sort(arr, mid+1, end);     //注意参数 
	merge_list(arr, start, mid, end); 
	
}

void merge_list(int arr[], int start, int mid, int end) {
	// 利用mid将该线性表分成两个线性表的顺序合并 
	int result[LEN];
	int i = start;
	int j = mid + 1;
	int k = 0;
	
    while(i<=mid && j<=end) {
	  if(arr[i] < arr[j]) {
	  	result[k++] = arr[i++];
	}
      else {
   		result[k++] = arr[j++];
   	}
				
	while(i<=mid) {
		result[k++] = arr[i++];
	} 
	while(j<=end) {
		result[k++] = arr[j++];
	}
	for(i=start,j=0; j<k; i++, j++) {
		arr[i] = result[j];
	}
 }
	
	 	
}
void print_list(int arr[], int len) { 
  int i;
  for(i=0; i<len; i++){
    printf("%d，", arr[i]);
  }
}