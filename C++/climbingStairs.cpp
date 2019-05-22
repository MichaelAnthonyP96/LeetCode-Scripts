class Solution {
public:
    int climbStairs(int n) {
        /*You are climbing a stair case. It takes n steps to reach to the top. Each time you can either 
         *climb 1 or 2 steps. In how many distinct ways can you climb to the top? Note: Given n will be a
         *positive integer.
         */
        if(n == 1) return 1; //base case of 1
        if(n == 2) return 2; //base case of 2
        unsigned int* array = new unsigned int[n]; //declare unsigned int array of size n
        array[0] = 1; //base case of 1
        array[1] = 2; //base case of 2
        //Iteratively populate the int array using the previous two terms. Since you can reach the stair
        //in question by taking x number of ways to get to stair i-1 and y number of ways to get to i-2,
        //to get to stair i all x and y number of ways are valid because you can take those paths and then 
        //another one or two stairs respectively
        for(int i = 2; i < n; i++){
            array[i] = array[i-1] + array[i-2];
        }
        return array[n-1];
    }
};