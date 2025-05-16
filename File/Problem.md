 - [ ] 文件库模版类看看，那些地方还不理解
 - [ ] C++中的输出可以缓冲。这意味着输出到文件流的任何内容都可能不会立即写入磁盘。相反，可以对多个输出操作合并一起处理。这主要是出于性能原因。将缓冲区写入磁盘时，这称为刷新缓冲区。导致刷新缓冲区的一种方法是关闭文件——缓冲区的内容将被刷新到磁盘，然后文件将被关闭。 这里如何理解
 - [ ] C++文件流读写时，string需要转换const char*
 ```
 //错误的，C++重载open函数,C++ 标准库不仅提供了以 C 风格字符串（const char*）作为参数的 open 函数，还提供了以 std::string 作为参数的版本。在 C++11 及后续的标准中
 void open( const char *filename,
           ios_base::openmode mode = ios_base::in|ios_base::out );
(1)	
void open( const std::filesystem::path::value_type *filename,
           ios_base::openmode mode = ios_base::in|ios_base::out );
(2)	(C++17 起)
void open( const std::string &filename,                                  
           ios_base::openmode mode = ios_base::in|ios_base::out );
 ```