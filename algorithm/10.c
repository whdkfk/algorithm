#include<stdio.h>
 
int n, parent[1001];
 
int Find(int v)
{
    if (parent[v] == v)
        return v;
    else
        return parent[v] = Find(parent[v]); //최종 분모 찾기
}
 
void Union(int x, int y){
    x = Find(x); //분모 찾기
    y = Find(y); 
 
    if (x != y) //합침
        parent[x] = y; //x부모를 y로 지정
}
 
void Set()
{
    int i;
 
    for (i = 1; i <= n; i++)
        parent[i] = i; //각 숫자의 부모를 자기 자신으로 초기화
}
 
int main(void)
{
 
    int m, i,a, b;
 
    scanf("%d %d", &n, &m); //학생수, 숫자쌍 개수 입력
 
    Set(); //자기 자신으로 초기화
 
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b); //a,b 입력
 
        Union(a, b); //집합으로 합침
    }
 
    scanf("%d %d", &a, &b);
    if (Find(a) == Find(b)) //a,b가 같은 집합에 있는지 확인
        printf("YES\n");
    else
        printf("NO\n");
 
    return 0;
}