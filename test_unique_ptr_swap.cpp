#include <memory>
#include <iostream>

using namespace std;

struct sp_test_node
{
    sp_test_node* parent = nullptr;
    unique_ptr<sp_test_node> child;
    sp_test_node() { cerr << "constructor\n"; }
    ~sp_test_node() { cerr << "destructor\n"; }
};

int main()
{
    auto p = make_unique<sp_test_node>();    
    auto p2 = p.get();
    p->child = make_unique<sp_test_node>();
    p->child->parent = p2;
    
    p.swap(p->child);
    p->parent = nullptr;

    //crash (double free)
    //delete p2;
    
    //does not crash, but shouldn't it?
    //stack overflow?
    //p2->child.reset();
    
    //should work
    p2->child.release();
    delete p2;
}

