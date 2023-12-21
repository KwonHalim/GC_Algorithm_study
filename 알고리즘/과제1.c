#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find_max(int[]);
int elapsed_time(int, int, int, int);
void quickSort(int[], int[], int, int);

int main() {
    int num;
    printf("���� �ð� ������ ������ �Է��ϼ���: ");
    scanf("%d", &num);

    // �ð� ������ ������ �迭
    char start[100][100]; // "HH:MM" ������ ���ڿ��� �����ϱ� ���� �迭
    char end[100][100];
    int start_hour[100];
    int start_min[100];
    int end_hour[100];
    int end_min[100];
    int time[100] = { 0 };

    // �ð� ���� �Է� �ޱ�
    for (int i = 0; i < num; i++) {
        printf("���� �ð� (��: 12:00): ");
        scanf("%s", start[i]);
        printf("���� �ð� (��: 13:35): ");
        scanf("%s", end[i]);

        // �ð��� ���� ����
        start_hour[i] = atoi(strtok(start[i], ":"));
        start_min[i] = atoi(strtok(NULL, ":"));
        end_hour[i] = atoi(strtok(end[i], ":"));
        end_min[i] = atoi(strtok(NULL, ":"));
    }
    //���� �Լ� �ϳ� ���� start_hour�� �����ϰ� �� ���� ���ؿ� ���� minute�� ���� �����Ѵ�.
    //�ð� ���� �ʿ�
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
                printf("10�ú���");
            }
            else if (i == num) {
                printf("%d�� %d�к���", end_hour[i - 1], end_min[i-1]);
            }
            else {
                printf("%d�� %d�к���", end_hour[i-1], end_min[i-1]);
            }
            printf("%d�ð� %d�� �� �� �ֽ��ϴ�.", time[i]/60, time[i] % 60);
            break;
        }
    }
    return 0;
}

//�ڿ� ������ ���� ���� �ð�
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
 ����:10:00
2�ð�
12:00 ~ 14:00
1�ð�
15:00 ~ 16:00
2�ð�
����:18:00

����:10:00
1�ð�
11:00 ~ 14:00
1�ð�
15:00 ~ 15:00
3�ð�
����:18:00

����:10:00
4�ð�
14:00 ~ 14:30
30��
15:00 ~ 16:30
1�ð�30��
����:18:00

����:10:00
0�ð�
10:00 ~ 11:30
4�ð�30��
16:00 ~ 16:30
1�ð�30��
����:18:00
input ����
*/