#include <stdio.h>
int main() {
	char a[101],b[101];
	int i,j,digit,count[100]={0};

	scanf("%s", a);
	for(j=0; a[j] != '\0'; j++){
		if(a[j] >= 65 && a[j] <= 90){
			digit = a[j] -65; //대문자 값에서 65를 빼서 인덱스로 변환
		} else if(a[j] >= 97 && a[j] <=122) { 
			digit = a[j]-71; //소문자의 값에서 71을 빼서 인덱스로 변환
		}
		count[digit]++; //해당 문자 카운트 증가
	}
	scanf("%s", b);
	for (j = 0; b[j] != '\0'; j++) {
		if (b[j] >= 65 && b[j] <= 90) {
			digit = b[j] - 65;
    } else if (b[j] >= 97 && b[j] <= 122) {
			digit = b[j] - 71;
		}
		count[digit]--; // 해당 문자 카운트 감소
	}
	
	for(i=0; i<52; i++){
		if(count[i] != 0){ //하나라도 0이 아니라면
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}
