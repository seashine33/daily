# Emoji
- [Emoji官网](https://emojipedia.org/)
💡
👀
😀

# 组合
+ Python 提供隐式的[字符串连接](https://docs.python.org/2/reference/lexical_analysis.html#string-literal-concatenation), 例如,
  ```C++
  >>> print("wtf" "python")
  wtfpython
  >>> print("wtf" "") # or "wtf"""
  wtf
  ```
+ `'''` 和 `"""` 在 Python中也是字符串定界符, Python 解释器在先遇到三个引号的的时候会尝试再寻找三个终止引号作为定界符, 如果不存在则会导致 `SyntaxError` 异常.

# 创建目录：
- vscode下Markdown插件
```
> Create Table of Contents
```
# 改变字体颜色
<span style="color: brown;">这是一段棕色文本</span>  
<span style="color: red;">这是一段红色文本</span>  
<span style="color: orange;">这是一段橙色文本</span>  
<span style="color: yellow;">这是一段黄色文本</span>  
<span style="color: green;">这是一段绿色文本</span>  
<span style="color: blue;">这是一段蓝色文本</span>  
<span style="color: purple;">这是一段紫色文本</span>  
<span style="color: pink;">这是一段粉色文本</span>  

# 标签
> [!IMPORTANT]
> This is an important message.

> [!NOTE]
> This is a note.

> [!TIP]
> This is a tip.

> [!WARNING]
> This is a warning message.

> [!ERROR]

> [!ATTENTION]
> This is an attention message.



# 标题
几个#就是几级标题

# 段落
空一行

再一行

# 换行
后面加两空格  
再加一行

# 文字效果
可以在语句中加入**加粗部分**。  
也可以加入*斜线*。  
~~这是删除线。~~也就是两个~中间的部分。  


# 引用
在段落前加>符号
> This is a blockquote with two paragraphs. Lorem ipsum dolor sit amet,
consectetuer adipiscing elit. Aliquam hendrerit mi posuere lectus.
Vestibulum enim wisi, viverra nec, fringilla in, laoreet vitae, risus.

> Donec sit amet nisl. Aliquam semper ipsum sit amet velit. Suspendisse
id sem consectetuer libero luctus adipiscing.

> This is the first level of quoting.
>
> > This is nested blockquote.
>
> Back to the first level.

> ## 这是一个标题。
>
> 1.   这是第一行列表项。
> 2.   这是第二行列表项。
>
> 给出一些例子代码：
>
>     return shell_exec("echo $input | $markdown_script");

# 分点
这是第一种方法  
- 这是第一点
- 这是第二点
- 第三点
  - asd

* shi
  * asd
    * asd

这是第二种方法  
1. 第一部分
   1. 1.1部分
      1. 1.1.1部分
   2. 1.2部分
2. 第二部分
3. 第三部分

# 代码
如果是段落中的代码，可以用`int a = 10;`表示出来。  
如果是整段的代码，可以指定语言  
```C
int a = 10;
for(int i=0; i<10; i++){
    printf("%d", i);
}
```

# 分割线
分割线1
***
分割线2
---
分割线3
___
当然，三种分割线渲染效果都一样

# 表格
自动填充: Alt + Shift + F
| Syntax    | Description |
| --------- | ----------- |
| Header    | Title       |
| Paragraph | Text        |

# 链接语法
这是一个链接 [Markdown语法](https://markdown.com.cn)。

给链接增加Title，
这是一个链接 [Markdown语法](https://markdown.com.cn "最好的markdown教程")。

直接用尖括号    
<https://markdown.com.cn>  
<fake@example.com>


带格式化的链接  
I love supporting the **[EFF](https://eff.org)**.  
This is the *[Markdown Guide](https://www.markdownguide.org)*.  
See the section on [`code`](#code).  

这个链接用 1 作为网址变量 [Google][1]
这个链接用 runoob 作为网址变量 [Runoob][runoob]
然后在文档的结尾为变量赋值（网址）

  [1]: http://www.google.com/
  [runoob]: http://www.runoob.com/

用%20代替空格
[link](https://www.example.com/my%20great%20page)

# 图片
插入图片Markdown语法代码
```
![图片alt](图片链接 "图片title")
```

注意这是本地图片  
![这是图片](./img/philly-magic-garden.jpg "Magic Gardens")

添加链接  
[![沙漠中的岩石图片](./img/shiprock.jpg "Shiprock")](https://markdown.com.cn)

# 转义字符
加反斜杠\*, \`，以此类推。

# 内嵌HTML
This **word** is bold. This <em>word</em> is italic.

This is a regular paragraph.

<table>
    <tr>
        <td>Foo</td>
    </tr>
</table>

This is another regular paragraph.