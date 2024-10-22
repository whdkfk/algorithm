#include <stdio.h>
int key,count,n;
int arr[5]={9,5,8,3,7};

int search(){
    for(int i=0; i<n; i++){
        count ++; //탐색 할때마다 count 증가

        if(arr[i]==key) return count; //탐색한 자료가 key와 일치하면 count 리턴
    }
    return -1;
}

int main(void){
    n = sizeof(arr)/sizeof(int);
    scanf("%d", &key);
    int result = search();

    if(result==-1) printf("탐색실패");
    else printf("%d", result);

    return 0;
}