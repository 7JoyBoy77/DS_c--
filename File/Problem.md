 - [ ] �ļ���ģ���࿴������Щ�ط��������
 - [ ] C++�е�������Ի��塣����ζ��������ļ������κ����ݶ����ܲ�������д����̡��෴�����ԶԶ����������ϲ�һ��������Ҫ�ǳ�������ԭ�򡣽�������д�����ʱ�����Ϊˢ�»�����������ˢ�»�������һ�ַ����ǹر��ļ����������������ݽ���ˢ�µ����̣�Ȼ���ļ������رա� ����������
 - [ ] C++�ļ�����дʱ��string��Ҫת��const char*
 ```
 //����ģ�C++����open����,C++ ��׼�ⲻ���ṩ���� C ����ַ�����const char*����Ϊ������ open ���������ṩ���� std::string ��Ϊ�����İ汾���� C++11 �������ı�׼��
 void open( const char *filename,
           ios_base::openmode mode = ios_base::in|ios_base::out );
(1)	
void open( const std::filesystem::path::value_type *filename,
           ios_base::openmode mode = ios_base::in|ios_base::out );
(2)	(C++17 ��)
void open( const std::string &filename,                                  
           ios_base::openmode mode = ios_base::in|ios_base::out );
 ```