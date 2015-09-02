#include <iostream>
#include <string>

using namespace std;

//given method, unknown implementation
bool is_substring(const string& left, const string& right)
{
    return true;
}

bool is_rotation(const string& left, const string& right)
{
    if (left.length() != right.length()) return false;

    if (left.length() == 0) return false;

    if (is_substring(left, right + right)) {
        return true;
    }
    return false;
}


