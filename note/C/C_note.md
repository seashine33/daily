# TODO
## 函数
### vsprintf()
- https://blog.csdn.net/heybeaman/article/details/80495846
- #include <stdarg.h>
- 应对多个参数。

# 概念
## 内联函数是什么？有什么用？

# 知识点
## 数组初始化的安全性
- 对于全局数组，不初始化是安全的，因为C语言保证它们会被自动清零。
- 对于局部数组，如果未初始化，其值是未定义的，可能包含随机数据（垃圾值）。