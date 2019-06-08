//
//  main.cpp
//  PointersLab
//
//  Created by Michael Anthony Pope on 6/6/19.
//  Copyright © 2019 Michael Anthony Pope. All rights reserved.
//

#include <iostream>

//Create a function called PassByValue that accepts an integer argument.
void passByValue(int num);
//Create a function called PassByRef that accepts a reference variable as an argument
void passByReference(int& num);

int main(int argc, const char * argv[]) {
    /*In your main() function, create two variables.  One variable needs to be an intrinsic integer variable
     *named num1 and the second needs to be a pointer to an int variable that you will call pNum.(Note,
     *pNum should NOT be a pointer to num1 which means you need to create another variable for pNum to point
     *to.)
     */
    int num1;
    int num2;
    int* pNum = &num2;
    //Assign the value 3 to num1.
    num1 = 3;
    //Assign the value 5 to the memory location stored in pNum.
    *pNum = 5;
    //Call PassByValue and pass in num1 as the argument.
    passByValue(num1);
    //After the call returns to main(), output the value of num1 to the console window again.
    std::cout << "num1 is the value: " << num1 <<std::endl;
    //Call PassByRef and send pNum as the argument.
    passByReference(*pNum);
    //After the call returns to main(), output the value of pNum to the console.
    std::cout << "The vale of pNum is: " << *pNum << std::endl;
    
    return 0;
}

void passByValue(int num) {
    //Inside PassByValue, output a text string indicating the name of the function you are in.
    std::cout << "In function passByValue" << std::endl;
    //Modify the value of num1 inside the PassByValue function and output the new value to the console window.
    num+=4;
    std::cout << "The value of num is: " << num << std::endl;
}

void passByReference(int& num) {
    //Output a statement indicating the current function name.
    std::cout << "In function passByReference" << std::endl;
    //Modify the value of pNum, setting it to 50,  and output the value to the console.
    num = 50;
    std::cout << "The value of num is: " << num << std::endl;
}
