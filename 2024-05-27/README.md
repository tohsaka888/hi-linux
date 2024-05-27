## STDIN and STDOUT

标准输入（Standard Input）和标准输出（Standard Output）是计算机程序与外部环境进行交互的基本机制，尤其在命令行环境中非常常见。它们通常被简称为 `stdin` 和 `stdout`。

### 标准输入（stdin）

标准输入是程序从外部环境（通常是键盘或文件）接收输入数据的通道。默认情况下，标准输入是键盘输入，但可以通过重定向从文件或其他输入源读取数据。

在编程中，标准输入通常与文件描述符 `0` 相关联。

#### 示例

在C语言中，可以使用 `scanf` 或 `getchar` 从标准输入读取数据：

```c
#include <stdio.h>

int main() {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    return 0;
}
```

在Python中，可以使用 `input` 函数从标准输入读取数据：

```python
name = input("Enter your name: ")
print(f"Hello, {name}!")
```

### 标准输出（stdout）

标准输出是程序向外部环境（通常是屏幕或文件）输出数据的通道。默认情况下，标准输出是屏幕显示，但可以通过重定向将输出写入文件或其他输出设备。

在编程中，标准输出通常与文件描述符 `1` 相关联。

#### 示例

在C语言中，可以使用 `printf` 向标准输出打印数据：

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

在Python中，可以使用 `print` 函数向标准输出打印数据：

```python
print("Hello, World!")
```

### 重定向

在命令行中，可以使用重定向操作符将标准输入和标准输出重定向到文件或其他命令。

#### 输入重定向

将文件内容作为标准输入：

```bash
program < input.txt
```

#### 输出重定向

将标准输出写入文件：

```bash
program > output.txt
```

#### 管道（Pipe）

将一个命令的标准输出作为另一个命令的标准输入：

```bash
command1 | command2
```

### 总结

- **标准输入（stdin）**：程序从外部环境接收输入数据的通道，默认是键盘输入。
- **标准输出（stdout）**：程序向外部环境输出数据的通道，默认是屏幕显示。

通过理解和使用标准输入和标准输出，可以更灵活地控制程序的输入和输出，尤其在命令行环境中。