class Solution {
    public int romanToInt(String s) {
        int ret = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == 'I'){
                if( (i+1) == s.length()){
                    ret += 1;
                    break;
                }
                else if(s.charAt(i+1) == 'V'){
                    ret += 4;
                    i++;
                    continue;
                }
                else if(s.charAt(i+1) == 'X'){
                    ret += 9;
                    i++;
                    continue;
                }
                else{
                    ret += 1;
                    continue;
                }
            }
            else if(s.charAt(i) == 'X'){
                if( (i+1) == s.length()){
                    ret += 10;
                    break;
                }
                else if(s.charAt(i+1) == 'L'){
                    ret += 40;
                    i++;
                    continue;
                }
                else if(s.charAt(i+1) == 'C'){
                    ret += 90;
                    i++;
                    continue;
                }
                else{
                    ret += 10;
                    continue;
                }
            }
            else if(s.charAt(i) == 'C'){
                if( (i+1) == s.length()){
                    ret += 100;
                    break;
                }
                else if(s.charAt(i+1) == 'D'){
                    ret += 400;
                    i++;
                    continue;
                }
                else if(s.charAt(i+1) == 'M'){
                    ret += 900;
                    i++;
                    continue;
                }
                else{
                    ret += 100;
                    continue;
                }
            }
            else if(s.charAt(i) == 'V') ret += 5;
            else if(s.charAt(i) == 'L') ret += 50;
            else if(s.charAt(i) == 'D') ret += 500;
            else if(s.charAt(i) == 'M') ret += 1000;
        }
    return ret;
    }
}