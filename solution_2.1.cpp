#include <list>
#include <iostream>
#include <unordered_set>
#include <iterator>

using namespace std;

template<typename T>
void remove_duplicates(list<T>& l)
{
    unordered_set<T> witnesses;
    auto it=l.begin();
    while (it!=l.end()) {
        if (witnesses.count(*it) !=0) {
            it = l.erase(it);
        } else {
            witnesses.insert(*it);
            ++it;
        }
    }
}

template<typename T>
void remove_duplicates_2(list<T>& l)
{
    auto it = l.begin();
    while (it != l.end()) {
        auto runner = next(it);
        while (runner != l.end()) {
            if (*runner == *it) {
                runner = l.erase(runner);
            } else {
                ++runner;
            }
        }
        ++it;
    }
}

template<typename T>
void print_list(const list<T>& l)
{
    cout << "{";
    for (auto& elem : l) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}

int main()
{
    list<int> l = {1,2,2,3,2,4,5,2,3,7};
    print_list(l);
    //remove_duplicates(l);
    remove_duplicates_2(l);
    print_list(l);
}


    

