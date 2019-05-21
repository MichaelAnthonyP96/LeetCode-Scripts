class Solution {
    public int reverse(int x) {
        int ret = 0;
        if(x < 0 ){
            ret = -1 * (x % 10);
            ret /= 10;
        }
        else{
            ret = x % 10;
            ret /= 10;
        }
        while(x != 0){
            int a = x % 10;
            x /= 10;
            if(ret > (Integer.MAX_VALUE / 10) ) return 0;
            if(ret < (Integer.MIN_VALUE / 10) ) return 0;
            else{
                ret = (ret * 10) + a;
            }
        }
    return ret;
    }
}