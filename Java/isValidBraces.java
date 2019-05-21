import java.util.Stack;
class Solution {
    public boolean isValid(String s) {
        //check the empty case
        if(s.isEmpty() ){
            return true;
        }
        //convert to charArray
        char[] c = s.toCharArray();
        //creates stack to push and pop to
        Stack<Character> stk = new Stack<Character>();
        //iterate over all characters in the array
        for(int i = 0; i < c.length; i++){
            //if character is a left brace, push to the stack
            switch (c[i]){
                case '(':
                    stk.push('(');
                    break;
                case '{':
                    stk.push('{');
                    break;
                case '[':
                    stk.push('[');
                    break;
            //if character is a right brace then check that the previous character
            //is the corresponding correct left brace
                case ')':
                    if( !stk.isEmpty() && stk.pop() == '('){
                        break;
                    }
                    else{
                        return false;
                    }
                case '}':
                    if( !stk.isEmpty() && stk.pop() == '{'){
                        break;
                    }
                    else{
                        return false;
                    }
                case ']':
                    if( !stk.isEmpty() && stk.pop() == '['){
                        break;
                    }
                    else{
                        return false;
                    }
            }
        }
        //at this point stack must be empty, otherwise it is an unbalanced string
        if(stk.isEmpty()) return true;
        else return false;
    }
}