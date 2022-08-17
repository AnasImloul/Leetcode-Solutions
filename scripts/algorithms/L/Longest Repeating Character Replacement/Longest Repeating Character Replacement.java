class Solution {
    public int characterReplacement(String s, int k) {
        HashMap<Character,Integer> map=new HashMap<>();
            int i=-1;
            int j=-1;
            int ans=0;
            while(true){
            boolean f1=false;
            boolean f2=false;
            while(i<s.length()-1){
                //acquire
               i++;
               f1=true;
               char ch=s.charAt(i);
               map.put(ch,map.getOrDefault(ch,0)+1);
               int count=0;
               for(char key:map.keySet()){
                   count=Math.max(count,map.get(key));
               }
               int replace=(i-j) - count;
               if(replace<=k) {
                   ans=Math.max(i-j,ans);
               } 
               else break;
                   
             }
                
             while(j<i){
               //release   
               f2=true;  
               j++;
               char ch=s.charAt(j);
               isremove(map,ch);
               int count=0;
               for(char key:map.keySet()){
                   count=Math.max(count,map.get(key));
               }
               int replace=(i-j) - count;  
               if(replace<=k){
                   ans=Math.max(i-j,ans);
                   break;
               }
               else continue;  
             }   
             if(f1==false && f2==false) break;   
                
         }
        
        return ans;
    }
    
    
    static void isremove(HashMap<Character,Integer> map,char ch){
        if(map.get(ch)==1) map.remove(ch);
        else map.put(ch,map.get(ch)-1);
    }
}
