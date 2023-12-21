//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int find_max(int arr[], int len) {
//    int max = arr[0];
//    for (int i = 1; i < len; i++) {
//        if (arr[i] > max) {
//            max = arr[i];
//        }
//    }
//    return max;
//}
//
//void swap(int *a, int *b) {
//    int tmp = *a;
//    *a = *b;
//    *b = tmp;
//}
//
//int main() {
//	int num[5] = { 0 };
	//for (int i = 0; i < 5; i++) {
	//	scanf("%d", &num[i]);
	//}
	//int big = find_max(num, 5);
 //   int cnt = 0;
 //   while (num[cnt] != big) {
 //       cnt++;
 //   }
 //   printf("big%d\n", big);
 //   printf("cnt:%d\n", cnt);
 //   for (int i = 0; i < cnt / 2; i++) {
 //       swap(&num[i], &num[cnt-i]);
 //   }//���� ū ������ ������
 //   for (int i = 0; i < 5/2; i++) {
 //       swap(&num[i], &num[4 - i]);
 //   }//���� ū ���� �� ���ϱ� ��ü ������
 //   for (int i = 0; i < 5; i++) {
 //       printf("%d", num[i]);
 //   }
 //   printf("\n");//13425����. �� �ѹ��� ������ ��
 //   big = find_max(num, 4);
 //   cnt = 0;
 //   while (num[cnt] != big) {
 //       cnt++;
 //   }
 //   printf("big%d\n", big);
 //   printf("cnt:%d\n", cnt);
 //   for (int i = 0; i < cnt / 2; i++) {
 //       swap(&num[i], &num[cnt - i]);
 //   }//���� ū ������ ������
 //   for (int i = 0; i < 4 / 2; i++) {
 //       swap(&num[i], &num[3 - i]);
 //   }//���� ū ���� �� ���ϱ� ��ü ������
 //   for (int i = 0; i < 5; i++) {
 //       printf("%d", num[i]);
 //   }
 //   printf("\n");
 //   big = find_max(num, 3);
 //   cnt = 0;
 //   while (num[cnt] != big) {
 //       cnt++;
 //   }
 //   printf("big%d\n", big);
 //   printf("cnt:%d\n", cnt);
 //   for (int i = 0; i < cnt / 2; i++) {
 //       swap(&num[i], &num[cnt - i]);
 //   }//���� ū ������ ������
 //   for (int i = 0; i < 3 / 2; i++) {
 //       swap(&num[i], &num[2 - i]);
 //   }//���� ū ���� �� ���ϱ� ��ü ������
 //   for (int i = 0; i < 5; i++) {
 //       printf("%d", num[i]);
 //   }
 //   printf("\n");

 //   big = find_max(num, 2);
 //   cnt = 0;
 //   while (num[cnt] != big) {
 //       cnt++;
 //   }
 //   printf("big%d\n", big);
 //   printf("cnt:%d\n", cnt);
 //   for (int i = 0; i < cnt / 2; i++) {
 //       swap(&num[i], &num[cnt - i]);
 //   }//���� ū ������ ������
 //   for (int i = 0; i < 2 / 2; i++) {
 //       swap(&num[i], &num[1 - i]);
 //   }//���� ū ���� �� ���ϱ� ��ü ������
 //   for (int i = 0; i < 5; i++) {
 //       printf("%d", num[i]);
 //   }
 //   printf("\n");

//    int temp = 5;
//    int big = -1;
//    int cnt = 0;
//    while (temp != 0) {
//
//        big = find_max(num,temp);
//        cnt = 0;
//        while (num[cnt] != big) {
//            cnt++;
//        }
//        printf("big%d\n", big);
//        printf("cnt:%d\n", cnt);
//        for (int i = 0; i < cnt / 2; i++) {
//            swap(&num[i], &num[cnt - i]);
//        }//���� ū ������ ������
//        for (int i = 0; i < temp / 2; i++) {
//            swap(&num[i], &num[temp - 1 - i]);
//        }//���� ū ���� �� ���ϱ� ��ü ������
//        for (int i = 0; i < temp; i++) {
//            printf("%d", num[i]);
//        }
//        printf("\n");
//    }
//    temp--;
//    return 0;
//}

#define time 30
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int find_max(int arr[], int len) {
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int num[time] = { 0 };
    int result[100] = { 0 };
    int number = 0;
    printf("�Է��� ������ũ�� ��");
    scanf("%d", &number);//�� ������ number
    for (int i = 0; i < number; i++) {
        scanf("%d", &num[i]);
    }
 
    int temp = number;
    int j = 0;


    while (temp != 0) {
        int big = find_max(num, temp);
        int cnt = 0;
        while (num[cnt] != big) {
            cnt++;
        }
        //printf("big:%d\n", big);
        //printf("cnt:%d\n", cnt);
        //printf("temp:%d\n", temp);
        //printf("���� ū �� ã�Ƽ� ���� �ø���\n");
        for (int i = 0; i < (cnt+1) / 2; i++) {
            swap(&num[i], &num[cnt - i]);
        }
        printf("\nflip:%d\n", cnt + 1);
        for (int i = 0; i < number; i++) {
            printf("%d ", num[i]);
        }
        //printf("���� ���� ���� ū �� �� �Ʒ��� ������\n");
        for (int i = 0; i < temp / 2; i++) {
            swap(&num[i], &num[temp - 1 - i]);
        }
        //���
        printf("\nflip:%d\n", temp);
        for (int i = 0; i < number; i++) {
            printf("%d ", num[i]);
        }


        if (temp != (cnt + 1)) {
            result[j] = cnt + 1;
            result[j + 1] = temp;
            j = j + 2;
        }
        temp--;
    }
    printf("\n\nresult\n");
    printf("flip\n");
    int k = 0;
    for (int k = 0; result[k] != 0; k +=1) { // 0�� ���������� ���
        if (result[k] == 1) {
            continue;
        }
        printf("%d:%d\n",k, number + 1 - result[k]);
    }
}





//qsort(start_hour, num, sizeof(int), compare);
int compare(const void* a, const void* b) {
    if (*(int*)a > *(int*)b) {
        return 1;
    }
    else if (*(int*)a < *(int*)b) {
        return -1;
    }
    else {
        return 0;
    }
}