//
//  main.cpp
//  CppExercises
//
//  Created by Michael Anthony Pope on 6/4/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include <iostream>
//#include "ListNode.hpp"
//#include "ListNodeUtilities.hpp"
#include "TreeNode.hpp"
#include "TreeNodeUtilities.hpp"

int main(int argc, const char * argv[]) {
    
    std::string j = "[1,2,2,3,4,4,3]";
    TreeNode* t = TreeNodeUtilities::stringToTreeNode(j);
    TreeNodeUtilities::isSymmetric(t);
    /*const char** v = argv;
    std::cout << v[3] << std::endl;
    std::cout << argc << std::endl;
    */
    
    /*ListNode* ptr = ListNodeUtilities::integerToLinkedList(321);
    while(ptr != NULL){
        std::cout << ptr->val << std::endl;
        ptr = ptr->next;
    }
     */
}

