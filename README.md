# CPrimer
C++笔记

## 类
### 聚合类
        1、所有成员都是public的
        2、没有定义任何构造函数
        3、没有类内初始值
        4、没有基类，也没有virtual函数
### IO 条件状态
        badbit                  用来指出流已经崩溃
        failbit                 用来指出一个IO操作失败
        eofbit                  用来指出流达到了文件结束
        goodbit                 用来指出流未处于错误状态
        cin.eof() cin.fail() cin.bad() cin.good()
        cin.clear()             将流中的所有状态复位
        cin.clear(flags)        将流中的指定状态复位
        cin.setstate(flags)     将指定的状态置位
        cin.rdstate()           返回当前流的状态
        enum _Ios_Iostate
        { 
            _S_goodbit 		= 0,
            _S_badbit 		= 1L << 0,
            _S_eofbit 		= 1L << 1,
            _S_failbit		= 1L << 2,
            _S_ios_iostate_end = 1L << 16,
            _S_ios_iostate_max = __INT_MAX__,
            _S_ios_iostate_min = ~__INT_MAX__
        };
### 缓冲区刷新条件
        1、程序正常结束
        2、缓冲区满
        3、使用endl、flush、ends(输出一个空字符，然后刷新缓冲区);
        4、使用标志unitbuf(开启立即刷新)、nounitbuf(关闭立即刷新)
        5、关联流，主动关联的流执行之前，会刷新被关联的流，例如：cin关联到cout，在执行cin从终端接收输入之前，会先刷新cout的缓冲区（场景：输出提示语句，提示用户输入，然后获取用户的输入，如果没有关联的话，会导致等待用户输入，然而提示语句没有输出，应该保证等待用户输入之前就先输出用户提示）
        s.tie()没有参数，返回s关联的流。例如cin.tie()，返回的是cout
        s.tie(&stream)，关联流，s关联新的流stream，并返回旧的流。(每个流同时最多关联一个流，但是可以同时被很多其他流关联)
### IO继承关系
        1、istream和ostream继承ios
        2、iostream继承于istream和ostream
        3、fstream和sstream继承于iostream
        4、ifstream和istringstream继承于istream
        5、ofstream和ostringstream继承于ostream
## 顺序容器
### 顺序容器类型
        1、vector       可变大小数组，支持快速随机访问。在尾部之外的位置插入删除元素很慢
        2、array        固定大小数组，支持快速随机访问，不能添加或删除元素
        3、string       与vector相似的容器，但专门用于保存字符，随机访问快，在尾部插入删除快
        4、deque        双端队列，支持快速随机访问，在头尾部插入删除快
        5、list         双向链表，只支持双向顺序访问，在任意位置插入删除操作速度都很快
        6、forward_list 单向链表，只支持单向顺序访问，在任意位置插入删除操作速度都很快
### 容器适配器
        1、stack                底层一般是deque封装，但可以自己指定底层容器
        2、queue                底层一般是deque封装，但可以自己指定底层容器
        3、priority_queue       底层一般是vector封装，但可以自己指定底层容器
### 泛型算法
        大多数算法在头文件algorithm，也有在numeric中
#### 只读算法
        1、find()
        2、accumulate() 在numeric中
        3、equal()
#### 写容器元素算法
        1、fill()/fill_n()
        2、copy()
        3、replace()/replace_copy()
#### 重排容器元素的算法
        1、sort
        2、unique       返回的是不重复元素的下一个位置的迭代器
        3、transform
#### 定制操作
        谓词：一个可调用的表达式、其返回结果是一个能用作条件的值
        一元谓词：接受一个参数
        二元谓词：接受两个参数
        stable_sort()   稳定排序算法，在字符串排序过程中能保证字典顺序
        lambda表达式    不能有默认参数，对于值拷贝捕获的变量，在lambda表达式内部是不允许修改的，如果要修改则需要再（）后面加入mutable
        for_each()
        bind()          可以修改函数的参数个数以及更改参数顺序
        ref()           返回一个对象，包含给定的引用，此对象是可以拷贝的。cref()
### 迭代器
        每个容器自带的迭代器才是真正的迭代器，而下面的四种迭代器，具有迭代器的性质的同时也具有适配器的性质，因此应该是迭代器适配器
#### 插入迭代器
        back_inserter
        front_inserter
        inserter
#### 流迭代器
        istream_iterator
        ostream_iterator
#### 反向迭代器
#### 移动迭代器
## 关联容器
### map
#### map
#### multimap
#### unordered_map
#### unordered_multimap
### set
#### set
#### multiset
#### unordered_set
#### unordered_multiset