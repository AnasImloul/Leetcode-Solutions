class Solution {
    public String countAndSay(int n) {
        String res = "1";
        while(n > 1) {
            res = generateString(res);
            n--;
        }
        return res;
    }
    
    private String generateString(String s) {
        if (s.length() == 1) return "" + 1 + s;
        int counter = 1;
        StringBuilder res = new StringBuilder("");
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) counter++;
            else {
                res.append(counter);
                res.append(s.charAt(i - 1));
                counter = 1;
            }
        }
        res.append(counter);
        res.append(s.charAt(s.length() - 1));
        return res.toString();
    }
}
