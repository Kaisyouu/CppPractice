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

int main() {
    int a[4][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int* no_such = nullptr;
    std::cout << Find(a[0], 4, 4, 7) << std::endl;
    std::cout << Find(a[0], 4, 4, 3) << std::endl;
    std::cout << Find(no_such, 4, 4, 3) << std::endl;
    std::cout << Find(a[0], 0, 1, 3) << std::endl;
}
