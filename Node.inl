#include "Node.h"
#include <assert.h>

template<class T>
Node<T>::Node(Node<T>* parent, T data) : parent_(parent), data_(data)
{
}

template<class T>
Node<T>::Node(Node<T>* node) // in copy ctor you always pass const: Node<T>::Node(const Node<T>* other)
{
    data_ = node->get_data();
    if (node->get_parent() == nullptr) //  if (node->get_parent()) - this is c++
        parent_ = nullptr
    else
        parent_ = new Node(node_->get_parent());
    children_(children_); // what exactly does that do?
}

template<class T>
Node<T>& Node<T>::operator=(const Node<T>* node) // I would rename node->other
{
    // this is scary your copy ctor is a gateway to invalid memory
    data_ = node->get_data();
    parent_ = node_->get_parent(); // you are copying pointer to the same address
    children_ = node->children; // you are copying collection of pointers to the same address
    // consider what would happen when the node that you pass to this copy ctor is deleted
    // you are still pointing to the same address locations, but now the are invalid
}

template<class T>
Node<T>::~Node()
{
    for (Node<T>* childNode : children_) // just use smart pointers
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
    // check if already exists
    // something like:
    // if (!std::find_if(children_.begin(), children_.end(), [data](const Node<T>* node) -> { return node->data == data; }) {
    children_.push_back(new Node<T>(this, data));
}

template<class T>
void Node<T>::remove_child(const size_t& indx)
{
    children_.erase(children.begin() + indx); // what about calling delete on your removed node? Memory leak.
    // again if you used a shared_ptr here you wont have to worry about it
    // what if indx is greater than children collection?
}

template<class T>
Node<T>* Node<T>::find_child(const T& data) const
{
    for (unsigned i = 0; i < children_.size(); i++) // what is unsigned? use int or size_t
        if (children_[i]->get_data() == data)
            return children_[i];
    return nullptr;
}

template<class T>
Node<T>* Node<T>::get_child(const size_t& indx) const
{
    // again check if within bounds
    return children_[indx];
}

template<class T>
Node<T>* Node<T>::get_parent() const // ideally you would always return const Node<T>*
{
    return parent_;
}

template<class T>
int Node<T>::get_num_children() const // your '_' is giving me brain seizures...
{
    return children_.size();
}

template<class T>
int Node<T>::get_depth_of_node() const
{
    Node<T>* top = parent_;
    unsigned int depth = 0; // no reason for unsigned unless you are doing some funky performance/memory optimization, use int
    while (top != nullptr)
    {
        top = top->parent_;
        depth++;
    }
        return depth;
}

template<class T>
const Node<T>* Node<T>::find_top_of_the_tree() const // can combine it with function above
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
    return output; // return  PrintLeaves(top); - isn't that better? :)
}

template<class T>
std::string Node<T>::Find(const std::string& name) const // if you are onlt using it with strings remove template class altogether this is messy
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
        throw "find_child_in_tree invalid parameter"; // dont use throw, return nullptr or smth
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
    unsigned int depth = top->get_depth_of_node(); // unsigned int -> int
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
