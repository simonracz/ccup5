#include <iostream>
#include <list>
#include <forward_list>
#include <cassert>

using namespace std;

//returns first element in case k>size(list)
template<typename T>
T find_last_kth(const forward_list<T>& l, int k)
{
    assert(k>=0);

    auto it = l.begin();
    for (int i=0; i<k; ++i) {
        if (it==l.end()) {
            return l.front();
        }
        ++it;
    }
    auto ret = l.begin();
    while (it!=l.end()) {
        ++it;
        ++ret;
    }
    return *ret;
}

template<typename T>
void print_list(const forward_list<T>& l)
{
    cout << "{";
    for (auto& elem : l) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}

int main()
{
    forward_list<int> l = {1,2,3,4,5,6,7,8,9,10};
    print_list(l);
    cout << "fifth from back: " << find_last_kth(l, 5) << endl;
    cout << "11th from back: " << find_last_kth(l, 11) << endl;
}



