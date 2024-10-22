#include <stdio.h>
int main(void){
    int n;
    int count=0;
    scanf("%d", &n);
    while(n>0) {
        if(n<3){
            n-=1;
            count++;
        } else if(n>=3){
            n-=3;
            count++;
        }
    }
    if(count%2==0)
        printf("SK");
    else
        printf("CY");
    return 0;
}
