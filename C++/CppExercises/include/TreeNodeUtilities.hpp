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

class TreeNodeUtilities{
public:
    static bool isSameTree(TreeNode* p, TreeNode* q);
    static int maxDepth(TreeNode* root);
};

#endif /* TreeNodeUtilities_hpp */
