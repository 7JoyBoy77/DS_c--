### ���ж���д���ټ������ģ��
- [ ] ����ʹ��������޹ص� �����������T���ͱ���
- [ ] ����ϵͳ�����ڴ棬�ڴ������ʲô
- [ ] C++�ڴ����
- [ ] this
> this ָ��ָ�����ڱ������Ķ���ͨ�� this ָ����Է��ʺͳ�ʼ���ö�������ݳ�Ա���������Ǿ�̬��Ա�����У�this ָ��ָ����øó�Ա�����Ķ���
- [ ] thisָ��
- [ ] Ϊʲô����һ��Ҫһ��ͷָ�룬������������Ҫͷָ�룬List���б���Ҫ��ListNode*�Ķ���
- [ ] ָ����Ϊ������������ʱֻ����Ϊֵ����
- [ ] ����������Ϊָ���ָ��
- [ ] ��������ָ�����
- [ ] �������
```
 template <typename T> void List<T>::traverse ( void ( *visit ) ( T& ) )
2 {  for ( ListNodePosi(T) p = header->succ; p != trailer; p = p->succ ) visit ( p->data );  } 
3  
4 template <typename T> template <typename VST> //Ԫ�����͡������� 
5 void List<T>::traverse ( VST& visit )
6 {  for ( ListNodePosi(T) p = header->succ; p != trailer; p = p->succ ) visit ( p->data );  }
```
- [ ] List ��vector ��������ٻؿ�
- [ ] C++ RALL��ʲô