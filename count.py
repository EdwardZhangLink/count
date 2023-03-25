# -*- coding: UTF-8 -*-

import os
from pandas import read_csv

dict = os.getcwd()
num_list = read_csv(dict + 'source.csv')
# num_list = [123, 456, 789, 123, 246]
char_dict = {}
# 将数字拆分成单个字符并统计出现次数
for num in num_list:
    for char in str(num):
        if char in char_dict:
            char_dict[char] += 1
        else:
            char_dict[char] = 1
# 输出统计结果
for key, value in char_dict.items():
    print(key, ":", value)