#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class CMyString {
public:
    CMyString(char* pData = nullptr) {
        if (nullptr == pData) {
            m_pData = new char[1];
            m_pData[0] = '\0';
        }
        else {
            m_pData = new char[strlen(pData) + 1];
            strcpy(m_pData, pData);
        }
    }

    CMyString(const CMyString& str) {
        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);
    }

    ~CMyString() {
        if (nullptr != m_pData) {
            delete[] m_pData;
            m_pData = nullptr;
        }
    }

    string GetString() {
        return string(m_pData);
    }
// 实现CMyString类的赋值运算符函数
public:
    // 写法一：有4个注意点
    // 1. 返回值是引用，确保str1=str2=str3可以连续赋值
    // 2. 入参为常量引用，避免一次拷贝构造
    // 3. 如果自身已有内存，而在分配新的内存时忘记释放，则会造成内存泄漏
    // 4. 若传递参数和自身是同一个实例，则会在释放内存后访问该内存
    /*
    CMyString& operator=(const CMyString& str) {
        if (this == &str) return *this;
        delete[] m_pData;
        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);
        return *this;
    }
    */
    
    // 写法二：在第一个写法中，new内存可能失败，在之前以及删除了原来的内存。
    // 在这个写法中，局部变量会在作用域之外被释放。
    CMyString& operator=(const CMyString& str) {
        if (this != &str) {
            CMyString tmp(str);
            char* tmp_pData = tmp.m_pData;
            tmp.m_pData = m_pData;
            m_pData = tmp_pData;
        }
        return *this;
    }

private:
    char* m_pData;
};
int main() {
    char str1[] = "hello";
    CMyString my_str1(str1);
    CMyString my_str2 = my_str1;
    cout << my_str1.GetString() << endl;
    cout << my_str2.GetString() << endl;
}
