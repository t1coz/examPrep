#include <stdio.h>
#include <stdlib.h>
//https://pastebin.com/Wt6H8tZx
//otherStuff--------------------
int fibonacciNum(int n){
    if(n<3)
        return 1;
    else
        return(fibonacciNum(n-2)+ fibonacciNum(n-1));
}
//2DArraysAndActionsW/Them------------------
int **memory(int n, int m) {
    int **arr;
    arr = (int **) calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *) calloc(m, sizeof(int));
    }
    return arr;
}
int **addRowAfterK(int **arr, int *n, int m, int k) {
    (*n)++;
    arr = (int **) realloc(arr, (*n) * sizeof(int *));
    arr[*n - 1] = (int *) calloc(m, sizeof(int));
    int *temp = arr[*n - 1];
    for (int i = *n - 1; i >= k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = temp;
    for (int i = 0; i < m; i++)
        arr[k-1][i] = 0;
}
int **add_line(int **arr, int *n, int m, int ind) {
    (*n)++;
    int** new_arr = (int **)realloc(arr, (*n) * sizeof(int *));
    if (new_arr == nullptr) {
        (*n)--;
        throw std::exception("no memory");
    }
    arr = new_arr;
    arr[(*n) - 1] = (int *)malloc(m * sizeof(int));
    for (int i = (*n) - 2; i > ind; i--) {
        for (int j = 0; j < m; j++) {
            //копируем всю строку
            arr[i + 1][j] = arr[i][j];
        }
    }
    return arr;
}
int **delEachKRow(int **arr, int *n, int k){
    for(int j = *n - 1; j >= 0; j--) {
        if ((j + 1) % k == 0) {
            //int *temp = arr[j];
            for (int i = j; i < *(n) - 1; i++) {
                arr[i] = arr[i + 1];
            }
            printf("\\n");
            //free(temp);
            (*n)--;
            arr = (int **) realloc(arr, (*n) * sizeof(int *));
        }
    }
    return arr;
}
int cnt0InColumn(int** mas, int n, int m, int k){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(mas[i][k] > 10)
            cnt++;
    }
    return cnt;
}
int cntOddInRow(int* mas, int m){
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(mas[i] % 2 == 1)
            cnt++;
    }
    return cnt;
}
void sortColumn(int** matr, int n, int m){
    for(int i=0; i < m; i++){
        for(int j = 0; j < m-1; j ++){
            int key1 = cnt0InColumn(matr, n, m, j);
            int key2 = cnt0InColumn(matr, n, m, j+1);
            if(key1 > key2){
                for(int k = 0; k < n; k++){
                    int temp = matr[k][j];
                    matr[k][j] = matr[k][j+1];
                    matr[k][j+1] = temp;
                }
            }
        }
    }
}
void sortRow(int** matr, int n, int m){
    for(int i=0; i < n; i++){
        for(int j = 0; j < n-1; j ++){
            int key1 = cntOddInRow(matr[j], m);
            int key2 = cntOddInRow(matr[j+1], m);
            if(key1 > key2){
                int* temp = matr[j];
                matr[j] = matr[j+1];
                matr[j+1] = temp;
            }
        }
    }
}
//stringsAndActionsW/Them----------------------------------
void reverseString(char **str, int l, int h, int i){
    if (l < h){
        swap(&str[i-1][l], &str[i-1][h]);
        reverseString(str, l + 1, h - 1, i);
    }
}
char* getStr(){
    char* s;
    char c;
    int i=0, n = 1;
    s = (char*)calloc(n, sizeof (char));
    while(n<=1){
        while((c = getchar()!=EOF) && c!= '\n'){
            n++;
            s = (char*)realloc(s, n * sizeof(char));
            s[i] = c;
            i++;
        }
    }
    s[n] = '\0';
    return s;
}
int strLen(char* str){
    int i = 0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}
