#include <iostream>
// 有序唯一化
// 遍历n - 1个元素
// 判断是否相同
// 相同快指针继续走
// 不同慢指针走一步，赋值快指针处值
// 循环迭代，当快指针循环结束，从慢支针处截断
template <typename T>
void Unique(T *A, int lo, int hi)
{
    int fast = 0;
    int slow = 0;
    while (fast != (hi - lo))
    {
        if (A[fast] == A[slow])
        {
            fast++;
        }
        else
        {
            slow++;
            A[slow] = A[fast];
        }
    }
    // 截断指针
    // 代码注释提到 “截断指针”，但并没有实际的操作。
    // 这里的意图可能是想截断数组到去重后的有效长度，但在 C++ 中对于普通数组无法直接截断，一般通过返回有效长度来让调用者知道有效部分。
}
