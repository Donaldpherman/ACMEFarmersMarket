#pragma once
#include <string>
#include "Node.h"

class Tree
{
    // consider adding
    using StringNode = Node<std::string>;
    
    Node<std::string>* topOfTree;

public:
    Tree();
    ~Tree();

private:
    void setup_line(const std::string& line);

public:
    bool parse_stream(std::istream&);
    std::string PrintTree() const;
    std::string PrintLeaves() const;
    std::string Find(const std::string& name) const;
};
