class Solution {
    public int maxScore(String s) {
        int max = 0;
       
        for(int i = 0; i < s.length()-1; i++){
            String temp0 = s.substring(0,i+1);
            String temp1 = s.substring(i+1,s.length());
            int tem1 = 0;
            int tem0 = 0;
            int temp = 0;
            for(int j = 0; j < temp0.length() ; j++){
                if(temp0.charAt(j) == '0'){
                    tem0++;
                }  
            }
            if(temp1 == ""){
                 tem1 = 0;
             } 
            else{
                for(int j = 0; j< temp1.length() ; j++){
                    if(temp1.charAt(j) == '1'){
                        tem1++;
                    }
                }
            }
            temp = tem0+tem1;
            if(max < temp){
                max = temp;
            }
        }
        return max;
    }
}
