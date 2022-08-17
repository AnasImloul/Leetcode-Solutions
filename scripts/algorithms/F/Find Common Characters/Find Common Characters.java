class Solution {
    public List<String> commonChars(String[] words) {
        List<String> strResult = new ArrayList<String>();
        for(int i = 0; i < words[0].length(); i++){
            String ch = String.valueOf(words[0].charAt(i));
            boolean isTrue = false;
            for(int j = 1; j < words.length; j++){
                if(words[j].contains(ch)){
                    words[j] = words[j].replaceFirst(ch,"");
                    isTrue = true;
                }else{
                    isTrue = false;
                    break;
                }
            }
            if(isTrue){
                strResult.add(ch);
            }
        }
        
        return strResult;
    }
}
