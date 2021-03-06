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
#include <queue>
#include <sstream>

using namespace std;

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
    /*Given a binary tree, find its maximum depth.The maximum depth is the number of nodes along the longest
     *path from the root node down to the farthest leaf node.
     */
    //base case with no node
    if(root == NULL) return 0;
    //base case with node with no children
    else if(root->left == NULL && root->right == NULL) return 1;
    //otherwise search for one plus the max depth of the children nodes
    else return fmax( 1 + maxDepth(root->left), 1 + maxDepth(root->right) );
}

bool TreeNodeUtilities::isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    queue<TreeNode*> q;
    q.push(root);
    while(true){
        unsigned long c = q.size();
        if(c == 0) break; //no more nodes to process
        std::deque<int> dq;//double sided queue
        TreeNode* tmp = NULL;
        //while c is greater than 0
        while(c--){
            TreeNode* curr = q.front();
            q.pop();
            tmp = curr;
            if(!curr){
                dq.push_back(-1); continue;
            }
            dq.push_back(curr->val);
            q.push(curr->left);
            q.push(curr->right);
        }
        if(tmp != root && (dq.size()&1)) return false;
        while(tmp != root && dq.size()){
            if(dq.back() != dq.front()) return false;
            dq.pop_front();
            dq.pop_back();
        }
    }
    return true;
}

void TreeNodeUtilities::trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void TreeNodeUtilities::trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* TreeNodeUtilities::stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }
    
    string item;
    stringstream ss;
    ss.str(input);
    
    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    
    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        
        if (!getline(ss, item, ',')) {
            break;
        }
        
        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        
        if (!getline(ss, item, ',')) {
            break;
        }
        
        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

//Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
//The binary search tree is guaranteed to have unique values.
int TreeNodeUtilities::rangeSumBST(TreeNode* root, int L, int R) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL){
        if(root->val >= L && root->val <= R){
            return root->val;
        }else{
            return 0;
        }
    }else{
        if(root->val >= L && root->val <= R){
            return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        }else{
            return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        }
    }
}

//A binary tree is univalued if every node in the tree has the same value.
bool TreeNodeUtilities::isUnivalTree(TreeNode* root) {
    if(root == NULL) return true;
    if(root->right != NULL){
        if(root->val != root->right->val)
            return false;
    }
    if(root->left != NULL){
        if(root->val != root->left->val)
            return false;
    }
    return isUnivalTree(root->right) && isUnivalTree(root->left);
}

TreeNode* TreeNodeUtilities::searchBST(TreeNode* root, int val) {
    //if(root == NULL) return root;
    while(root != NULL && root->val != val){
        if(val < root->val)
            root = root->left;
        else if(val > root->val){
            root = root->right;
        } else {
            return root;
        }
    }
    return root;
}

bool TreeNodeUtilities::isLeaf(TreeNode* root){
    if(root == NULL) return false;
    else if(root->left != NULL){
        return false;
    } else if(root->right != NULL){
        return false;
    } else {
        return true;
    }
}

int TreeNodeUtilities::sumOfLeftLeaves(TreeNode* root) {
    if(root == NULL) return 0;
    if(isLeaf(root->left)){
        return root->left->val + sumOfLeftLeaves(root->right);
    } else {
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
}
