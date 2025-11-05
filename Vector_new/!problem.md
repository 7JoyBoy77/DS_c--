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
- [X] C++指针可以用下标操作，why？ 
```
    //new出来的动态数组本质上分配了一块连续的内存，
    //arr[i + 1] 等价于 *(arr +i + 1); 内存连续所以找的到
```
- [x] return 的作用
- [x] 一定要回顾时间复杂度大O的分析
- [ ] C++20中判等器和比较器被被删除了一些
- [x] 指针数组引用, 为什么指针可以用下标，引用可以直接赋值给 T const *指针 `    _elem[r] = e; `
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
- [x] 时间复杂度的概念，渐进上界，T(n), 相关数学公式
- [ ] 为什么增删改查，唯一化，排序是关键的操作
- [x] 对指针new之后，这是用指针创建动态数组
- [x] 初始化一个栈上的数组
` int stackArray[5] = {1, 2, 3, 4, 5};
    int* ptr = stackArray; `
    和new分配一个heap上的数组不同
```
    int* dynamicArray = new int[size];
```
- [ ] 不能用for-range遍历new出的动态数组
>for range无法通过头元素指针确定迭代范围
- [ ] 函数对象和函数指针机制
- [ ] 将事物的逻辑转化为代码需要遵循"分解问题 → 抽象步骤 → 代码实现"的过程。
```
    template <typename VST>
    void traverse(VST& visit) {
        for (int i = 0; i < _size; i++) {
            visit(_elem[i]);
        }
    }
};

// 操作器：打印元素
struct PrintVisitor {
    template <typename T>
    void operator()(const T& value) {
        std::cout << value << " ";
    }
};

int main() {
    Vector<int> vec(5);
    PrintVisitor visitor;
    vec.traverse(visitor);
    std::cout << std::endl;
    return 0;
}
```
- [ ] 这个示例中，PrintVisitor 是一个操作器，它重载了 () 运算符，用于打印传入的元素。在 main 函数中，创建了一个 Vector<int> 对象 vec，并调用 traverse 函数，传入 PrintVisitor 对象 visitor，从而实现对 Vector 中所有元素的打印操作

- [ ] 一些情况，编译器必须看到完整的定义才能使用标识符（例如，对于模板定义和类型定义，将在以后课程中讨论这两种定义）
- [ ] 每个文件都应显式地#include需要编译的所有头文件。不要依赖于从其他头文件传递包含的头文件
- [ ] 避免分离 .h 和 .cpp：对于模板类，不要将实现放在 .cpp 文件中，除非你显式实例化所有可能的类型（不推荐）。

- [ ] 在 C++ 中，默认参数只能在函数声明中指定一次，不能在声明和定义中重复指定。

- [ ] size() 是 Vector 的成员函数，必须通过对象实例调用，不能通过类名直接调用（除非是静态成员函数，但 size() 显然不是静态的

- [ ] 问题：全局函数不能用 static 修饰（static 在全局作用域表示 “内部链接”，但模板函数需要外部链接）。
后果：可能导致链接错误（如 undefined reference）。

- [ ] static 修饰不同的变量，函数成员方法不同

- [ ] print 是 非静态成员函数，其函数指针类型为 void (Vector<T>::*)(T&)，而 traverse 方法的参数类型为 void (*)(T&)（普通函数指针），两者不兼容。
```

template <typename T>
void Vector<T>::print(T &value)
{
    std::cout << value << std::endl;
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T &))
{
    for (int i = 0; i < _size; i++)
    {
        // 与其指向函数Func Func(_elem[i]) 用法无异
        visit(_elem[i]);
    }
}

```

- [ ] 函数指针隐式解引用，显式解引用

- [ ] 函数指针版本是传统 C 风格的延续，适合简单无状态的回调。
泛型可调用对象版本是 C++ 泛型编程的体现，通过模板支持更灵活的回调形式，是现代 C++ 推荐的做法。
```
template <typename T>
void Vector<T>::traverse(void (*visit)(T &))
{
    for (int i = 0; i < _size; i++)
    {
        // 与其指向函数Func Func(_elem[i]) 用法无异
        // 隐式解引用，显式解引用
        visit(_elem[i]);
    }
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST &visit)
{
    for (int i = 0; i < _size; i++)
    {
        visit(_elem[i]);
    }
}
```
- [ ] 这样new分出来的固定的空间 本质上在内存中连续，试用下标访问比较快
`    _elem = new T[capacity = 2 * (hi - lo)];`
