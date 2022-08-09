class Solution {
    public String reformat(String s) {
        
        List<Character> ch = new ArrayList<>();
        List<Character> d = new ArrayList<>();
        
        for(char c : s.toCharArray()){
            if(c >= 'a' && c <= 'z')ch.add(c);
            else d.add(c);
        }
        
        if(Math.abs(d.size() - ch.size()) > 1)  return "";
        
        StringBuilder str = new StringBuilder();
        
        for(int i = 0; i < s.length(); i++){
            
            if(!ch.isEmpty() || !d.isEmpty()){
                if(ch.size() > d.size())
                    str.append(appender(ch,d));
                else 
                    str.append(appender(d,ch));
            }
            else{
                break;
            }
        }
        
        return new String(str);
        
    }
    
    public String appender(List<Character> first,List<Character> second){
        
        StringBuilder str = new StringBuilder();
        
        if(!first.isEmpty()){
            str.append(first.get(0));
            first.remove(0);
        }
        if(!second.isEmpty()){
            str.append(second.get(0));
            second.remove(0);
        }
        
        return new String(str);
    }
}
