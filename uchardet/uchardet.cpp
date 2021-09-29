#include "uchardet.h"

#include "libucd.h"

#include <iostream>

Uchardet::Uchardet()
{
}

bool Uchardet::parse(const char *content, int len, std::string &code_name)
{
    bool ok = true;

    ucd_t handle;
    ucd_init(&handle);

    ucd_parse(&handle, content, len);
    ucd_end(&handle);

    char name[40];
    if(UCD_RESULT_OK == ucd_results(&handle, name, 40) ) {
        code_name.assign(name);
    } else {
        std::cout << "parse context code failed, set to utf-8";
        code_name = "UTF-8";
        ok = false;
    }

    ucd_clear(&handle);

    return ok;
}
