#pragma once
#include <string>
#include "Node.h"

class Tree
{
    Node<std::string>* root = nullptr;

public:
    Tree();
    ~Tree();

private:
    void SetupLine(const std::string& line);

public:
    bool ParseStream(std::istream& stream);
    std::string PrintTree() const;
    std::string PrintLeaves() const;
    std::string Find(const std::string& name) const;
};
