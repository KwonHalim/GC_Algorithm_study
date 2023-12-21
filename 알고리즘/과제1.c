#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find_max(int[]);
int elapsed_time(int, int, int, int);
void quickSort(int[], int[], int, int);

int main() {
    int num;
    printf("비교할 시간 범위의 개수를 입력하세요: ");
    scanf("%d", &num);

    // 시간 범위를 저장할 배열
    char start[100][100]; // "HH:MM" 형식의 문자열을 저장하기 위한 배열
    char end[100][100];
    int start_hour[100];
    int start_min[100];
    int end_hour[100];
    int end_min[100];
    int time[100] = { 0 };

    // 시간 범위 입력 받기
    for (int i = 0; i < num; i++) {
        printf("시작 시간 (예: 12:00): ");
        scanf("%s", start[i]);
        printf("종료 시간 (예: 13:35): ");
        scanf("%s", end[i]);

        // 시간과 분을 저장
        start_hour[i] = atoi(strtok(start[i], ":"));
        start_min[i] = atoi(strtok(NULL, ":"));
        end_hour[i] = atoi(strtok(end[i], ":"));
        end_min[i] = atoi(strtok(NULL, ":"));
    }
    //정렬 함수 하나 만들어서 start_hour를 정렬하고 그 정렬 기준에 따라서 minute도 같이 정렬한다.
    //시간 정렬 필요
    quickSort(start_hour, start_min, 0, num - 1);
    quickSort(end_hour, end_min, 0, num - 1);


    time[0] = elapsed_time(10, 0, start_hour[0], start_min[0]);
    time[num] = elapsed_time(end_hour[num - 1], end_min[num - 1], 18, 0);

    for (int i = 1; i < num; i++) {
        if (end_min[i-1] > start_min[i]) {
            start_hour[i] = start_hour[i] - 1;
            start_min[i] = start_min[i] + 60;
            time[i] = elapsed_time(end_hour[i - 1], end_min[i - 1], start_hour[i], start_min[i]);
        }
        else {
            time[i] = elapsed_time(end_hour[i - 1], end_min[i - 1], start_hour[i], start_min[i]);
        }
    }
    int result = find_max(time, num);
    for (int i = 0; i <= num; i++) {
        if (result == time[i]) {
            if (i == 0) {
                printf("10시부터");
            }
            else if (i == num) {
                printf("%d시 %d분부터", end_hour[i - 1], end_min[i-1]);
            }
            else {
                printf("%d시 %d분부터", end_hour[i-1], end_min[i-1]);
            }
            printf("%d시간 %d분 잘 수 있습니다.", time[i]/60, time[i] % 60);
            break;
        }
    }
    return 0;
}

//뒤에 들어오는 값이 나중 시간
int elapsed_time(int first_hour, int first_min, int second_hour, int second_min) {
    int min = 0;
    if (second_hour - first_hour > 0) {
        min = min + ((second_hour - first_hour) * 60);
    }
    min = min + (second_min - first_min);
    return min;
}

int find_max(int arr[], int num) {
    int max = arr[0];
    for (int i = 0; i <= num; i++) {
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void quickSort(int arr[], int arr2[] , int L, int R) {
    int left = L, right = R;
    int pivot = arr[(L + R) / 2];
    int temp;
    int temp2;
    do
    {
        while (arr[left] < pivot)   
            left++;
        while (arr[right] > pivot) 
            right--;
        if (left <= right)   
        {
            temp = arr[left];
            temp2 = arr2[left];
            arr[left] = arr[right];
            arr2[left] = arr2[right];
            arr[right] = temp;
            arr2[right] = temp2;
            left++;
            right--;
        }
    } while (left <= right);    

    /* recursion */
    if (L < right)
        quickSort(arr, arr2, L, right); 

    if (left < R)
        quickSort(arr, arr2, left, R);
}/*
 시작:10:00
2시간
12:00 ~ 14:00
1시간
15:00 ~ 16:00
2시간
종료:18:00

시작:10:00
1시간
11:00 ~ 14:00
1시간
15:00 ~ 15:00
3시간
종료:18:00

시작:10:00
4시간
14:00 ~ 14:30
30분
15:00 ~ 16:30
1시간30분
종료:18:00

시작:10:00
0시간
10:00 ~ 11:30
4시간30분
16:00 ~ 16:30
1시간30분
종료:18:00
input 예시
*/