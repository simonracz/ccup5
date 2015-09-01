#include <string>
#include <iostream>

using namespace std;

string compress(const string& str)
{
    if (str.length() < 1) return str;

    string ret;
    char previous = str[0];
    int count=1;
    for (int i=1; i<str.length(); ++i) {
        if (previous == str[i]) {
            ++count;
            continue;
        }
        if (count > 1) {
            ret += previous + to_string(count);
        } else {
            ret += previous;
        }
        previous = str[i];
        count = 1;
    }
    
    if (count > 1) {
        ret += previous + to_string(count);
    } else {
        ret += previous;
    }
    
    if (ret.length() < str.length()) {
        return ret;
    }
    
    return str;
}

int main() {
    cout << compress("aaabccaaad") << endl;
    cout << compress("aabccaad") << endl;
    cout << compress("") << endl;
    cout << compress("a") << endl;
}
