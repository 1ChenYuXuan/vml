# VML（虚拟机语言）

# 什么是VML？

## VML包含哪两个分支？
### BVML（基础虚拟机语言，Basic Virtual Machine Language）
### CVML（复合虚拟机语言，Complex Virtual Machine Language）

## 相比BVML，CVML新增了哪些特性？

## 第一点：核心组件CAPI
- CAPI是CVML的核心组成部分。
  *严禁使用CAPI实施任何破坏行为。*

绝大多数场景下，CAPI的安全性存在一定局限；在特殊场景中，甚至可能引发严重问题。但同时CAPI功能性极强，可显著提升程序的运行效率。

## 第二点：CAPI的全称
CAPI看起来类似C语言API（设计逻辑与Python3的API相近），但实际上，CAPI的全称是**C Plusplus API（即C++ API）**。

## VML语言的编译流程
实际上，编译器会先将VML代码编译为「VML编译格式」。
VML编译格式是一种类似x86_64汇编的编译产物，大部分代码都对应多字节的符号标识。VML虚拟机可读取这些字节码并执行，通常这些字节码会以文件形式存储在操作系统中。

随后，VML编译器会读取该文件，将其翻译为可执行的字节码。

- 更多内容请查阅 readme.txt 文件
