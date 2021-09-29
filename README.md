# 基础功能
参考开源程序，整理的C++基础库。编译的工程为Qt。
## 文本识别
开源程序最初来自火狐社区的 universal chardet。后来这个模块不作为独立的模块。为了方便使用，前辈将此模块单独维护[cpp_libucd](https://github.com/yhfudev/cpp-libucd.git)。本项目在此基础上，将调用接口封装为一个单独的函数，适用于功能优化不是特别严苛的场合。封装后封装后的接口为
```c++
// 功能说明：判断传入字符串的编码类型
// parameter:
// [in] content: 需要检测的文本内容
// [in] len: 检测的文本长度。实际上，并不需要全部的字符才能推断出编码类型，可以截断类型
// [out] code_name: 返回的编码类型。判断失败默认为utf-8
 bool Uchardet::parse(const char * content, int len, std::string &code_name);
```


## 中文拼音输入
