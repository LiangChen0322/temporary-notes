# 未整理问题

┌ARM不同模式
└x86不同模式

┌用户态和内核态的切换
└内核栈公用问题

http://www.cnblogs.com/justcxtoworld/p/3155741.html
http://www.cnblogs.com/Anker/p/3269106.html

┌内核线程
└用户线程

#函数调用堆栈结构

参考资料
http://www.csee.umbc.edu/~chang/cs313.s02/stack.shtml
http://www.tenouk.com/Bufferoverflowc/Bufferoverflow2a.html



#Linux进程的虚拟地址空间最低的地址设置为reserved

观察Linux进程的虚拟地址空间会发现，32位进程是从0x8048000开始，64位进程是从0x40000开始。

http://stackoverflow.com/questions/2187484/why-is-the-elf-execution-entry-point-virtual-address-of-the-form-0x80xxxxx-and-n

