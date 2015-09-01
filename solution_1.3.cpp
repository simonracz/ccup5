#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

bool is_permutation(const string& left, const string& right)
{
    if (left.length() != right.length()) return false;

    unordered_map<char, int> counter;
    for (int i=0; i<left.length(); ++i) {
        if (counter.count(left[i]) == 0) {
            counter[left[i]] = 1;
        } else {
            counter[left[i]] += 1;
        }
    }

    for (int i=0; i<right.length(); ++i) {
        if (counter.count(right[i]) == 0) {
            return false;
        } else {
            counter[right[i]] -= 1;
            if (counter[right[i]] == 0) counter.erase(right[i]);
        }
    }
    return true;
}

bool test_strings(const string& left, const string& right)
{
    bool ret_1 = is_permutation(left, right);
    printf("%s is %s of %s\n", left.c_str(), ret_1?"a permutation":"not a permutation", right.c_str());
    bool ret_2 = is_permutation(right, left);
    assert(ret_1 == ret_2);
    return ret_1;
}

int main() {
    string test_string_1a = "aaabcd";
    string test_string_1b = "bcaada";

    test_strings(test_string_1a, test_string_1b);
    test_strings("a", "b");
    test_strings("", "");
    test_strings("ab", "a");
}

