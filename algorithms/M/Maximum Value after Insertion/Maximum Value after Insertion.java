class Solution {
    public String maxValue(String n, int x) {
        StringBuilder res= new StringBuilder();
        int i=0, j=0;
        if(n.charAt(0)=='-'){
            res.append(n.charAt(0));
            for(j=1; j<n.length(); j++){
               char ch= n.charAt(j);
               int val= ch-'0';
               if(val<= x){  
                  res.append(ch);
               }else{
                   res.append(x);
                   res.append(ch);
                   res.append(n.substring(j+1));
                   break;
               }
           }
            if(j==n.length()){
                res.append(x);
            }
        }
        else{
            for(i=0; i<n.length(); i++){
               char ch= n.charAt(i);
               int val= ch-'0';
                
               if(val>= x){  
                  res.append(ch);
               }else{
                   res.append(x);
                   res.append(ch);
                   res.append(n.substring(i+1));
                   break;
               }
           }
            if(i==n.length()){
                res.append(x);
            }
        }
        return res.toString();
    }
}