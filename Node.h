#pragma once
#include <vector>
#include <deque>

// check out this, it can make your code look professional: http://en.cppreference.com/w/cpp/language/type_alias

template<class T>
class Node
{
    T data_; // wtf is this, a good c++ syntax is to prefix your class members with m_ e.g. m_data
    Node<T>* parent_; // m_parent
    std::vector<Node<T>*> children_; // m_children
public:
    Node(Node<T>* parent, T data);
    Node(Node<T>* node);
    Node<T>& operator=(const Node<T>* other);

    ~Node();

    const T& get_data() const;
    void set_data(const T& data);
    void add_child(const T& data);
    void remove_child(const size_t& indx);
    Node<T>* find_child(const T& data) const;
    Node<T>* get_child(const size_t& indx) const;
    Node<T>* get_parent() const;
    int get_num_children() const;
    int get_depth_of_node() const;
    const Node<T>* find_top_of_the_tree() const;

    std::string PrintTree() const; // return const char*
    std::string PrintLeaves() const; // return const char*
    std::string Find(const std::string& name) const; // return const char*

    static Node<T>* find_node_in_tree(Node<T>* node, const T& data);

    static void PrintTree(const Node<T>* top, std::string& outString); // why not just return as non-static functions too
    static void PrintLeaves(const Node<T>* top, std::string& outString);
    static void Find(const Node<T>* top, const std::string& name, std::string& outString);

};
#include "Node.inl"
