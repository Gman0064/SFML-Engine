#include <string>

#ifndef UTIL_H
#define UTIL_H

class Util
{
    private:
        static const int uid_len = 6;
    public:
        static std::string gen_uid();
        static void ClearTerm();
};

#endif