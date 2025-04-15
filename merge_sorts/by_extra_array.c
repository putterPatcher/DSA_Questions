#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void main () {
    int size;
    scanf("%d", &size);
	int *nums = malloc(size*sizeof(int));
	for (int i=0;i<size;i++) {
		printf("Enter integer (%d): ",i);
		scanf("%d",&nums[i]);
	};

	for (int i=0;i<size;i++) {
		printf("%d ",nums[i]);
	};
	printf("\n");

	static int length;

	length = size;

    int *ret = malloc(length*sizeof(int));
    void merge_sort(int* arr, int length, int start) {
        int mid = (start+length/2);
        int m = length / 2;
        if (m == 1) {
            if (length == 2) {
                int index_2 = start+1;
                if (arr[start] > arr[index_2]) {
                    int temp = arr[start];
                    arr[start] = arr[index_2];
                    arr[index_2] = temp;
                }
            }
            if (length == 3) {
                int index_1 = start + 1;
                int index_2 = start + 2;
                if (arr[start] > arr[index_2]) {
                    int temp = arr[start];
                    arr[start] = arr[index_2];
                    arr[index_2] = temp;
                }
                if (arr[start] > arr[index_1]) {
                    int temp = arr[start];
                    arr[start] = arr[index_1];
                    arr[index_1] = temp;
                }
                if (arr[index_2] < arr[index_1]) {
                    int temp = arr[index_2];
                    arr[index_2] = arr[index_1];
                    arr[index_1] = temp;
                }
            }
        } else {
            int len_arr1 = m;
            int len_arr2 = length - m;
            merge_sort(arr, len_arr1, start);
            merge_sort(arr, len_arr2, mid);
            int end = start+length;
            int p1 = start;
            int p2 = mid;
            int s = start;
            int start = 0;
            int *merged_array = malloc(length*sizeof(int));
            while (p1 < mid && p2 < end) {
                if (arr[p1] > arr[p2]) {
                    merged_array[start] = arr[p2];
                    p2 += 1;
                    start += 1;
                } else {
                    merged_array[start] = arr[p1];
                    p1 += 1;
                    start += 1;
                }
            }
            while (p1 < mid) {
                for (int i = start; i < length; i++) {
                    merged_array[start] = arr[p1];
                    p1 += 1;
                    start += 1;
                }
            }
            while (p2 < end) {
                for (int i = start; i < length; i++) {
                    merged_array[start] = arr[p2];
                    p2 += 1;
                    start += 1;
                }
            }
            start = 0;
            for (int i=s;i<s+length;i++) {
                arr[i] = merged_array[start];
                start+=1;
            }
        }
    }

    merge_sort(nums, length, 0);
    printf("Length: %d\n", length);
    for (int i=0;i<length;i++) {
        printf("%d\t", nums[i]);
    }
    printf("\n");
}