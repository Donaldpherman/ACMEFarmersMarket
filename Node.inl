#include "Node.h"
#include <assert.h>
#include <algorithm>

template<class T>
Node<T>::Node(Node<T>* parent, T data) : parent_(parent), data_(data)
{
}

template<class T>
Node<T>::Node(const Node<T>* other)
{
    data_ = other->get_data();
    if (other->get_parent())
        parent_ = new Node(other->get_parent());
    else
        parent_ = nullptr
    children_(other->children_);
}

template<class T>
Node<T>& Node<T>::operator=(const Node<T>* other)
{
    if (this == &other)
        return *this;
    data_ = node->get_data();
    if (other->get_parent())
        parent_ = new Node<T>(other->get_parent());
    else
        parent_ = nullptr;
    for (child : other->children_)
        children_.push_back(new Node<T>(child));
}

template<class T>
Node<T>::~Node()
{
    for (Node<T>* childNode : children_)
        delete childNode;
}

template<class T>
const T& Node<T>::GetData() const
{
    return data_;
}

template<class T>
void Node<T>::SetData(const T& data)
{
    data_ = data;
}

template<class T>
void Node<T>::AddChild(const T& data)
{
    for (Node<T>* child : children_)
        if (child->data_ == data)
            return;
    
    children_.push_back(new Node<T>(this, data));
}

template<class T>
void Node<T>::RemoveChild(const size_t& indx)
{
    assert(indx < children_.size() && indx >= 0);
    if (indx >= children_.size() || indx < 0)
        return;
    auto it = children_.erase(children.begin() + indx);
    delete it;
}

template<class T>
Node<T>* Node<T>::FindChild(const T& data) const
{
    for (size_t i = 0; i < children_.size(); i++)
        if (children_[i]->GetData() == data)
            return children_[i];
    return nullptr;
}

template<class T>
Node<T>* Node<T>::GetChild(const size_t& indx) const
{
    assert(indx < children_.size() && indx >= 0);
    if (indx >= children_.size() || indx < 0)
        return;
    return children_[indx];
}

template<class T>
const Node<T>* Node<T>::GetParent() const
{
    return parent_;
}

template<class T>
int Node<T>::GetNumChildren() const
{
    return children_.size();
}

template<class T>
int Node<T>::GetDepthOfNode() const
{
    Node<T>* top = parent_;
    int depth = 0;
    while (top != nullptr)
    {
        top = top->parent_;
        depth++;
    }
        return depth;
}

template<class T>
const Node<T>* Node<T>::FindRootOfTheTree() const
{
    const Node<T>* root = this;
    while (root->parent_ != nullptr)
        root = root->parent_;
    return root;
}

template<class T>
std::string Node<T>::PrintTree() const
{
    const Node<T>* root = FindRootOfTheTree();
    std::string output;
    PrintTree(root, output);
    return output;
}

template<class T>
std::string Node<T>::PrintLeaves() const
{
    const Node<T>* root = FindRootOfTheTree();
    std::string output;
    PrintLeaves(root, output);
    return output;
}

template<class T>
std::string Node<T>::Find(const T& data) const
{
    const Node<T>* top = FindRootOfTheTree();
    std::string output;
    Find(top, data, output);
    return output;
}

template<class T>
Node<T>* Node<T>::FindNodeInTree(Node<T>* node, const T& data)
{
    assert(node);
    if (node == nullptr)
        return nullptr;
    if (node->data_ == data)
        return node;
    Node<T>* childNode = node->FindChild(data);
    if (childNode != nullptr)
        return childNode;
    for (Node<T>* child : node->children_)
    {
        Node<T>* node = FindNodeInTree(child, data);
        if (node != nullptr)
            return node;
    }
    return nullptr;
}

template<class T>
void Node<T>::PrintTree(const Node<T>* top, std::string& outString)
{
    int depth = top->GetDepthOfNode();
    for (int i = 0; i < depth; ++i)
        outString.append("-");
    outString.append(top->GetData());
    outString.append("\n");
    for (Node<T>*child : top->children_)
        PrintTree(child, outString);
}

template<class T>
void Node<T>::PrintLeaves(const Node<T>* top, std::string& outString)
{
    if (top->GetNumChildren() == 0)
        outString.append(top->GetData() + "\n");
    else
    {
        for (Node<T>*child : top->children_)
            PrintLeaves(child, outString);
    }
}

template<class T>
void Node<T>::Find(const Node<T>* top, const T& name, std::string& outString)
{
    if (top->GetData() != name)
    {
        for (Node<T>* child : top->children_)
            Find(child, name, outString);
    }
    else
    {
        std::deque<T> toPrint;
        while (top != nullptr)
        {
            toPrint.push_front(top->GetData());
            top = top->parent_;
        }
        for (size_t i = 0; i < toPrint.size(); ++i)
        {
            outString.append(toPrint.at(i));
            if (i < toPrint.size() - 1)
                outString.append("-");
        }
        outString.append("\n");
    }
}
