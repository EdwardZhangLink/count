#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001);
    int nums[10] = {0};  // 初始化数组，用于统计数字出现次数
    int num;

    // 循环读取数字并统计出现次数
    while (scanf("%d", &num) == 1) {
        if (num >= 0 && num <= 9) {  // 判断数字是否在合法范围内
            nums[num]++;
        }
    }

    // 使用冒泡排序法按出现次数从高到低排序
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (nums[i] < nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    // 输出排序结果
    printf("数字\t出现次数\n");
    for (int i = 0; i < 10; i++) {
        if (nums[i] > 0) {
            printf("%d\t%d\n", i, nums[i]);
        }
    }

    return 0;
}