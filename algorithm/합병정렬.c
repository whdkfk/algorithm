#include <stdio.h>
int sorted[100];

void merge(int list[], int left,int mid, int right)
{
    int i,j,k,l;
    i=left;
    j=mid+1; //오른쪽 배열 첫번째 요소
    k=left; //정렬된 걸 저장할 인덱스
    while(i<=mid && j<=right) //양쪽 배열을 비교하면서 병합
    {
        if(list[i]<=list[j])
        {
            sorted[k++]=list[i++]; //왼쪽 배열 값을 정렬된 배열에 추가
        }
        else
        {
            sorted[k++]=list[j++]; //오른쪽 배열 값을 정렬된 배열에 추가
        }
    }
    if(i>mid) //왼쪽 배열이 다 추가돼서 없으면
    {
        for(l=j; l<=right; l++) //오른쪽 배열 나머지 값을 다 추가
        {
            sorted[k++]=list[l];
        }
    }
    else //오른쪽 배열이 다 추가돼서 없으면
    {
        for(l=i; l<=mid; l++) //왼쪽 배열 나머지 값을 다 추가
        {
            sorted[k++]=list[l];
        }
    }
    for(l=left; l<=right; l++) // 정렬된 결과를 원래 배열에 넣음
    {
        list[l]=sorted[l];
    }
}

void mergesort(int list[], int left,int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        mergesort(list,left,mid);
        mergesort(list,mid+1,right);
        merge(list,left,mid,right);
    }
}

int main()
{
    int list[4]={27,12,20,25};
    mergesort(list,0,3);
    for(int i=0; i<4; i++)
    {
        printf("%d ",list[i]);
    }
    return 0;
}