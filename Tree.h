#pragma once
#include <string>
#include "Node.h"

class Tree
{
    Node<std::string>* topOfTree; // rename to root

public:
    Tree();
    ~Tree();

private:
    void setup_line(const std::string& line); // Use CamelCase no '_' characer

public:
    bool parse_stream(std::istream&); // Use CamelCase no '_' characer
    std::string PrintTree() const;
    std::string PrintLeaves() const;
    std::string Find(const std::string& name) const;
};
