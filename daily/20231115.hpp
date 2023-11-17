/*
题目：
在一个二维数组中，每一行按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include <iostream>

bool Find(int* matrix, int rows, int columns, int number) {
    if (nullptr == matrix || rows <= 0 && columns <= 0) return false;
    bool found = false;
    int row = rows - 1;
    int column = 0; // 从左下角开始搜索
    while (row >= 0 && column < columns - 1) {
        if (matrix[row * columns + column] == number) return true;
        else if (matrix[row * columns + column] < number) {
            column++;  // 比左下角大的数只会在右边
        }
        else {
            row--;  // 比左下角小的数只会在上面
        }
    }
    return found;
}

