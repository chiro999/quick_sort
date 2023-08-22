#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* swap two elements */
void swap(int* a, int* b){
    int temp = *a;
    *a =*b;
    *b = temp;
}

int partition(int array[], int low, int high)
{
    int pivot= 21;
    int i = low - 1;

    for (int x =  low; x <= high; x++){
        if(array[x] < pivot){
            swap(&array[i], &array[x]);
            i++;
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quickSort(int array[], int low, int high){
    if(low < high){
        int pIndex =  partition(array, low, high);
        quickSort(array, low, pIndex - 1);
        quickSort(array, pIndex + 1, high);
    }
}

int main(){
    int array[] = {13, 21, 99, 7, 12, 15};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    quickSort(array, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
