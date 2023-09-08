// Runtime: 952 ms (Top 21.5%) | Memory: 44.16 MB (Top 54.1%)

class Solution {
    int res = 0;
    
    public int maxProduct(String s) {
        char[] strArr = s.toCharArray();
        dfs(strArr, 0, "", "");
        return res;
    }

    public void dfs(char[] strArr, int i, String s1, String s2){
        if(i >= strArr.length){
            if(isPalindromic(s1) && isPalindromic(s2))
                res = Math.max(res, s1.length()*s2.length());
            return;
        }
        dfs(strArr, i+1, s1 + strArr[i], s2);
        dfs(strArr, i+1, s1, s2 + strArr[i]);
        dfs(strArr, i+1, s1, s2);
    }

    public boolean isPalindromic(String str){
        int j = str.length() - 1;
        char[] strArr = str.toCharArray();
        for (int i = 0; i < j; i ++){
            if (strArr[i] != strArr[j])
                return false;
            j--;
        }
        return true;
    }
}