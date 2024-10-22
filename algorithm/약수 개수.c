#include <stdio.h>
int main() {
	int n, num[50001]={0},m;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){ //i마다 약수의 개수를 찾지 않고 j의 배수는 모두 i를 약수로 가진다를 이용해서 시간 줄이기
		for(int j=i; j<=n; j+=i){ //i가 j의 약수 num[j]를 증가시킴
			num[j]++;
		}
	}
	for(int i=1; i<=n; i++){
		printf("%d ", num[i]);
	}
	return 0;
}
