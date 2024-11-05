#include <stdio.h>
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) //두 변수 값 교환

int n;
int step = 1; //현재 단계


//배열을 피벗 기준으로 두 부분으로 나눔
int partition(int list[], int left, int right) {
    int pivot, temp, low, high;
    low = left;         // 왼쪽 탐색
    high = right + 1;   // 오른쪽 탐색
    pivot = list[left];
    
    //low와 high가 교차할 때까지 반복하여 요소를 피벗 기준으로 나눔
    do {
        do {
            low++; // 피벗보다 큰 값을 찾을 때까지 오른쪽으로 이동
        } while (low <= right && list[low] > pivot);
        
        do {
            high--; // 피벗보다 작은 값을 찾을 때까지 왼쪽으로 이동
        } while (list[high] < pivot);

        // low와 high가 교차하지 않은 경우
        if (low < high) {
            swap(list[low], list[high], temp); // low와 high 위치의 값 교환
        }
    } while (low < high); // low와 high가 교차할 때까지 반복

    swap(list[left], list[high], temp);


    printf("%d단계 : ", step++);
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return high; // 피벗의 최종 위치 반환
}

//재귀적으로 배열을 정렬
void quicksort(int list[], int left, int right) {
    if (left < right) {
        int q = partition(list, left, right); //배열을 피벗 기준으로 나누고 피벗 위치 반환
        quicksort(list, left, q - 1); // 피벗 왼쪽 부분 정렬
        quicksort(list, q + 1, right); // 피벗 오른쪽 부분 정렬
    }
}

int main() {
    int list[64];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    quicksort(list, 0, n - 1);

    return 0;
}
