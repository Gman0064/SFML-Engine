#include <string>
#include <iostream>

#include "../include/node.h"
#include "../include/util.h"
#include "../include/game_object.h"


std::string Util::gen_uid() {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(uid_len);

    for (int i = 0; i < uid_len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}


void ClearTerm() {
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

//https://stackoverflow.com/questions/52146507/how-do-we-print-out-the-value-type-of-a-c-stl-container
// template <typename T> 
// std::string getTypeName() {
//     auto name = typeid(T()).name();  // function type, not a constructor call!
//     int status = 0;

//     std::unique_ptr<char, void(*)(void*)> res {
//         abi::__cxa_demangle(name, NULL, NULL, &status),
//         std::free
//     };

//     std::string ret((status == 0) ? res.get() : name);
//     if (ret.substr(ret.size() - 3) == " ()") ret.resize(ret.size() - 3);
//     return ret;
// }