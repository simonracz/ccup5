#include <forward_list>
#include <iostream>
#include <cassert>

using namespace std;

forward_list<int> add(const forward_list<int>& left, const forward_list<int>& right)
{
    forward_list<int> ret;
    auto pos = ret.before_begin();

    auto l_it = left.begin();
    auto r_it = right.begin();
    int remainder = 0;

    while (l_it != left.end()) {
        int sum = *l_it + *r_it + remainder;
        remainder = sum / 10;
        ret.insert_after(pos, sum % 10);
        ++pos;
        ++l_it;
        ++r_it;
    }
    if (remainder > 0) {
        ret.insert_after(pos, remainder);
    }
    return ret;
}

forward_list<int> reversed(const forward_list<int>& l)
{
    forward_list<int> ret;
    for (int elem : l) {
        ret.push_front(elem);
    }
    return ret;
}

forward_list<int> add_2(const forward_list<int>& left, const forward_list<int>& right)
{
    return reversed(add(reversed(left), reversed(right)));
}

void print_l(const forward_list<int>& l)
{
    for (int elem : l) {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    forward_list<int> l = {4,5,2,9};
    forward_list<int> r = {7,1,1,5};

    print_l(l);
    print_l(r);

    auto ret = add(l, r);

    print_l(ret);

    ret = add_2(l, r);

    print_l(ret);
}
      


