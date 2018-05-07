#include "stdafx.h"
#include <vector>
#include <sstream>
#include <iostream>

#include "Tree.h"
#include "Node.h"

Tree::Tree(): root(nullptr)
{
}

Tree::~Tree()
{
    delete root;
}

void Tree::SetupLine(const std::string& line)
{
    std::stringstream ss(line);
    std::vector<std::string> tokens;
    std::string item;
    auto backInserter = std::back_inserter(tokens);
    while (std::getline(ss, item, '|'))
    {
        (backInserter++) = item;
    }
    std::string parentData = tokens.at(0);
    std::string childData = tokens.at(1);
    if (!parentData.empty())
    {
        Node<std::string>* parentNode = Node<std::string>::FindNodeInTree(root, parentData);
        if (parentNode == nullptr)
        {
            parentNode = new Node<std::string>(nullptr, parentData);
            root = parentNode;
        }
        parentNode->AddChild(childData);
    }
    else
        root = new Node<std::string>(nullptr, childData);
}

bool Tree::ParseStream(std::istream& stream)
{
    std::string line;
    while (std::getline(stream, line))
    {
        SetupLine(line);
    }
    return true;
}

std::string Tree::PrintTree() const
{
    return root->PrintTree();
}

std::string Tree::PrintLeaves() const
{
    return root->PrintLeaves();
}

std::string Tree::Find(const std::string& name) const
{
    return root->Find(name);
}
