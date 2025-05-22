### 所有东西写完再检查容器模版
- [x] 深拷贝和传引用是无关的 深拷贝的责任在T类型本身
```
值传递时的拷贝行为：
当通过值传递对象时，会触发对象的拷贝构造函数。
```
- [ ] 操作系统分配内存，内存对齐是什么
- [ ] C++内存管理
- [ ] this
> this 指针指向正在被创建的对象，通过 this 指针可以访问和初始化该对象的数据成员。在其他非静态成员函数中，this 指针指向调用该成员函数的对象。
- [ ] this指针
- [ ] 为什么插入一定要一个头指针，空链表插入必须要头指针，List类中必须要有ListNode*的对象
- [x] 指针作为函数参数传递时只能作为值传递
` 然指针允许修改指向的数据，但指针本身是通过值传递的。如果在函数内部修改指针的值（例如让它指向其他内存），不会影响原始指针 `
- [ ] 函数参数作为指针的指针
- [ ] 借助函数指针遍历
- [ ] 下面代码
```
 template <typename T> void List<T>::traverse ( void ( *visit ) ( T& ) )
2 {  for ( ListNodePosi(T) p = header->succ; p != trailer; p = p->succ ) visit ( p->data );  } 
3  
4 template <typename T> template <typename VST> //元素类型、操作器 
5 void List<T>::traverse ( VST& visit )
6 {  for ( ListNodePosi(T) p = header->succ; p != trailer; p = p->succ ) visit ( p->data );  }
```
- [x] List 和vector 梳理过后再回看
- [ ] 一定回看链表问题
- [ ] C++ RALL 与 智能指针
