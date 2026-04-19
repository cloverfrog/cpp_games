## 所需工具

vscode+gcc+make

## eaysx

在 [EasyX](https://easyx.cn/easyx) 官网可下载 [EasyX_for_MinGW](https://go.easyx.cn/easyx-for-mingw)

编译时使用参数 `-I<Path to Easyx>/include -L<Path to Easyx>/lib64 -leasyx` 进行链接，`Path to Easyx` 是下载的 easyx 库文件目录，可以是相对路径

其中：

- `-I` 告诉预处理器去哪里找头文件  
- `-L` 告诉链接器去哪里找 `.a`
- `-leasyx` 指定具体库名

## vscode 配置

为了让 vscode 能够识别 esayx 库以给出代码提示，需要配置 `.vscode/c_cpp_properties.json` 文件，在 `includePath` 中添加 esayx 库文件的 `include` 目录，可以是相对路径

配置 `.vscode/settings.json` 文件，添加 `"files.encoding": "gbk"`，以使中文字符正常显示，非要用 `utf-8` 的话会非常麻烦，会有踩不完的坑。

## Cmake 方式

使用 scoop 安装的 gcc+make+cmake 三件套，不要安装 mingw，会出现莫名其妙的问题

写好 Cmake 后，调用

```bash
cmake -S . -B build -G "Unix Makefiles"
make -C build
```