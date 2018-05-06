# ACMEFarmersMarket
A C++ project giving to me by employer during a job interview

See Below for details:

Candidate Evaluation Assignment
Senior C++ Developer
Scenario
ACME Farmers Market has an online store through which various products are listed and organized by category. The
category layout is a tree structure. Each node can only have 1 parent and is capable of having 0 to n children.
Objective
Create a console app in C++ that will:
1. Read the attached text file, and create a tree data structure.
2. Implement the interface below and provide the correct results to each function.
Assumptions
• Each line is a node. The format is: ‘parent name’ | ‘new node name’.
• The input file is structed to build your tree as it is read. The parent to the new node will be the most recent
occurrence of that name.
// Interface
// Print out all nodes with 0 children
PrintLeaves();
// Find and print out node by name. If multiple with the same name return both.
Find(std::string name);
// Print out the full tree structure to the screen.
PrintTree()
Sample print output. Each level of the tree has an additional ‘-‘.
TOP
- FRUIT
-- RED
--- APPLE
--- STRAWBERRIES
-- GREEN
--- GRAPES
-- YELLOW
--- BANANA
Sample output for Find(BANANAS)
TOP-FRUITS-YELLOW-BANANAS
