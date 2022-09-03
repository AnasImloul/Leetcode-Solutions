// Runtime: 1 ms (Top 93.52%) | Memory: 42.1 MB (Top 54.01%)
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int i = 0;
        int j = 0;
        int m = name.length();
        int n = typed.length();

        while(j < n)
        {
            if(i < m && name.charAt(i) == typed.charAt(j))
            {
                i++;
                j++;
            }
            else if(j > 0 && typed.charAt(j) == typed.charAt(j-1))
            {
                j++;
            }
            else
            {
                return false;
            }
        }

        return i == m;
    }
}