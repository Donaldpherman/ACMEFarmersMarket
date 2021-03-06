// ACMEFarmerMarket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include <string>
#include "Tree.h"
#include "Test.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{

    std::string fileName;
    if (argc != 2)
    {
        std::cout << "Enter a file name: ";
        std::cin >> fileName;
    }
    else
        fileName = argv[1];

    if (fileName == "-t")
    {
        Test::run_tests();
        return 0;
    }

    std::cout << "* trying to open and read: " << fileName << std::endl;
    std::ifstream fileStream(fileName);
    if (!fileStream.is_open())
    {
        perror("failed on file open");
        return 1;
    }
    Tree tree;
    if (!tree.ParseStream(fileStream))
    {
        perror("Cannot open stream");
        return 1;
    }
    std::cout << "PrintTree()" << std::endl;
    std::cout << tree.PrintTree();
    std::cout << "PrintLeaves()" << std::endl;
    std::cout << tree.PrintLeaves();
    std::cout << "FIND(BANANAS)" << std::endl;
    std::cout << tree.Find("BANANAS") << std::endl;
    std::cout << "FIND(APPLES)" << std::endl;
    std::cout << tree.Find("APPLES");

    return 0;
}
