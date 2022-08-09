class Solution {
    public String largestMultipleOfThree(int[] digits) {
        int n=digits.length;
        Arrays.sort(digits);
        
        if(digits[digits.length-1]==0){
            return "0";
        }
        
        int sum=0;
        
        for(int i=0;i<digits.length;i++){
            sum+=digits[i];
        }
        
        if(sum%3==0){
            StringBuilder sb=new StringBuilder("");
            
            for(int i=n-1;i>=0;i--){
                sb.append(digits[i]);
            }
            
            return sb.toString();
        }else if(sum%3==1){
            int modOne=-1;
            
            for(int i=0;i<n;i++){
                if(digits[i]%3==1){
                    modOne=i;
                    break;
                }
            }
            
            if(modOne==-1){
                int []idx=new int[2];
                Arrays.fill(idx,-1);
                
                for(int i=0;i<n;i++){
                    if(digits[i]%3==2){
                        if(idx[0]==-1){
                            idx[0]=i;
                        }else{
                            idx[1]=i;
                            break;
                        }
                    }
                }
                
                if(idx[1]==-1){
                    return "";
                }else{
                    digits[idx[0]]=-1;
                    digits[idx[1]]=-1;
                }
            }else{
                digits[modOne]=-1;
            }
        }else{
            int modTwo=-1;
            
            for(int i=0;i<n;i++){
                if(digits[i]%3==2){
                    modTwo=i;
                    break;
                }
            }
            
            if(modTwo==-1){
                int []idx=new int[2];
                Arrays.fill(idx,-1);
                
                for(int i=0;i<n;i++){
                    if(digits[i]%3==1){
                        if(idx[0]==-1){
                            idx[0]=i;
                        }else{
                            idx[1]=i;
                            break;
                        }
                    }
                }
                
                if(idx[1]==-1){
                    return "";
                }else{
                    digits[idx[0]]=-1;
                    digits[idx[1]]=-1;
                }
            }else{
                digits[modTwo]=-1;
            }
        }
        
        StringBuilder sb=new StringBuilder("");
        
        for(int i=n-1;i>=0;i--){
            if(digits[i]!=-1){
                sb.append(digits[i]);
            }
            
        }
        
        if(sb.length()>0 && sb.toString().charAt(0)=='0'){
            return "0";
        }
        return sb.toString();
    }
}
