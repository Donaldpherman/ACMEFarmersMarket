#include "Node.h"
#include <assert.h>

template<class T>
Node<T>::Node(Node<T>* parent, T data) : parent_(parent), data_(data)
{
}

template<class T>
Node<T>::Node(Node<T>* node)
{
    data_ = node->get_data();
    if (node->get_parent() == nullptr)
        parent_ = nullptr
    else
        parent_ = new Node(node_->get_parent());
    children_(children_);
}

template<class T>
Node<T>& Node<T>::operator=(const Node<T>* node)
{
    data_ = node->get_data();
    parent_ = node_->get_parent();
    children_ = node->children;
}

template<class T>
Node<T>::~Node()
{
    for (Node<T>* childNode : children_)
        delete childNode;
}

template<class T>
const T& Node<T>::get_data() const
{
    return data_;
}

template<class T>
void Node<T>::set_data(const T& data)
{
    data_ = data;
}

template<class T>
void Node<T>::add_child(const T& data)
{
    children_.push_back(new Node<T>(this, data));
}

template<class T>
void Node<T>::remove_child(const size_t& indx)
{
    children_.erase(children.begin() + indx);
}

template<class T>
Node<T>* Node<T>::find_child(const T& data) const
{
    for (unsigned i = 0; i < children_.size(); i++)
        if (children_[i]->get_data() == data)
            return children_[i];
    return nullptr;
}

template<class T>
Node<T>* Node<T>::get_child(const size_t& indx) const
{
    return children_[indx];
}

template<class T>
Node<T>* Node<T>::get_parent() const
{
    return parent_;
}

template<class T>
int Node<T>::get_num_children() const
{
    return children_.size();
}

template<class T>
int Node<T>::get_depth_of_node() const
{
    Node<T>* top = parent_;
    unsigned int depth = 0;
    while (top != nullptr)
    {
        top = top->parent_;
        depth++;
    }
        return depth;
}

template<class T>
const Node<T>* Node<T>::find_top_of_the_tree() const
{
    const Node<T>* top = this;
    while (top->parent_ != nullptr)
        top = top->parent_;
    return top;
}

template<class T>
std::string Node<T>::PrintTree() const
{
    const Node<T>* top = find_top_of_the_tree();
    std::string output;
    PrintTree(top, output);
    return output;
}

template<class T>
std::string Node<T>::PrintLeaves() const
{
    const Node<T>* top = find_top_of_the_tree();
    std::string output;
    PrintLeaves(top, output);
    return output;
}

template<class T>
std::string Node<T>::Find(const std::string& name) const
{
    const Node<T>* top = find_top_of_the_tree();
    std::string output;
    Find(top, name, output);
    return output;
}

template<class T>
Node<T>* Node<T>::find_node_in_tree(Node<T>* node, const T& data)
{
    assert(node);
    if (node == nullptr)
        throw "find_child_in_tree invalid parameter";
    if (node->data_ == data)
        return node;
    Node<T>* childNode = node->find_child(data);
    if (childNode != nullptr)
        return childNode;
    for (Node<T>* child : node->children_)
    {
        Node<T>* node = find_node_in_tree(child, data);
        if (node != nullptr)
            return node;
    }
    return nullptr;
}

template<class T>
void Node<T>::PrintTree(const Node<T>* top, std::string& outString)
{
    unsigned int depth = top->get_depth_of_node();
    for (unsigned int i = 0; i < depth; ++i)
        outString.append("-");
    outString.append(top->get_data());
    outString.append("\n");
    for (Node<T>*child : top->children_)
        PrintTree(child, outString);
}

template<class T>
void Node<T>::PrintLeaves(const Node<T>* top, std::string& outString)
{
    if (top->get_num_children() == 0)
    {
        outString.append(top->get_data() + "\n");
    }
    else
    {
        for (Node<T>*child : top->children_)
            PrintLeaves(child, outString);
    }
}

template<class T>
void Node<T>::Find(const Node<T>* top, const std::string& name, std::string& outString)
{
    if (top->get_data() != name)
    {
        for (Node<T>* child : top->children_)
            Find(child, name, outString);
    }
    else
    {
        std::deque<T> toPrint;
        while (top != nullptr)
        {
            toPrint.push_front(top->get_data());
            top = top->parent_;
        }
        for (unsigned int i = 0; i < toPrint.size(); ++i)
        {
            outString.append(toPrint.at(i));
            if (i < toPrint.size() - 1)
                outString.append("-");
        }
        outString.append("\n");
    }
}
