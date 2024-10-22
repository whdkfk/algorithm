#include <stdio.h>
int main() {
	int arr[301][301];
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d ", &arr[i][j]);
		}
	}
	int k;
	int sum=0;
	int i,j,x,y;
	scanf("%d",&k);
	for(int q=1; q<=k; q++){
		scanf("%d %d %d %d", &i, &j, &x, &y);
		sum=0;
		for(int w=i; w<=x; w++){ //지정된 좌표 범위의 요소 합 계산
			for(int e=j; e<=y; e++){
				sum+=arr[w][e]; //범위 내의 모든 요소를 더해 sum에 저장
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
