#include <stdio.h>

int digit_sum(int x){
	int sum=0;
	while(x>0){
		sum += x%10; //x의 각자릿수(10으로 나눴을 때의 나머지)를 sum에 더함
		x = x/10; //x의 다음 자릿수를 더하기 위해 x에 10을 나누기
	}
	return sum;
}
int main() {
	int n, num[101],m=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &num[i]);
	}
	int max=0;
	int maxn=0;
	for(int i=0; i<n; i++){
		m = digit_sum(num[i]);
		if(m>max || (m==max && num[i]>maxn)){ //각자릿수의 합이 같다면 num이 큰 값이 maxn 
			max=m;
			maxn=num[i];
		}
	}
	printf("%d",maxn); 
	return 0;
}
