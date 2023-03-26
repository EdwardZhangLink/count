#include <stdio.h>
#include <windows.h>

#define MAX_NUMBERS 1000

int main() {
    SetConsoleOutputCP(65001);
    int numbers[MAX_NUMBERS];
    int count[MAX_NUMBERS];
    int n, i, j, temp;

    printf("请输入数字个数：");
    scanf("%d", &n);

    // 读入数字并统计出现次数
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        count[i] = 1;
        for (j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                count[j]++;
                count[i] = 0;
                break;
            }
        }
    }

    // 使用冒泡排序将数字按出现次数从高到低排序
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (count[j] < count[j + 1]) {
                // 交换数字出现次数
                temp = count[j];
                count[j] = count[j + 1];
                count[j + 1] = temp;

                // 交换数字本身
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // 输出结果
    printf("数字\t出现次数\n");
    for (i = 0; i < n; i++) {
        if (count[i] == 0) {
            break;
        }
        printf("%d\t%d\n", numbers[i], count[i]);
    }

    return 0;
}