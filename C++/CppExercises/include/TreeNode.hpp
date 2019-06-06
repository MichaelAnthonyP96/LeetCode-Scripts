//
//  TreeNode.hpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/5/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

 struct TreeNode {
      const int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x);
  };

#endif /* TreeNode_hpp */
