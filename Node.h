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
    Node(const Node<T>* other);
    Node<T>& operator=(const Node<T>* other);

    ~Node();

    const T& GetData() const;
    void SetData(const T& data);
    void AddChild(const T& data);
    void RemoveChild(const size_t& indx);
    Node<T>* FindChild(const T& data) const;
    Node<T>* GetChild(const size_t& indx) const;
    const Node<T>* GetParent() const;
    int GetNumChildren() const;
    int GetDepthOfNode() const;
    const Node<T>* FindRootOfTheTree() const;

    std::string PrintTree() const;
    std::string PrintLeaves() const;
    std::string Find(const T& data) const;

    static Node<T>* FindNodeInTree(Node<T>* node, const T& data);

    static void PrintTree(const Node<T>* top, std::string& outString);
    static void PrintLeaves(const Node<T>* top, std::string& outString);
    static void Find(const Node<T>* top, const T& data, std::string& outString);

};
#include "Node.inl"
