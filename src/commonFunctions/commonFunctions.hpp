#if !defined(COMMONFUNCTIONS_HPP)
#define COMMONFUNCTIONS_HPP

#include <vector>
#include <string>
#include <sstream>

using namespace std;

constexpr unsigned int str2int(const char *str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

vector<string> myStrTok(const string str);

bool checkInt(string arg);

bool is_valid_float(const string &str);

#include "./commonFunctions.cxx"

#endif // COMMONFUNCTIONS_HPP
