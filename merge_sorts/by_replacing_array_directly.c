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

    void merge_sort(int* arr, int length, int start) {
        int mid = (start + length / 2);
        int m = length / 2;
        if (m == 1) {
            if (length == 2) {
                int index_2 = start + 1;
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
            int end = start + length;
            int p1 = start;
            int p2 = mid;
            int start = 0;
            int* merged_array = malloc(len_arr1 * sizeof(int));
            int max_index = -1;
            int min_index = 0;
            while (p1 < mid && p2 < end) {
                if (max_index > -1 && max_index >= min_index) {
                    if (merged_array[min_index] > arr[p2]) {
                        max_index += 1;
                        merged_array[max_index] = arr[p1];
                        arr[p1] = arr[p2];
                        p2 += 1;
                        p1 += 1;
                    } else {
                        max_index += 1;
                        merged_array[max_index] = arr[p1];
                        arr[p1] = merged_array[min_index];
                        min_index += 1;
                        p1 += 1;
                    }
                } else {
                    if (arr[p1] > arr[p2]) {
                        max_index += 1;
                        merged_array[max_index] = arr[p1];
                        arr[p1] = arr[p2];
                        p2 += 1;
                        p1 += 1;
                    } else {
                        p1 += 1;
                    }
                }
            }
            if (p2 == end && p1 < mid) {
                for (int i = 0; i <= max_index; i++) {
                    arr[p1] = merged_array[i];
                    p1 += 1;
                }
            } else if (p1 == mid && p2 < end) {
                while (min_index <= max_index && p2 != end && p1 < p2) {
                    if (merged_array[min_index] < arr[p2]) {
                        arr[p1] = merged_array[min_index];
                        min_index += 1;
                        p1 += 1;
                    } else {
                        arr[p1] = arr[p2];
                        p2 += 1;
                        p1 += 1;
                    }
                }
            }
            if (p2 == end && min_index <= max_index) {
                while (p1 < end) {
                    arr[p1] = merged_array[min_index];
                    p1 += 1;
                    min_index += 1;
                };
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