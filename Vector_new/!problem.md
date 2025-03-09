##Problem
* 第一段代码：适合在类的设计中，_size 有明确的默认初始化逻辑，并且可以保证在调用 copy 函数之前 _size 已经被正确初始化为 0 的情况。但这种方式对代码的整体管理要求较高，一旦初始化逻辑出现问题，容易引发难以调试的错误。
第二段代码：更加安全可靠，不依赖于外部的初始化逻辑，能够独立地完成元素复制操作。在实际开发中，推荐使用这种显式初始化的方式，尤其是在多人协作或者代码结构较为复杂的项目中。
```
template <typename T>
void Vector<T>::copy(T *const A, Rank lo, Rank hi)
{
    _elem = new T[capacity = 2 * (hi - lo)];
    while (lo != hi)
    {
        _elem[_size] = A[lo];
        lo++;
        _size++;
    }
}
```
```
template <typename T>
void Vector<T>::copyFrom(T *const A, Rank lo, Rank hi)
{
    // 顺便给_capacity赋值，一举两得
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo != hi)
    {
        _elem[_size++] = A[lo++];
    }
}
```
- [ ] 学习容器，模版，指针引用，STL源码
- [ ] C++指针可以用下标操作，why？ 
```
    //new出来的动态数组本质上分配了一块连续的内存，
    //arr[i + 1] 等价于 *(arr +i + 1); 内存连续所以找的到
```
- [ ] return 的作用
- [ ] 一定要回时间复杂度O的分析
- [ ] C++20中判等器和比较器被被删除了一些
- [ ] 指针数组引用, 为什么指针可以用下标，引用可以直接赋值给 T const *指针 `    _elem[r] = e; `
- [ ] 在对容器扩容中迭代器失效会引起其底层空间改变的操作，都有可能是迭代器失效,这里pos位置是一个迭代器。首先保证插入操作的空间足够，如果不够，先进行扩容，那么进行扩容，就会引起空间的挪动，那么就会造成原来pos迭代器失效的问题，
```
template <typename T>
void Vector<T>::insert(const T &e, Rank r)
{
    //是否扩容
    for (int i = _size; i > r; i--)
    {
        _elem[i] = _elem[i - 1];
    }
    _elem[r] = e;
    _size++;
}
```
- [ ] 时间复杂度的概念，渐进上界，T(n), 相关数学公式
- [ ] 为什么增删改查，唯一化，排序是关键的操作
- [ ] 对指针new之后，这是用指针创建动态数组
- [ ] 初始化一个栈上的数组
` int stackArray[5] = {1, 2, 3, 4, 5};
    int* ptr = stackArray; `
    和new分配一个heap上的数组不同
```
    int* dynamicArray = new int[size];
```
- [ ] 不能用for-range遍历new出的动态数组
- [ ] 函数对象和函数指针机制
- [ ] 将事物的逻辑转化为代码需要遵循"分解问题 → 抽象步骤 → 代码实现"的过程。
