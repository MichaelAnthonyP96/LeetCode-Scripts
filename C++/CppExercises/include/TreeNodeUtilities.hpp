//
//  TreeNodeUtilities.hpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/5/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef TreeNodeUtilities_hpp
#define TreeNodeUtilities_hpp

#include "TreeNode.hpp"
#include "string"

class TreeNodeUtilities{
public:
    static bool isSameTree(TreeNode* p, TreeNode* q);
    static int maxDepth(TreeNode* root);
    static bool isSymmetric(TreeNode* root);
    static void trimLeftTrailingSpaces(std::string &input);
    static void trimRightTrailingSpaces(std::string &input);
    static TreeNode* stringToTreeNode(std::string input);
    static int rangeSumBST(TreeNode* root, int L, int R);
    static bool isUnivalTree(TreeNode* root);
};

#endif /* TreeNodeUtilities_hpp */
