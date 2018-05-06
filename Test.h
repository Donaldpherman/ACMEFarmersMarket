#pragma once
#include <string>
class Test
{
    std::string buildingTheTree;
    std::string testStringForPrintTree;
    std::string testStringForPrintLeaves;
    std::string testStringForFind;
    std::string testStringForFindDuplicate;

public:
    Test();
    static void run_tests();
private:
    void PrintTree_test() const;
    void PrintLeaves_test() const;
    void Find_test() const;
    void Find_test__duplicate() const;
};
