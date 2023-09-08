// Runtime: 11 ms (Top 15.1%) | Memory: 43.76 MB (Top 17.4%)


class Solution {
    public int maximumNumberOfStringPairs(String[] words) {
        ArrayList<String> obj=new  ArrayList<String>();
        Collections.addAll(obj,words);
        int count=0;
        for(int i=0;i<words.length;i++){
            String str=words[i];
            int n=str.length();
            String ktr="";
            //REVERSE
            for(int k=0;k<n;k++){
                ktr=str.charAt(k)+ktr;
            }
            //REMOVE ELEMENTS LIKE "ZZ","aa"
            if(ktr.equals(str)){
                 obj.remove(ktr);
            }
             //REMOVE ELEMENTS IF PRESENT IN ARRAY LIST
            if(obj.contains(ktr)){
                obj.remove(str); 
                count++;
            }
            
         
          
        }
        
        return count;
    }
} 