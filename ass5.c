#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int sml = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[sml]) {
        sml = left;
    }

    if (right < n && arr[right] < arr[sml]) {
        sml = right;
    }

    if (sml != i) {
        swap(&arr[i], &arr[sml]);
        heapify(arr, n, sml);
    }
}

void insert(int arr[], int *n, int value) {
    if (*n >= 100) {
        printf("Heap is full.\n");
        return;
    }

    int i = (*n)++;
    arr[i] = value;

    while (i > 0 && arr[i] < arr[(i - 1) / 2]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int deleteMin(int arr[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int minVal = arr[0];
    arr[0] = arr[--(*n)];
    heapify(arr, *n, 0);

    return minVal;
}

void printHeap(int arr[], int n) {
    printf("Min Heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); 
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[50];
    int n = 0;
    
    printf("elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    printHeap(arr, n);

    int minVal = deleteMin(arr, &n);
    if (minVal != -1) {
        printf("Deleted element: %d\n", minVal);
        printHeap(arr, n);
    }
      heapSort(arr, n);

    printf("Sorted array: ");
    printHeap(arr, n);


    return 0;
}







// Q2

// #include <stdio.h>
// #include <stdlib.h>
// void swap(int *a, int *b)
// {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }
// int head[11];
// void heapify(int arr[], int n)
// {
//     for (int i = n - 1; i > 0; i--)
//     {
//         if (i == 1)
//         {
//             if (arr[0] > arr[1])
//             {
//                 swap(&arr[1], &arr[0]);
//                 continue;
//             }
//         }
//         if (i & 1)
//         {
//             if (arr[i] < arr[(i - 2) / 2])
//             {
//                 swap(&arr[i], &arr[(i - 2) / 2]);
//             }
//         }
//         else
//         {
//             if (arr[i] < arr[(i - 1) / 2])
//             {
//                 swap(&arr[i], &arr[(i - 1) / 2]);
//             }
//         }
//     }
// }

// void deleteMin(int arr[], int n)
// {
//     int last = arr[n - 1];
//     arr[0] = last;
//     n = n - 1;
//     heapifyMax(arr, n);
// }

// void fun(int arr[], int n, int final[])
// {
//     int last = arr[n - 1];
//     final[n - 1] = arr[0];
//     arr[n - 1] = arr[0];
//     arr[0] = last;
//     n = n - 1;
//     heapifyMax(arr, n);
// }

// void heapsort(int arr[], int n)
// {
//     if (n == 0)
//     {

//         return;
//     }
//     int final[n];

//     fun(arr, n, final);
//     n = n - 1;
//     heapsort(arr, n);
// }

// void heapifyMax(int arr[], int n)
// {
//     for (int i = n - 1; i > 0; i--)
//     {
//         if (i == 1)
//         {
//             if (arr[0] < arr[1])
//             {
//                 swap(&arr[1], &arr[0]);
//                 continue;
//             }
//         }
//         if (i & 1)
//         {
//             if (arr[i] > arr[(i - 2) / 2])
//             {
//                 swap(&arr[i], &arr[(i - 2) / 2]);
//             }
//         }
//         else
//         {
//             if (arr[i] > arr[(i - 1) / 2])
//             {
//                 swap(&arr[i], &arr[(i - 1) / 2]);
//             }
//         }
//     }
// }

// int main()
// {

//     int head[7] = {3, 5, 6, 8, 9, 7, 1};
//      heapifyMax(head, 7);
//     printf("termination\n");
//     for (int i = 0; i < 7; i++)
//     {
//         printf("%d ", head[i]);
//     }
//     printf("\n");
//      deleteMin(head,7);

//     for(int i=0;i<6;i++){
//      printf("%d ",head[i]);
//     }
// printf("\n");

//     for (int i = 0; i < 7; i++)
//     {
//         printf("%d ", head[i]);
//     }
// }

