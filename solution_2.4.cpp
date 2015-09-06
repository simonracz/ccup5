#include <iostream>
#include <forward_list>
#include <iterator>

using namespace std;

template<typename T>
void print_l(const forward_list<T>& l)
{
    for (auto& elem : l) {
        cout << elem << " ";
    }
    cout << endl;
}

template<typename T>
void partition(forward_list<T>& l, T value)
{
    if (l.empty()) return;

    forward_list<T> upper;
    auto position = upper.before_begin();
    auto it = l.before_begin();
    auto it2 = l.begin();
    for (;;) {
        if (*it2 >= value) {
            upper.splice_after(position, l, it);
            position = it2;
            it2 = next(it);
            if (it2 == l.end()) break;            
        } else {
            ++it;
            ++it2;
            if (it2 == l.end()) break;
        }
    }
    l.splice_after(it, upper);
}

int main()
{
    forward_list<int> l = {1,7,9,8,8,5,2,1,5,4,2,3,4,5};
    print_l(l);
    partition(l, 5);
    print_l(l);    
}
