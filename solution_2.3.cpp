#include <forward_list>
#include <iostream>

using namespace std;

template<typename T>
void erase_middle(forward_list<T>& l)
{
    auto it = l.begin();
    auto runner = l.begin();
    for (int i=0; i<2 && runner!=l.end(); ++i) {
        ++runner;
    }
    while (runner != l.end()) {
        ++runner;
        if (runner != l.end()) {
            ++runner;
            ++it;
        }
    }
    l.erase_after(it);
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

template<typename T>
void test(forward_list<T>& l)
{
    print_list(l);
    erase_middle(l);
    print_list(l);
}

int main()
{
    forward_list<int> l = {1,2,3,4,5,6,7,8,9,10};
    forward_list<int> l2 = {1,2,3,4,5,6,7,8,9,10,11};

    test(l);
    test(l2);
}
