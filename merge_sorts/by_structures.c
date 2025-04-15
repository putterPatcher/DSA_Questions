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

    struct extra_struct {
        int value;
        bool last;
        struct extra_struct *next_struct;
    };

    void merge_sort(int* arr, int length, int start) {
        static struct extra_struct start_struct;
        static struct extra_struct* end_struct;
        end_struct = (struct extra_struct*)malloc(8);
        end_struct->last = true;
        start_struct.last = true;

        bool equal_struct()
        {
            return start_struct.last == false;
        }
        void add_struct(int value) {
            if (start_struct.last) {
                start_struct.next_struct = end_struct;
                start_struct.value = value;
                start_struct.last = false;
            } else {
                /*
                    Here we need to find a way to store the new end and preserve the old chain...
                */
                struct extra_struct *b = &start_struct;
                while (b->next_struct != end_struct) {
                    b = b->next_struct;
                };
                struct extra_struct *a;
                a = (struct extra_struct*)malloc(16);
                a->value = value;
                a->next_struct = end_struct;
                a->last = false;
                b->next_struct = a;
            }
        }

        int next_struct() {
            int value = start_struct.value;
            if (start_struct.next_struct != end_struct) {
                start_struct = *start_struct.next_struct;
            } else {
                start_struct.last = true;
            }
            return value;
        }

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
            while (p1 < mid && p2 < end) {
                if (equal_struct()) {
                    if (start_struct.value > arr[p2]) {
                        add_struct(arr[p1]);
                        arr[p1] = arr[p2];
                        p2 += 1;
                        p1 += 1;
                    } else {
                        add_struct(arr[p1]);
                        arr[p1] = next_struct();
                        p1 += 1;
                    }
                } else {
                    if (arr[p1] > arr[p2]) {
                        add_struct(arr[p1]);
                        arr[p1] = arr[p2];
                        p2 += 1;
                        p1 += 1;
                    } else {
                        p1 += 1;
                    }
                }
            }
            if (p2 == end && p1 < mid) {
                while (equal_struct()) {
                    arr[p1] = next_struct();
                    p1 += 1;
                }
            } else if (p1 == mid && p2 < end) {
                while (equal_struct() && p2 != end && p1 < p2) {
                    if (start_struct.value < arr[p2]) {
                        arr[p1] = next_struct();
                        p1 += 1;
                    } else {
                        arr[p1] = arr[p2];
                        p2 += 1;
                        p1 += 1;
                    }
                }
            }
            if (p2 == end) {
                while (p1 < end && equal_struct()) {
                    arr[p1] = next_struct();
                    p1 += 1;
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