#include "stdafx.h"
#include "Tree.h"

// good practice to sort your includes... include STL first then your own headers
#include <vector>
#include <sstream>
#include "Node.h"
#include <iostream>

Tree::Tree(): topOfTree(nullptr) // in new version of C++ you can assign topOfTree in your .h file
{
}

Tree::~Tree()
{
    delete topOfTree; // consider using std::unique_ptr<Node>
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

bool Tree::parse_stream(std::istream& stream) // you are using CamelCase and whatever this_weird_notation interchangably, keep it consistent
{
    std::string line;
    while (std::getline(stream, line))
    {
        setup_line(line);
    }
    return true;
}

std::string Tree::PrintTree() const // return const char*
{
    return topOfTree->PrintTree();
}

std::string Tree::PrintLeaves() const // return const char*
{
    return topOfTree->PrintLeaves();
}

std::string Tree::Find(const std::string& name) const // return const char*
{
    return topOfTree->Find(name);
}
