#include <stdio.h>

int min(int x, int y) {
    return (x <= y) ? x : y;
}

int fibonacciSearch(int arr[], int x, int n) {
    int fib2 = 0;   // (m-2)'th Fibonacci Number
    int fib1 = 1;   // (m-1)'th Fibonacci Number
    int fibM = fib2 + fib1;  // m'th Fibonacci Number
    
    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }
    
    int offset = -1;
    
    while (fibM > 1) {
        int i = min(offset + fib2, n-1);
        
        if (arr[i] < x) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        }
        else if (arr[i] > x) {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        }
        else {
            return i;
        }
    }
    
    if (fib1 && arr[offset + 1] == x) {
        return offset + 1;
    }
    
    return -1;
}

int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 85;
    
    int ind = fibonacciSearch(arr, x, n);
    if (ind >= 0) {
        printf("Found at index: %d\n", ind);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}