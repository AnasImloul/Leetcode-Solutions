class Solution {
    List<Integer> dp[][];
    public List<Integer> diffWaysToCompute(String expression) {
        List<String> exp = new ArrayList<>();
        
        for(int i = 0; i < expression.length();) {
            char ch = expression.charAt(i);
            StringBuilder sb = new StringBuilder();
            
            if(ch >= '0' && ch <= '9') {
                if(i + 1 < expression.length()) {
                    char ch1 = expression.charAt(i + 1);
                    
                    if(ch1 >= '0' && ch1 <= '9') {
                        sb.append(ch);
                        sb.append(ch1);
                        i += 2;
                    }
                    else {
                        sb.append(ch);
                        i++;
                    }
                }
                else {
                    sb.append(ch);
                    i++;
                }
            }
            else {
                sb.append(ch);
                i++;
            }
            
            exp.add(sb.toString());
        }
        
        dp = new ArrayList[exp.size()][exp.size()];
        return diffWaysToCompute(exp, 0, exp.size() - 1);
    }
    
    public List<Integer> diffWaysToCompute(List<String> exp, int i, int j) {
        if(i == j) {
            List<Integer> bans = new ArrayList<>();
            bans.add(Integer.parseInt(exp.get(i)));
            return bans;
        }
        
        if(dp[i][j] != null) {
            return dp[i][j];
        }
        
        List<Integer> ans = new ArrayList<>();
        
        for(int k = i + 1; k <= j - 1; k += 2) {
            List<Integer> leftRes = diffWaysToCompute(exp, i, k - 1);
            List<Integer> rightRes = diffWaysToCompute(exp, k + 1, j);
            
            getRes(leftRes, rightRes, exp.get(k).charAt(0), ans);
        }
        
        return dp[i][j] = ans;
    }
    
    public void getRes(List<Integer> left, List<Integer> right, char opr, List<Integer> ans) {
        if(opr == '+') {
            for(int val1 : left) {
                for(int val2 : right) {
                    ans.add(val1 + val2);
                }
            }
        }
        else if(opr == '-') {
            for(int val1 : left) {
                for(int val2 : right) {
                    ans.add(val1 - val2);
                }
            }
        }
        else if(opr == '*') {
            for(int val1 : left) {
                for(int val2 : right) {
                    ans.add(val1 * val2);
                }
            }
        }
    }
}
