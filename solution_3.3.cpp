#include <vector>
#include <utility>
#include <stack>
#include <iostream>

using namespace std;

template<typename T>
class multi_stack {
    static const int threshold = 3;
    vector<stack<T>> stacks;
    int _size = 0;
public:
    multi_stack<T>& push(T);
    T pop();
    int size() {return _size;}
};

template<typename T>
multi_stack<T>& multi_stack<T>::push(T t)
{
    ++_size;
    if (stacks.empty() || stacks.back().size() > threshold) {
        stack<T> s;
        s.push(t);
        stacks.push_back(move(s));
    } else {
        stacks.back().push(t);
    }
    return *this;
}

template<typename T>
T multi_stack<T>::pop()
{
    --_size;
    T t = stacks.back().top();
    stacks.back().pop();
    if (stacks.back().empty()) {
        stacks.erase(stacks.begin() + (stacks.size() - 1));
    }
    return t;
}

template<typename T>
void print_s(multi_stack<T>& s)
{
    int size = s.size();
    cout << "size : " << size << endl;
    for (int i=0; i<size; ++i) {
        cout << s.pop() << endl;
    }
}

int main()
{
    multi_stack<int> s;
    s.push(7).push(4).push(3).push(1).push(1).push(3).push(9).push(7);
    print_s(s);
}

