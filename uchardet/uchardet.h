#ifndef UCHARDET_H
#define UCHARDET_H

#include "uchardet_global.h"
#include <string>

class UCHARDET_EXPORT Uchardet
{
public:
    Uchardet();

    // 功能说明：判断传入字符串的编码类型
    // parameter:
    // [in] content: 需要检测的文本内容
    // [in] len: 检测的文本长度。实际上，并不需要全部的字符才能推断出编码类型，可以截断类型
    // [out] code_name: 返回的编码类型。判断失败默认为utf-8
    static bool parse(const char * content, int len, std::string &code_name);
};

#endif // UCHARDET_H
