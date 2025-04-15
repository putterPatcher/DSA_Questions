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

    void slice_array(int *arr, int *arr_new,int start,int end) {
        int index = 0;
        for (int i=start;i<end;i++) {
            arr_new[index] = arr[i];
            index += 1;
        };
    };


    void merge_sort(int *arr, int length) {
        int mid = length/2;
        if (mid == 1) {
            if (length == 2) {
                if (arr[0] > arr[1]) {
                    int temp = arr[0];
                    arr[0] = arr[1];
                    arr[1] = temp;
                } 
            }
            if (length == 3) {
                if (arr[0] > arr[2]) {
                    int temp = arr[0];
                    arr[0] = arr[2];
                    arr[2] = temp;
                } 
                if (arr[0] > arr[1]) {
                    int temp = arr[0];
                    arr[0] = arr[1];
                    arr[1] = temp;
                } 
                if (arr[2] < arr[1]) {
                    int temp = arr[2];
                    arr[2] = arr[1];
                    arr[1] = temp;
                }
            }
        }
        else {
            int len_arr1 = mid;
            int len_arr2 = length - mid;
            int *arr1 = malloc(len_arr1*sizeof(int));
            slice_array(arr, arr1, 0, mid);
            int *arr2 = malloc(len_arr2*sizeof(int));
            slice_array(arr, arr2, mid, length);
            merge_sort(arr1, len_arr1);
            merge_sort(arr2, len_arr2);
            int p1 = 0;
            int p2 = 0;
            int start = 0;
            while (p1 < len_arr1 && p2 < len_arr2) {
                if (arr1[p1] > arr2[p2]) {
                    arr[start] = arr2[p2];
                    p2+=1;
                    start+=1;
                }
                else {
                    arr[start] = arr1[p1];
                    p1+=1;
                    start+=1;
                }
            }
            while (p1 < len_arr1) {
                for (int i=start;i<length;i++) {
                    arr[start] = arr1[p1];
                    p1+=1;
                    start+=1;
                }
            }
            while (p2 < len_arr2) {
                for (int i=start;i<length;i++) {
                    arr[start] = arr2[p2];
                    p2+=1;
                    start+=1;
                }
            }
        }
    }

    merge_sort(nums, length);
    printf("Length: %d\n", length);
    for (int i=0;i<length;i++) {
        printf("%d\t", nums[i]);
    }
    printf("\n");
}