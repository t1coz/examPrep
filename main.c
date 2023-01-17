#include <stdio.h>
//void swap(int *x, int *y){
//    int temp = *x;
//    *x = *y;
//    *y = temp;
//}
//int partitionForQS(int arr[], int low, int high){
//    int pivotValue = arr[high];
//    int i = low;
//    for(int j = low; j<high;j++){
//        if(arr[j]<=pivotValue){
//            swap(&arr[i], &arr[j]);
//            i++;
//        }
//    }
//    swap(&arr[i], &arr[high]);
//    return i;
//}
//void qSRecursion(int arr[], int low, int high){
//    if(low<high){
//        int pivotIndex = partitionForQS(arr, low, high);
//        qSRecursion(arr, low, pivotIndex-1);
//        qSRecursion(arr, pivotIndex+1, high);
//    }
//}
//void quickSort(int n, int arr[]){
//    qSRecursion(arr, 0, n-1);
//}
//void mergeSortedArrays(int arr[], int l, int m, int r){
//    int leftLength = m-l+1;
//    int rightLength = r-m;
//    int rightT[rightLength], leftT[leftLength];
//    int i, j, k;
//    for(i = 0; i<leftLength; i++){
//        leftT[i] = arr[l+i];
//    }
//    for(i=0; i<rightLength; i++){
//        rightT[i] = arr[m+1+i];
//    }
//    for(i = 0, j = 0, k=l; k<=r; k++){
//        if(i<leftLength && ((j>=rightLength)||(leftT[i]<rightT[j]))){
//            arr[k] = leftT[i];
//            i++;
//        }else{
//            arr[k] = rightT[j];
//            j++;
//        }
//    }
//}
//void mergeSortRecursion(int arr[], int l, int r){
//    if(l<r){
//        int m = (l+r-1)/2;
//        mergeSortRecursion(arr, l, m);
//        mergeSortRecursion(arr, m+1, r);
//        mergeSortedArrays(arr, l, m, r);
//    }
//}
//void mergeSort(int n, int arr[]){
//    mergeSortRecursion(arr, 0, n-1);
//}
//void shellFromPres(int n, int arr[]){
//    int flag, temp;
//    for(int gap = n/2; gap>0; gap/=2){
//        do{
//            flag = 0;
//            for(int i = 0, j = gap; j<n;j++,i++){
//                if(arr[i]> arr[j]){
//                    temp = arr[i];
//                    arr[i] = arr[j];
//                    arr[j] = temp;
//                    flag = 1;
//                }
//            }
//        }while(flag);
//    }
//}
//void insertionSort(int n, int arr[]){
//    for(int i = 1; i < n; i++){
//        int value = arr[i];
//        int j = i-1;
//        while(j>=0 && arr[j]>value){
//            arr[j+1] = arr[j];
//            j--;
//        }
//        arr[j+1] = value;
//    }
//}
//1 4 8 3 5 0
//void selectionSort(int n, int arr[]){
//    int temp;
//    for(int i = 0; i < n-1; i++){
//        int minPos = i;
//        for(int j = i+1; j<n;j++){
//            if(arr[j]<arr[i]){
//                minPos = j;
//            }
//        }
//        if(minPos!=i){
//            temp = arr[i];
//            arr[i] = arr[minPos];
//            arr[minPos]= temp;
//        }
//    }
//}
//void BubbleSort(int n, int arr[]){
//    int temp;
//    for(int i = 0; i< n; i++){
//        for(int j = 0; j<n-1; j++){
//            if(arr[j]>arr[j+1]){
//                temp = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = temp;
//            }
//        }
//    }
//}
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int low, int high){
    int pivotValue = arr[high];
    int i = low;
    for(int j = low; j<high; j++){
        if(arr[j]<=pivotValue){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
void quickSortRecursion(int arr[], int low, int high){
    if(low<high){
        int pivotIndex = partition(arr, low, high);
        quickSortRecursion(arr, low, pivotIndex-1);
        quickSortRecursion(arr, pivotIndex+1, high);
    }
}
void quickSort(int arr[], int n){
    quickSortRecursion(arr, 0, n-1);
}
void mergeSortedArrays(int arr[], int l, int m, int r){
    int leftLength = m+1-l, rightLength = r-m;
    int tempLeft[leftLength], tempRight[rightLength];
    int i, j, k;
    for(i=0; i < leftLength; i++)
        tempLeft[i] = arr[i+l];
    for(i=0; i<rightLength; i++)
        tempRight[i] = arr[m+1+i];
    for(i=0, j=0, k=l; k<=r;k++){
        if(i<leftLength &&(j>=rightLength || tempLeft[i]<tempRight[j])){
            arr[k] = tempLeft[i];
            i++;
        }else{
            arr[k] = tempRight[j];
            j++;
        }
    }
}
void mergeSortRecursion(int arr[], int l, int r){
    if(l<r){
        int m = (l+r-1)/2;
        mergeSortRecursion(arr, l, m);
        mergeSortRecursion(arr, m+1, r);
        mergeSortedArrays(arr, l, m, r);
    }
}
void mergeSort(int arr[], int n){
    mergeSortRecursion(arr, 0, n-1);
}
void shellSort(int arr[], int n){
    int temp, flag;
    for(int gap = n/2; gap>0; gap/=2){
        do{
            flag = 0;
            for(int i = 0, j = gap; j<n; j++, i++){
                if(arr[i]>arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    flag = 1;
                }
            }
        }while(flag);
    }
}
void insertionSort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int value = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>value){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = value;
    }
}
void selectionSort(int arr[], int n){
    int temp;
    for(int i = 0; i<n-1; i++){
        int minPos = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[minPos]){
                minPos = j;
            }
        }
        if(minPos!=i){
            temp = arr[i];
            arr[i] = arr[minPos];
            arr[minPos] = temp;
        }
    }
}
void bubbleSort(int arr[], int n){
    int temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void output(int n, int arr[]){
    for (int i = 0; i < n; ++i) {
        printf("%2d", arr[i]);
    }
}
int main() {
    int arr[7] = {3, 6, 2, 5, 1, 0, 9};
    int n = 7;

    output(n, arr);
    printf("\n");

    quickSort(arr, n);

    output(n, arr);
    return 0;
}
