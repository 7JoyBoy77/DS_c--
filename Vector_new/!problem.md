##Problem
* ��һ�δ��룺�ʺ����������У�_size ����ȷ��Ĭ�ϳ�ʼ���߼������ҿ��Ա�֤�ڵ��� copy ����֮ǰ _size �Ѿ�����ȷ��ʼ��Ϊ 0 ������������ַ�ʽ�Դ�����������Ҫ��ϸߣ�һ����ʼ���߼��������⣬�����������Ե��ԵĴ���
�ڶ��δ��룺���Ӱ�ȫ�ɿ������������ⲿ�ĳ�ʼ���߼����ܹ����������Ԫ�ظ��Ʋ�������ʵ�ʿ����У��Ƽ�ʹ��������ʽ��ʼ���ķ�ʽ���������ڶ���Э�����ߴ���ṹ��Ϊ���ӵ���Ŀ�С�
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
    // ˳���_capacity��ֵ��һ������
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo != hi)
    {
        _elem[_size++] = A[lo++];
    }
}
```
- [ ] ѧϰ������ģ�棬ָ�����ã�STLԴ��
- [X] C++ָ��������±������why�� 
```
    //new�����Ķ�̬���鱾���Ϸ�����һ���������ڴ棬
    //arr[i + 1] �ȼ��� *(arr +i + 1); �ڴ����������ҵĵ�
```
- [x] return ������
- [x] һ��Ҫ�ع�ʱ�临�Ӷȴ�O�ķ���
- [ ] C++20���е����ͱȽ�������ɾ����һЩ
- [x] ָ����������, Ϊʲôָ��������±꣬���ÿ���ֱ�Ӹ�ֵ�� T const *ָ�� `    _elem[r] = e; `
- [ ] �ڶ����������е�����ʧЧ��������ײ�ռ�ı�Ĳ��������п����ǵ�����ʧЧ,����posλ����һ�������������ȱ�֤��������Ŀռ��㹻������������Ƚ������ݣ���ô�������ݣ��ͻ�����ռ��Ų������ô�ͻ����ԭ��pos������ʧЧ�����⣬
```
template <typename T>
void Vector<T>::insert(const T &e, Rank r)
{
    //�Ƿ�����
    for (int i = _size; i > r; i--)
    {
        _elem[i] = _elem[i - 1];
    }
    _elem[r] = e;
    _size++;
}
```
- [x] ʱ�临�Ӷȵĸ�������Ͻ磬T(n), �����ѧ��ʽ
- [ ] Ϊʲô��ɾ�Ĳ飬Ψһ���������ǹؼ��Ĳ���
- [x] ��ָ��new֮��������ָ�봴����̬����
- [x] ��ʼ��һ��ջ�ϵ�����
` int stackArray[5] = {1, 2, 3, 4, 5};
    int* ptr = stackArray; `
    ��new����һ��heap�ϵ����鲻ͬ
```
    int* dynamicArray = new int[size];
```
- [ ] ������for-range����new���Ķ�̬����
>for range�޷�ͨ��ͷԪ��ָ��ȷ��������Χ
- [ ] ��������ͺ���ָ�����
- [ ] ��������߼�ת��Ϊ������Ҫ��ѭ"�ֽ����� �� ������ �� ����ʵ��"�Ĺ��̡�
```
    template <typename VST>
    void traverse(VST& visit) {
        for (int i = 0; i < _size; i++) {
            visit(_elem[i]);
        }
    }
};

// ����������ӡԪ��
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
- [ ] ���ʾ���У�PrintVisitor ��һ������������������ () ����������ڴ�ӡ�����Ԫ�ء��� main �����У�������һ�� Vector<int> ���� vec�������� traverse ���������� PrintVisitor ���� visitor���Ӷ�ʵ�ֶ� Vector ������Ԫ�صĴ�ӡ����

- [ ] һЩ��������������뿴�������Ķ������ʹ�ñ�ʶ�������磬����ģ�嶨������Ͷ��壬�����Ժ�γ������������ֶ��壩
- [ ] ÿ���ļ���Ӧ��ʽ��#include��Ҫ���������ͷ�ļ�����Ҫ�����ڴ�����ͷ�ļ����ݰ�����ͷ�ļ�
- [ ] ������� .h �� .cpp������ģ���࣬��Ҫ��ʵ�ַ��� .cpp �ļ��У���������ʽʵ�������п��ܵ����ͣ����Ƽ�����

- [ ] �� C++ �У�Ĭ�ϲ���ֻ���ں���������ָ��һ�Σ������������Ͷ������ظ�ָ����

- [ ] size() �� Vector �ĳ�Ա����������ͨ������ʵ�����ã�����ͨ������ֱ�ӵ��ã������Ǿ�̬��Ա�������� size() ��Ȼ���Ǿ�̬��

- [ ] ���⣺ȫ�ֺ��������� static ���Σ�static ��ȫ���������ʾ ���ڲ����ӡ�����ģ�庯����Ҫ�ⲿ���ӣ���
��������ܵ������Ӵ����� undefined reference����

- [ ] static ���β�ͬ�ı�����������Ա������ͬ

- [ ] print �� �Ǿ�̬��Ա�������亯��ָ������Ϊ void (Vector<T>::*)(T&)���� traverse �����Ĳ�������Ϊ void (*)(T&)����ͨ����ָ�룩�����߲����ݡ�
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
        // ����ָ����Func Func(_elem[i]) �÷�����
        visit(_elem[i]);
    }
}

```

- [ ] ����ָ����ʽ�����ã���ʽ������

- [ ] ����ָ��汾�Ǵ�ͳ C �����������ʺϼ���״̬�Ļص���
���Ϳɵ��ö���汾�� C++ ���ͱ�̵����֣�ͨ��ģ��֧�ָ����Ļص���ʽ�����ִ� C++ �Ƽ���������
```
template <typename T>
void Vector<T>::traverse(void (*visit)(T &))
{
    for (int i = 0; i < _size; i++)
    {
        // ����ָ����Func Func(_elem[i]) �÷�����
        // ��ʽ�����ã���ʽ������
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