#include <stdio.h>

int binarysearch(int arr[], int size, int tar) {
    int low = 0;
    int high = size -1;

    while(low <= high) {
        int mid = low + (high - low)/2 ;

        if (arr[mid] == tar) {
            return mid;
        }

        if (arr[mid] < tar) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], tar, n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Which element you want to find from the array: ");
    scanf("%d", &tar);

    int ch = binarysearch(arr, n, tar);

    if (ch == -1) {
        printf("Element not found in the array\n");
    } else{
        printf("Element found at %d position\n", ch+1);
    }
    return 0;
}