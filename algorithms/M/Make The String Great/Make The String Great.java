class Solution {
public String makeGood(String s) {
     char[] res = s.toCharArray();
    int i = 0;
    for( char n: s.toCharArray())
    {
        res[i] = n;
        
        if(i>0 && Math.abs((int) res[i-1]- (int) res[i])==32)
        {
            i-=2;
        }
        i++;
    }
    return new String(res, 0, i);
}
}
