#include <unordered_set>
#include <string>

using namespace std;

#pragma mark - solutions

bool all_unique(const string& str)
{
    unordered_set<char> char_set;
    for (int i=0; i<str.length(); ++i) {
        if (char_set.count(str[i]) == 1) {
            return false;
        }
        char_set.insert(str[i]);
    }
    return true;
}

bool all_unique_2(string& str)
{
    if (str.length() == 0) return true;

    sort(str.begin(), str.end());
    for (int i=0; i<str.length() - 1; ++i) {
        if (str[i] == str[i+1]) {
            return false;
        }
    }
    return true;
}

#pragma mark - test code

template<typename F>
bool test_string(string& str, F&& f)
{
    printf("%s\n", str.c_str());
    bool unique = f(str);
    printf("%s\n", unique?"unique":"not unique");
    return unique;
}

int main()
{
    string test_string_1 = "abcd";
    string test_string_2 = "abbd";
    string test_string_3 = "";
    string test_string_4 = "HgH";
    test_string(test_string_1, all_unique);
    test_string(test_string_2, all_unique);
    test_string(test_string_3, all_unique);
    test_string(test_string_4, all_unique);
    
    test_string(test_string_1, all_unique_2);
    test_string(test_string_2, all_unique_2);
    test_string(test_string_3, all_unique_2);
    test_string(test_string_4, all_unique_2);

    return 0;
}
    


