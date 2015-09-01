#include <string>
#include <iostream>

using namespace std;

void reverse_string(string& str)
{
    if (str.length() < 2) return;

    int length = str.length();
    for (int i=0; i<length / 2; ++i) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return;
}

int main()
{
    string test_string_1 = "abcdefg";
    string test_string_2 = "";
    string test_string_3 = "ab";

    reverse_string(test_string_1);
    cout << test_string_1 << endl;
    reverse_string(test_string_2);
    cout << test_string_2 << endl;
    reverse_string(test_string_3);
    cout << test_string_3 << endl;
}



