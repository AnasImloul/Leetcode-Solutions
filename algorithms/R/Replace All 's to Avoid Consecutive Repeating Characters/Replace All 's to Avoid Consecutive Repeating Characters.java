class Solution {
    public String modifyString(String s) {

        
         if(s.length()==1){
            return String.valueOf('a');
        }
        if(s.length()==0){
            return null;
        }
        
        StringBuilder stringBuilder=new StringBuilder(s);
        for (int i=0;i<stringBuilder.length();i++){
            if(stringBuilder.charAt(i)=='?'){
                for(char j='a';j<='z';j++){
                    if(i!=0&&i!=stringBuilder.length()-1&&j!=stringBuilder.charAt(i-1)&&j!=stringBuilder.charAt(i+1)){
                        stringBuilder.replace(i,i+1, String.valueOf(j));
                    }
                    if(i==0&&j!=stringBuilder.charAt(i+1)){
                        stringBuilder.replace(i,i+1, String.valueOf(j));
                    }
                    if(i==stringBuilder.length()-1&&j!=stringBuilder.charAt(i-1)){
                        stringBuilder.replace(i,i+1,String.valueOf(j));
                    }
                }

            }
        }
        return stringBuilder.toString();
    }
}