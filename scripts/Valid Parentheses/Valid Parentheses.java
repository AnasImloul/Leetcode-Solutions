class Solution {
    public boolean isValid(String s) {
        Deque<Character> str = new ArrayDeque<>();
        for(int i=0; i<s.length(); i++) {
            // char x = s.charAt(i);
            if(s.charAt(i)=='(' || s.charAt(i)=='{' || s.charAt(i)=='[') {
                str.push(s.charAt(i));
            }
            else {
                if(str.isEmpty())
                    return false;
                else if(matching(str.peek(), s.charAt(i)))
                    return false; 
                str.pop();
            }
        }
        
        return (str.isEmpty() == true);
    }
    
    public boolean matching(char a, char b) {
        return (
                (a=='(' && b!=')') || 
                (a=='{' && b!='}') || 
                (a=='[' && b!=']')
                );
    }
}
