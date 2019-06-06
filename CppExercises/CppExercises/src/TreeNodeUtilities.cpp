//
//  TreeNodeUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/5/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "TreeNodeUtilities.hpp"
#include "TreeNode.hpp"

bool TreeNodeUtilities::isSameTree(TreeNode* p, TreeNode* q){
    if(p == NULL && q == NULL) return true; // base case of two empty trees
    else if( (p == NULL && q != NULL) || \
             (p != NULL && q == NULL)) return false; // base case where only one is empty
    else if(p->val != q->val) return false; // base case of unequal values
    // case which handles trees of different shapes
    else if( (p->left != NULL && q->left == NULL) || \
             (p->right != NULL && q->right == NULL) || \
             (p->left == NULL && q->left != NULL) || \
             (p->right == NULL && q->right != NULL) ) return false;
    else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
