#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_LINE_LENGTH 1024 // 文件中最大的一行字符数

int main(void) {
    SetConsoleOutputCP(65001);
    char filename[256]; // 文件名
    printf("请输入CSV文件名：");
    scanf("%s", filename);
    FILE* fp = fopen(filename, "r"); // 打开文件
    if (!fp) {
        printf("文件打开失败！");
        return 1;
    }
    // 用数组统计每种字符出现次数
    int cnt[256] = {0};
    char line[MAX_LINE_LENGTH]; // 读取的一行字符
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) { // 逐行读取
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            cnt[(unsigned char)line[i]]++; // 数组下标要转成无符号char类型
        }
    }
    // 输出每种字符出现次数
    printf("每种字符出现次数：\n");
    for (int i = 0; i < 256; i++) {
        if (cnt[i] > 0) { // 只输出出现过的字符
            printf("%c: %d\n", (char)i, cnt[i]);
        }
    }
    fclose(fp); // 关闭文件
    getchar();
    getchar();
    return 0;
}