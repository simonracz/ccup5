#include <memory>

using namespace std;

template<typename D>
class Tree
{
public:
    struct Node {
        Node* parent = nullptr;
        unique_ptr<Node> left;
        unique_ptr<Node> right;
        D data;
        Node(D data) : data(data) {};
        Node(Node* parent, D data) : parent(parent), data(data) {};
    };
private:
    unique_ptr<Node> _root;
    Node& find_impl(const D& data, Node& root);
    bool is_left_child(const Node& node);
public:
    Node* add(const D& data);
    void remove(const D& data);
    void remove(Node* it);
    Node* find(const D& data);
};

template<typename D>
Tree::Node* Tree<D>::add(const D& data)
{
    if (_root == nullptr) {
        _root = make_unique<Node>(data);
        return _root.get();
    }
        
    auto node = find_impl(data, *_root.get());

    if (data > node.data) {
        node.right = make_unique<Node>(&node, data);
        return node.right.get();
    } else if (data < node.data) {
        node.left = make_unique<Node>(&node, data);
        return &node.left.get();
    }
    return &node;
}

template<typename D>
void Tree<D>::remove(const D& data)
{
    if (!_root) return;

    auto node = find_impl(data, *_root.get());
    if (node.data == data) {
        remove(&node);
    }
}

template<typename D>
Node* Tree<D>::find(const D& data)
{
    if (!_root) return nullptr;

    auto node = find_impl(data, *_root.get());
    if (node.data == data) {
        return &node;
    }
    return nullptr;
}

template<typename D>
Node& Tree<D>::find_impl(const D& data, Node& root)
{
    if (data < root.data) {
        if (root.left) {
            return *find_impl(data, *root.left.get()).get();
        } else {
            return root;
        }
    } else if (data > root.data) {
        if (root.right) {
            return *find_impl(data, *root.right.get()).get();
        } else {
            return root;
        }
    }
    return root;
}

template<typename D>
bool is_left_child(const Node& node)
{
    if (node.parent->left.get() == &node) {
        return true;
    }
    return false;
}
    
void Tree<D>::remove(Node* it)
{
    if (!it->left) {
        if (!it->parent) {
            _root.swap(it->right);
            _root->parent = nullptr;
            it->right.release();
            delete it;
            return;
        } else {
            if (is_left_child(*it)) {
                            
        }







        

