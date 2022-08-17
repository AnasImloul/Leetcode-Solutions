class Solution {
    public boolean judgePoint24(int[] cards) {
        List<Double> in=new ArrayList<>();
        
        for(int i : cards){
            in.add((double)i);
        }
        
        return dfs(in);
    }
    
    
    public boolean dfs(List<Double> cards){
        if(cards.size()==1){
            if(Math.abs(cards.get(0)-24.0)<0.001) return true;
            return false;
        }
        
        for(int i=0;i<cards.size();i++){
            for(int j=i+1;j<cards.size();j++){
                List<Double> possibleCombinations=generatePossibleResults(cards.get(i),cards.get(j));
                
                for(double c:possibleCombinations){
                    List<Double> next=new ArrayList<>();
                    next.add(c);
                    
                    for(int k=0;k<cards.size();k++){
                        if(k!=i && k!=j) next.add(cards.get(k));
                    }                    
                    if(dfs(next)) return true;
                } 
                
            }
        }
        return false;
    
    }

    private List<Double> generatePossibleResults(double a, double b) {
        List<Double> res = new ArrayList<>();
        res.add(a + b);
        res.add(a - b);
        res.add(b - a);
        res.add(a * b);
        res.add(a / b);
        res.add(b / a);
        return res;
    }
}
