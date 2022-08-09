class Solution {
    private String result;
    public String findLexSmallestString(String s, int a, int b) {
        result = "z";
        HashSet<String> set = new HashSet<>();
        dfs(s, a, b, set);
        return result;
    }
    private void dfs(String s, int a, int b, HashSet<String> set) {
        if(set.contains(s))
            return;
        set.add(s);
        String s1, s2;
        s1 = addA(s, a);
        s2 = rotateB(s, b);
        dfs(s1, a , b, set);
        dfs(s2, a , b, set);
    }
    private String addA(String s, int a) {
        char c[] = s.toCharArray();
        int i, temp;
        for(i=1;i<s.length();i+=2) {
            temp = c[i] - '0';
            temp += a;
            temp = temp % 10;
            c[i] = (char)(temp + '0');
        } 
        s = new String(c);
        if(result.compareTo(s) > 0)
            result = s;
        return s;
    }
    private String rotateB(String s, int b) {
        if(b < 0)
            b += s.length();
        b = b % s.length();
        b = s.length() - b;
        s = s.substring(b) + s.substring(0, b);
        if(result.compareTo(s) > 0)
            result = s;
        return s;
    }
}
