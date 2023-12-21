#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find_max(int[]);
int elapsed_time(int, int, int, int);
int compare(const void* a, const void* b);
void quickSort(int arr[], int arr2[], int L, int R);


int main() {
    int num;
    scanf("%d", &num);

    char start[100][100]; // array to store Hour and Minute
    char end[100][100];

    int start_hour[100]; //array to store HH of starting schedule
    int start_min[100];
    int end_hour[100]; // array to store MM of ending schedule
    int end_min[100];
    int time[100] = { 0 };
    char words[255];
    for (int i = 0; i < num; i++) {
        scanf("%s %s", start[i], end[i]);
        gets(words);
        //slice time by :
        start_hour[i] = atoi(strtok(start[i], ":"));
        start_min[i] = atoi(strtok(NULL, ":"));
        end_hour[i] = atoi(strtok(end[i], ":"));
        end_min[i] = atoi(strtok(NULL, ":"));
        words[0] = '\0';
    }
    //sort the time.
    //As minute and hour is stored in another array, Hour and Minute index should be sorted in the same way.
    quickSort(start_hour, start_min, 0, num - 1);
    quickSort(end_hour, end_min, 0, num - 1);

    //Calculate time between 10:00~start time
    time[0] = elapsed_time(10, 0, start_hour[0], start_min[0]);
    //Calculate time between end time~18:00
    time[num] = elapsed_time(end_hour[num - 1], end_min[num - 1], 18, 0);

    for (int i = 1; i < num; i++) {
        //if ending minute has bigger value than start minute Ex) if Nap Time is 14:30 ~ 15:00 ->hour = 1, Minute = -30(x) -> hour = 0, Minute = 30(o)
        if (end_min[i - 1] > start_min[i]) {
            start_hour[i] = start_hour[i] - 1;
            start_min[i] = start_min[i] + 60;
            time[i] = elapsed_time(end_hour[i - 1], end_min[i - 1], start_hour[i], start_min[i]);
        }
        else {
            time[i] = elapsed_time(end_hour[i - 1], end_min[i - 1], start_hour[i], start_min[i]);
        }
    }
    //every nap time is stored in time array. Find the longgest minute and print its' time.
    int result = find_max(time, num);
    for (int i = 0; i <= num; i++) {
        if (result == time[i]) {
            if (i == 0) {
                printf("Day #1: the longest nap starts at 10:00 and will last for ");
            }
            else {
                printf("Day #1: the longest nap starts at %d:%02d and will last for ", end_hour[i - 1], end_min[i - 1]);
            }
            printf("%d hours and %d minutes.", time[i] / 60, time[i] % 60);
            break;
        }
    }
    return 0;
}

//Second time must be the late time. Meaning first parameter is ending time of the early schedule and second parameter is the starting time after ending time of the first schedule.
int elapsed_time(int first_hour, int first_min, int second_hour, int second_min) {
    int min = 0;
    if (second_hour - first_hour > 0) {
        min = min + ((second_hour - first_hour) * 60);
    }
    min = min + (second_min - first_min);
    return min;
}
//find the biggest number.
int find_max(int arr[], int num) {
    int max = arr[0];
    for (int i = 0; i <= num; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
//Quick sort algorithm
void quickSort(int arr[], int arr2[], int L, int R) {
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

    if (L < right)
        quickSort(arr, arr2, L, right);

    if (left < R)
        quickSort(arr, arr2, left, R);
}