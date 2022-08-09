// Space Complexity = O(N*M) (N == length of cost array and M == target )
// Time Complexity = O(N*M)

class Solution {
    Map<String,String> map =  new HashMap<>();
    String[][] memo;
    public String largestNumber(int[] cost, int target) {
        memo = new String[cost.length+1][target+1];
        
        for( int i = 0;i<=cost.length;i++ ){
            for(int j = 0;j<=target;j++) memo[i][j] = "0";
        }
        
        String res = helper(cost,cost.length-1,target);
        
        return res == "-1" ? "0" : res; 
        
    }
    
    public String helper( int[] cost , int index , int target){
        if(target == 0) {
            return "";
        }
        
        if(target < 0) return "-1";
        
        if(index < 0) return "-1";
        
        if( memo[index][target] != "0") return memo[index][target];
        
        String str1 = (index+1) + helper(cost,cost.length-1,target-cost[index]) ;
        String str2 = helper(cost,index-1,target);
        
        String res = getBigger(str1,str2);
        
        memo[index][target] =  res;
        
        return res;
    }
    
    public String getBigger(String num1 , String num2){
        if( num1.contains("-1") ) return num2;
        if( num2.contains("-1") ) return num1;
        if( num1.length() > num2.length() ) return num1;
        if( num2.length() > num1.length() ) return num2;
        return Double.parseDouble( num1 ) < Double.parseDouble( num2 ) ? num2 : num1;
    }
}
