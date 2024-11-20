#include <stdio.h>
int key,count;
int arr[6] = {1,2,3,4,5,6};

int search(int start, int end){
    int middle;

    if(start<=end){
        count++;
        middle=(start+end)/2; //반을 나눠서 탐색

        if(key==arr[middle]) return count;
        else if(key>arr[middle]) return search(start, middle-1); //key>arr[middle]이면 앞부분을 다시 탐색 
        else if(key<arr[middle]) return search(middle+1, end); //key<arr[middle]이면 뒷부분만 다시 탐색 
    }
    return -1;
}

int main(void){
    int n=sizeof(arr)/sizeof(int);
    scanf("%d", &key);
    int result=search(0,n-1);

    if(result==-1) printf("탐색실패");
    else printf("%d", result);

    return 0;
}