int isLetter(char s){
    if((s>='a' && s<='z')||(s>='A' && s<='Z'))
        return 1;
    return 0;
}
void strCopy(char* s1, char** s2){
    int i = 0;
    int n = strLen(s1);
    *s2 = (char*)calloc(n,sizeof(char));
    while(s1[i]!='\0'){
        *s2[i] = s1[i];
        i++;
    }
    *s2[i] = '\0';
}
int countWords(char *s){
    int cnt = 0, i;
    int n = strLen(s);
    for (i = 0; i < n; i++) {
        if(isLetter(s[i])==1 && i == 0){
            cnt++;
        }
        if(isLetter(s[i-1])==0 && isLetter(s[i])==1){
            cnt++;
        }
    }
    return cnt;
}
int strCmp(char *s1, char *s2){
    int i = 0;
    while(s1[i]!='\0'){
        if(s1[i] - s2[i] != 0)
            return s1[i] - s2[i];
        i++;
    }
    if(s1[i]=='\0'){
        return -1;
    }
    return 0;
}
int atoI(char *str){
    int res = 0;
    int sign = 1;
    int i = 0;
    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return sign * res;
}
double a_to_f(char *s)
{ float n, res = 0.0;
    int i=0, znak;
    while(s[i++]==' ' && s[i]!='\0');
    if (s[i]=='\0') return 0;
    i--;
    znak = (s[i]=='-') ? -1 : 1;
    if (s[i]=='+' || s[i]=='-')
        i++;
    for(n=0.0; (s[i]>'0' && s[i]<='9') || s[i]=='.'; i++){
        if (s[i]!='.')
            n= 10.0*n + (s[i]-'0');
        else res=1;
        if (res != 0) res *= 10;
    }
    res /= 10;
    return znak*n / res;
}
void deletingArr(char **arr, int n){
    if(n!=0){
        for (int i = 0; i < n; i++) free(arr[i]);
        free(arr);
    }
}
int mostRepeated(char*arr, char** words){
    int repeatCount = 0, maxRepeat = 0, maxIndex = 0, flag = 1;
    int wordCount = countWords(arr);
    int n = strLen(arr);
    for (int j = 0; j < wordCount; j++){
        for (int i = 0; i < wordCount; i++) {
            for (int k = 0; k < n; k++){
                if (words[j][k] != words[i][k]){
                    flag = 0;
                    break;
                }
            }
            if (flag == 1){
                repeatCount++;
            }
            flag = 1;
        }
        if (maxRepeat < repeatCount){
            maxRepeat = repeatCount;
            maxIndex = j;
        }
        repeatCount = 0;
    }
    return maxIndex;
}
void deletingWordWithRow(char*** strSplited, int *wordCount, int k, int m){
    int i;
    for(i = k; i<*wordCount-1; i++){
        for(int j=0; j < m; j++)
            (*strSplited)[i][j] = (*strSplited)[i+1][j];
    }
    (*wordCount)--;
    (*strSplited) = (char**)realloc((*strSplited), (*wordCount) * sizeof(char*));
}
void deletingFromSecDiag(int **arr, int n, int *m){
    for (int i = 0; i < n; i++){
        for (int k = *m-i; k < *m; k++){
            arr[i][k - 1] = arr[i][k];
        }
    }
    (*m)--;
    for (int j = 0; j < n; ++j) {
        arr[j] = (int*)realloc(arr[j], (*m) * sizeof(int));
    }
}
char *strCat(char *s1, char *s2, int k){
    char *s;
    int i, len1 = strLen(s1), len2 = strLen(s2);
    if (k > len1)
        k=len1;
    if ((s=(char*)malloc(sizeof(char)*(len1 + len2))) == NULL)
        return s1;
    for (i=0; i<k; i++)
        s[i] = s1[i];
    for (i=0; s2[i]!='\0'; i++)
        s[k+i] = s2[i];
    for (i=0; s1[k+i]!='\0'; i++)
        s[k+len2+i] = s1[k+i];
    s[k+len2+i]='\0';
    s1=s;
    return s1;
}
//rowActionsFor1D------------------------------------------------------------
void reverse(char* str, int size){
    char temp;
    for (int i = 0; i < size / 2; i++){
        temp = str[size - i - 1];
        str[size - i - 1] = str[i];
        str[i] = temp;
    }
}
void SwapWords(char* str, int firstBegin, int firstEnd, int secondBegin, int secondEnd){
    char* str_p = &(str[firstBegin]);
    reverse(str_p, secondEnd - firstBegin + 1);
    reverse(str_p, secondEnd - secondBegin + 1);
    str_p = &(str[secondBegin - (firstEnd - firstBegin) + (secondEnd - secondBegin)]);
    reverse(str_p, firstEnd - firstBegin + 1);
    str_p = &(str[secondEnd - secondBegin + 1]);
    reverse(str_p, secondBegin - firstEnd - 1);
}
void cycleShiftintOddOnK(int *arr, int n, int k){
    for(int j = k; j>=0; j--){
        int value = arr[1];
        for(int i = 1; i<n-1; i+=2){
            arr[i]= arr[i+2];
        }
        arr[n-2] = value;
    }
}
void rightShiftOf1DArray(int arr[], int n){
    int c = arr[n-1];
    for(int i = n-1; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = c;
}
void leftShiftOf1DArray(int arr[], int n){
    int c = arr[0];
    for(int i = 0; i<n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = c;
}
void deletingKElementFromRow1D(int arr[], int *n, int k){
    for(int i = k; i<(*n)-1; i++){
        arr[i] = arr[i+1];
    }
    (*n)--;
}
void addKElementto1D(int arr[], int *n, int k){
    (*n)++;
    for(int i = *n-1; i>k; i--){
        arr[i+1] = arr[i];
    }
    arr[k+1] = -1;
}
void addElementAfterCondition(int arr[], int n){ //if multiple of 3, add 100 after value
    for (int i = n-1; i >= 0; i--) {
        if (arr[i] % 3 == 0) {
            n++;
            for (int j = n - 1; j > i; j--)
                arr[j + 1] = arr[j];
            arr[i + 1] = 100;
        }
    }
}
int mostFrequentNumber(int *arr, int n){
    int i = 0, index = i, count, maxFrequency = 0;
    for(i = 0; i<n; i++){
        count = 0;
        for(int j = 0; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count>maxFrequency){
            index = i;
            maxFrequency = count;
        }
    }
    return index;
}
//SortingMethods-------------------------------------------------------------------------
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
void quickSortRec(int arr[], int low, int high){
    if(low<high){
        int pivotIndex = partition(arr, low, high);
        quickSortRec(arr, low, pivotIndex-1);
        quickSortRec(arr, pivotIndex+1, high);
    }
}
void quickSort(int arr[], int n){
    quickSortRec(arr, 0, n-1);
}
void mergeSortedArray(int arr[], int l, int m, int r){
    int leftLength = m+1-l, rightLength = r-m;
    int tempL[leftLength], tempR[rightLength];
    int i, j, k;
    for(i = 0; i<leftLength; i++)
        tempL[i] = arr[l+i];
    for(i = 0; i<rightLength; i++)
        tempR[i] = arr[m+1+i];
    for(i=0, j=0, k=l; k<=r; k++){
        if(i<leftLength && (j>=rightLength || tempL[i]<tempR[j])){
            arr[k] = tempL[i];
            i++;
        }else{
            arr[k] = tempR[j];
            j++;
        }
    }
}
void mergeSortRecursion(int arr[], int l, int r){
    if(l<r){
        int m = (l+r-1)/2;
        mergeSortRecursion(arr, l, m);
        mergeSortRecursion(arr, m+1, r);
        mergeSortedArray(arr, l, m, r);
    }
}
void mergeSort(int arr[], int n ){
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
    for(int i=0; i<n; i++){
        for(int j = 0; j<n-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void output1D(int n, int arr[]){
    for (int i = 0; i < n; ++i) {
        printf("%2d", arr[i]);
    }
}
//some Pre-ready tasks
//void isLetter(char s){
//    if((s>='A' && s<='Z')||(s>='a'&&s<='z'))
//        return 1;
//    return 0;
//}
int findKWord(char *str, int n, int k){
    int count = 0;
    for(int i = 0; i<n; i++){
        if(isLetter(str[i]) ==1 && i == 0){
            count++;
        }
        if(isLetter(str[i-1]) == 0 && isLetter(str[i] = 1 )){
            count++;
        }
        if(count == k){
            return i;
        }
    }
}
int findEndIndex(char *str, int n, int k){
    int i = findKWord(str, n, k);

    while(isLetter(str[i]) == 1){
        i++;
    }
    return i;
}
void swapWords(char* str, int firstBeg, int firstEnd, int secondBeg, int secondEnd){
    char* s = &(str[firstBeg]);
    reverse(s, secondEnd-firstBeg+1);
    reverse(s, secondEnd-secondBeg+1);
    s = &(str[secondBeg-(firstEnd-firstBeg)+(secondEnd-secondBeg)]);
    reverse(s, firstEnd-firstBeg+1);
    s = &(str[secondEnd-secondBeg+1]);
    reverse(s, secondBeg-firstEnd-1);
}
void task2(char *str, int n, int k1, int k2){
    swapWords(str, findKWord(str, n, k1), findEndIndex(str, n, k1), findKWord(str, n, k2), findEndIndex(str, n, k2));
}
int main() {
    int arr[7] = {3, 6, 2, 5, 1, 0, 9};
    int n = 7;

    output1D(n, arr);
    printf("\n");

    mergeSort(arr, n);
    output1D(n, arr);
    printf("\n");
    return 0;
}
