#include <stdio.h>
int i,k,n=8;
int hash(int key)
{
    return key%n;
}
int main()
{
    int key;
    int list[8]={0,0,10,3,2,5,0,0}; //초기 해시 테이블
    scanf("%d",&key);
    int index=hash(key); //입력받은 key의 해시값을 구해서 배열 인덱스 계산
    while(1) //충돌이 발생할 때까지
    {
        if(list[index]==0) //인덱스가 비어있으면
        {
            list[index]=key;
            break; //저장이 됐으면 종료
        }
        else //값이 이미 있다면
        {
            k++; //충돌 해결
            index=(hash(key)+k)%n; //새로운 인덱스
        }
    }
    printf("%d",index);
    return 0;
}