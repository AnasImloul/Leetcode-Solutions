// Runtime: 1 ms (Top 97.83%) | Memory: 41.60 MB (Top 63.04%)

class Solution {
    List<Integer> list=new ArrayList<>();
    public List<Integer> splitIntoFibonacci(String num) {
        
        if(backtrack(num,0)) return list;
        else return new ArrayList();
        
    }
    boolean backtrack(String num,int index){
        if(index==num.length()) return list.size()>2;
        
        int n=0;
        for(int i=index;i<num.length();i++){
            n=n*10+(num.charAt(i)-'0');
            if(n<0) return false;
            if(list.size()<2 || list.get(list.size()-1)+list.get(list.size()-2)==n){
                list.add(n);
                if(backtrack(num,i+1)) return true;
            list.remove(list.size()-1);
            }
            
            if(i==index && num.charAt(i)=='0') return false;
        }
        return false;
    }
    
}