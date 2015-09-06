#include <iostream>
#include <forward_list>

using namespace std;

template<typename T>
forward_list<T> reversed(const forward_list<T>& l)
{
    forward_list<T> ret;
    for (auto elem : l) {
        ret.push_front(elem);
    }
    return ret;
}

bool is_palindrome(const forward_list<char>& l)
{
    if (l.empty()) return true;

    auto rev = reversed(l);

    auto it = l.begin();
    auto it2 = rev.begin();

    while (it != l.end()) {
        if ( *it != *it2 ) return false;
        ++it;
        ++it2;
    }

    return true;
}

template<typename T>
void print_l(const forward_list<T>& l)
{
    for (auto& elem : l) {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    forward_list<char> l = {'a','b','b','a'};
    forward_list<char> l2 = {'a','b','c','a'};

    print_l(l);
    if (is_palindrome(l)) {
        cout << "palindrome" << endl;
    } else {
        cout << "not palindrome" << endl;
    }

    print_l(l2);
    if (is_palindrome(l2)) {
        cout << "palindrome" << endl;
    } else {
        cout << "not palindrome" << endl;
    }
}

