#pragma once
#include <vector>
#include <deque>

template<class T>
class Node
{
    T data_;
    Node<T>* parent_;
    std::vector<Node<T>*> children_;
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

    std::string PrintTree() const;
    std::string PrintLeaves() const;
    std::string Find(const std::string& name) const;

    static Node<T>* find_node_in_tree(Node<T>* node, const T& data);

    static void PrintTree(const Node<T>* top, std::string& outString);
    static void PrintLeaves(const Node<T>* top, std::string& outString);
    static void Find(const Node<T>* top, const std::string& name, std::string& outString);

};
#include "Node.inl"
