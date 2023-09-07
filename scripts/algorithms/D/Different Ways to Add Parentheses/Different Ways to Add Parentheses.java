// Runtime: 2 ms (Top 79.5%) | Memory: 41.16 MB (Top 75.1%)

class Solution {
    Map<String, List<Integer>> memo = new HashMap<>();
    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> res = new LinkedList<>();
        if(memo.containsKey(expression)) return memo.get(expression);

        for(int i = 0; i<expression.length(); i++){
            char c = expression.charAt(i);
            if(c == '*' || c == '+' || c == '-'){
                //divide
                List<Integer> left = diffWaysToCompute(expression.substring(0, i));
                List<Integer> right = diffWaysToCompute(expression.substring(i+1));

                //conquer
                for(int a : left){
                    for(int b : right){
                        if(c == '+'){
                            res.add(a+b);
                        }else if(c == '-'){
                            res.add(a - b);
                        }else if(c == '*'){
                            res.add(a * b);
                        }
                    }
                }
                
            }
        }
        //base case, when there is no operator
        if(res.isEmpty()){
            res.add(Integer.parseInt(expression));
        }
        memo.put(expression, res);
        return res;     
    }
}