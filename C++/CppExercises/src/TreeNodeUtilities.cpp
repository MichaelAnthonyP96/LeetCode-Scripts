//
//  TreeNodeUtilities.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/5/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include "TreeNodeUtilities.hpp"
#include "TreeNode.hpp"
#include <math.h>

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

int TreeNodeUtilities::maxDepth(TreeNode* root) {
    //base case with no node
    if(root == NULL) return 0;
    //base case with node with no children
    else if(root->left == NULL && root->right == NULL) return 1;
    //otherwise search for one plus the max depth of the children nodes
    else return fmax( 1 + maxDepth(root->left), 1 + maxDepth(root->right) );
}
