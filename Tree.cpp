#include "stdafx.h"
#include "Tree.h"

#include <vector>
#include <sstream>
#include "Node.h"
#include <iostream>

Tree::Tree(): topOfTree(nullptr)
{
}

Tree::~Tree()
{
    delete topOfTree;
}

void Tree::setup_line(const std::string& line)
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
        Node<std::string>* parentNode = Node<std::string>::find_node_in_tree(topOfTree, parentData);
        if (parentNode == nullptr)
        {
            parentNode = new Node<std::string>(nullptr, parentData);
            topOfTree = parentNode;
        }
        parentNode->add_child(childData);
    }
    else
        topOfTree = new Node<std::string>(nullptr, childData);
}

bool Tree::parse_stream(std::istream& stream)
{
    std::string line;
    while (std::getline(stream, line))
    {
        setup_line(line);
    }
    return true;
}

std::string Tree::PrintTree() const
{
    return topOfTree->PrintTree();
}

std::string Tree::PrintLeaves() const
{
    return topOfTree->PrintLeaves();
}

std::string Tree::Find(const std::string& name) const
{
    return topOfTree->Find(name);
}
