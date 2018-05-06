#include "stdafx.h"
#include "Test.h"
#include "Tree.h"
#include <iostream>
#include <fstream>

Test::Test()
{
    testStringForPrintTree = "TOP\n"
        "-FRUITS\n"
        "--RED\n"
        "---STRAWBERRIES\n"
        "---APPLES\n"
        "----ADANAC APPLES\n"
        "----AKERO APPLES\n"
        "----AKANE APPLES\n"
        "-----LARGE\n"
        "-----SMALL\n"
        "--GREEN\n"
        "---GRAPES\n"
        "---PEARS\n"
        "--YELLOW\n"
        "---BANANAS\n"
        "-VEGETABLES\n"
        "--ROOTS\n"
        "--HERBS\n"
        "--BEANS\n"
        "--LEAFY VEGETABLES\n"
        "---LETTUCE\n"
        "---SPINACH\n"
        "----SAVOY\n"
        "----FLAT SPINACH\n"
        "----SEMI-SAVOY\n";

    testStringForPrintLeaves = "STRAWBERRIES\n"
        "ADANAC APPLES\n"
        "AKERO APPLES\n"
        "LARGE\n"
        "SMALL\n"
        "GRAPES\n"
        "PEARS\n"
        "BANANAS\n"
        "ROOTS\n"
        "HERBS\n"
        "BEANS\n"
        "LETTUCE\n"
        "SAVOY\n"
        "FLAT SPINACH\n"
        "SEMI-SAVOY\n";

    testStringForFind = "TOP-FRUITS-YELLOW-BANANAS\n";

    testStringForFindDuplicate = "TOP-FRUITS-RED-APPLES\n"
        "TOP-FRUITS-GREEN-APPLES\n";
}

void Test::run_tests()
{
    Test test;
    test.PrintTree_test();
    test.PrintLeaves_test();
    test.Find_test();
    test.Find_test__duplicate();
}

void Test::PrintTree_test() const
{
    Tree tree;
    std::ifstream fileStream("data.txt");
    if (!fileStream.is_open())
    {
        perror("failed on file open data.txt");
        return;
    }
    tree.ParseStream(fileStream);
    std::string outPut = tree.PrintTree();
    if (outPut != testStringForPrintTree)
        std::cout << ("Error in PrintTree_test\n");

}

void Test::PrintLeaves_test() const
{
    Tree tree;
    std::ifstream fileStream("data.txt");
    if (!fileStream.is_open())
    {
        perror("failed on file open data.txt");
        return;
    }
    tree.ParseStream(fileStream);
    std::string outPut = tree.PrintLeaves();
    if (outPut != testStringForPrintLeaves)
        std::cout << ("Error in PrintLeaves_test\n");
}

void Test::Find_test() const
{
    Tree tree;
    std::ifstream fileStream("data.txt");
    if (!fileStream.is_open())
    {
        perror("failed on file open data.txt");
        return;
    }
    tree.ParseStream(fileStream);
    std::string outPut = tree.Find("BANANAS");
    if (outPut != testStringForFind)
        std::cout << ("Error in Find_test\n");
}

void Test::Find_test__duplicate() const
{
    Tree tree;
    std::ifstream fileStream("dataTwo.txt");
    if (!fileStream.is_open())
    {
        perror("failed on file open dataTwo.txt");
        return;
    }
    tree.ParseStream(fileStream);
    std::string outPut = tree.Find("APPLES");
    if (outPut != testStringForFindDuplicate)
        std::cout << ("Error in Find_test__duplicate\n");
}
