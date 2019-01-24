# EDD-STC 编程守约

这是一份 EDD-STC 开发人员的开发指引。团队协作开发，需要由不同
的人采用合作的方式完成，EDD-STC 的开发人员需遵守如下的编程约定。

## 1.编程工具

  ***语言***
  
    C89  

**为提高通用性，部分数据类型使用统一约定的数据类型别名，详见eddc51.h**

  ***IDE*** 
  
    Keil C51 V5以上版本
  
    Keil统一配置:  
        UTF-8编码格式           
        Tabsize：4  
        勾选 Insert spaces for tabs.  (即用空格替代Tab) 
 		  
  ***补充***  

    若采用其他文本编辑器编辑代码，请对以下内容进行统一:  
        编码格式：UTF-8
        设置Tab大小为4， 用空格替代Tab。

## 2.文件(含目录)名称

文件名称如果无特殊的需求(如果是引用其他地方，可以保留相应的名称)，使用全小写
的形式；名称应该能够反应部分的意思。另外为了避免文件名重名的问题，一些地方请尽量不要使用通用化、使用频率高
的名称。

## 3.头文件定义

C语言头文件为了避免多次重复包含，需要定义一个符号。这个符号的定义形式统一采用如下
的风格：

```c
    #ifndef __FILE_H__
    #define __FILE_H__
    /* header file content */
    #endif
```

即定义的符号两侧采用 "__" 以避免重名，另外也可以根据文件名中是否包含多个词语而
采用 "_" 连接起来.

## 4.文件头注释

在每个源文件文件头上，应该包括相应的版权信息，Change Log 记录：

```c
/**
  * ### Copyright (c) 2018，EDD-STC Development Team (eddstc1984@gmail.com).######
  * ### SPDX-License-Identifier: Apache-2.0 ######
  ********************************************************************************************
  * @file atkp.c
  * @version 0.1.0 
  * @brief none
  * @details none
  * @bug none
  * @warning none
  ********************************************************************************************
  *###Change Logs:
  *     Date        |   Author      |   Notes
  * ----------------|---------------|---------------------------------------------------------
  *     2018-11-18  |   GYC         |   the first version
***/
```

采用如上的形式。 （版本号向linux方式看齐，主 次 修改）

## 5.结构体定义

结构体名称请使用小写英文名的形式，单词与单词之间采用 "_" 连接，例如：

```c
    struct edd_list_node
    {
        struct rt_list_node *next;
        struct rt_list_node *prev;
    };
```

其中，"{"，"}" 独立占用一行，后面的成员定义使用缩进的方式定义。

结构体等的类型定义请以结构体名称加上 "_t" 或 "_st"的形式作为名称，例如：

```c
    typedef struct edd_list_node edd_list_t;
```

## 6.常量，宏定义，变量

请使用大写英文名称作为宏名、常量名，单词之间使用 "_" 连接.

变量名称应该有一定的自说明性

## 7.函数名称、声明

内部函数名称使用小写英文的形式，单词之间使用 "_" 连接，且建议用 "static"修饰，必要时可在其名称前加"_"。示例：

```c
    static int _swap_byte_of_halfword(uint16 *phalfword)
    {
      ...
    }
```

外部函数名称采用**小驼峰法标识**, 且必要时可在前加前缀。 示例：

```c
    void oled_pixelWrite(uint8_t xPixel, uint8_t yPixel, bool color)
    {
      ...
    }
```

或

```c
    void oledPixelWrite(uint8_t xPixel, uint8_t yPixel, bool color)
    {
      ...
    }
```

尽管可以使用上述两种方式， 但在同一源文件中应当统一使用一种形式。

提供给上层应用使用的 API接口（外部函数），必须在相应的头文件中声明；
如果函数入口参数是空，必须使用 void 作为入口参数.

## 8.注释编写

  ***注释风格***

    统一采用doxygen注释风格，部分示例：  
```c
    /// ...
    int var; 

    /*or*/

    int var; ///< ...

    /**
      * @brief ...
      * @param roll[in]: ...
      * @param pitch[out]: ...
      * @param yaw: ...
      * @param baro[in,out]: ...
      * @return ...
      */
    int atkp_sendStatus(int roll, int pitch, int yaw, int baro)
```

更多的注释用法详见doxygen官网

  ***注释语言***

    尽量使用英文做注释！！！

  ***注释原则***

    源代码的注释不应该过多，更多的说明应该是代码做了什么，仅当个别关键点才需要一些
    相应提示性的注释以解释一段复杂的算法它是如何工作的。对语句的注释只能写在它的上
    方或右方，其他位置都是非法的。

## 9.缩进及分行

缩进请采用 4 个空格的方式。如果没有什么特殊意义，请在 "{" 后进行分行，并在下一
行都采用缩进的方式，例如：

```c
    if (condition)
    {
        /* others */
    }
```
或者
```c
    if (condition) {
        /* others */
    }
```

唯一的例外是 swtich 语句，switch-case 语句**可以采用** case 语句与 swtich 对齐的方式，
例如：

```c
    switch (value)
    {
    case value1:
        break;
    }
```

case 语句与前面的 switch 语句对齐，后续的语句则采用缩进的方式。

分行上，如果没有什么特殊考虑，请**不要在代码中连续使用两个以上的空行**。

## 10.大括号与空格（不完全严格）

从代码阅读角度，建议每个大括号单独占用一行，而不是跟在语句的后面，例如：

```c
    if (condition)
    {
        /* others */
    }
```

匹配的大括号单独占用一行，代码阅读起来就会有相应的层次而不会容易出现混淆的情况。

空格建议在非函数方式的括号调用前留一个空格以和前面的进行区分，例如：

```c
    if (x <= y)
    {
        /* others */
    }

    for (index = 0; index < MAX_NUMBER; index ++)
    {
        /* others */
    }
```

建议在括号前留出一个空格(涉及的包括 if、for、while、swtich 语句)，而运算表达式
中，运算符与字符串间留一个空格。另外，不要在括号的表达式两侧留空格，例如：

```c
    if ( x <= y )
    {
        /* other */
    }
```

这样括号内两侧的空格是不允许的。

## 11.函数
通常认为，一个设计优良的函数不应该在内部直接使用外部变量(此指定义在函数之外的变量)。

函数应该尽量精简，仅完成相对独立的简单功能。函数的实现不应该太长
，函数实现太长，应该反思能够如何修改(或拆分)使得函数更为精简、易懂。


## 12. 用 astyle 自动格式化代码

    参数：--style=allman
          --indent=spaces=4
          --indent-preproc-block
          --pad-oper
          --pad-header
          --unpad-paren
          --suffix=none
          --align-pointer=name
          --lineend=linux
          --convert-tabs
          --verbose
