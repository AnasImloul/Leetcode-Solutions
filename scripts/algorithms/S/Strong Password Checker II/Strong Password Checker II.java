class Solution {
    public boolean strongPasswordCheckerII(String password) {
           HashSet<Integer> intAscii = new HashSet<>();
        String specialCharacters = "!@#$%^&*()-+";
        for (int i = 0; i < specialCharacters.length(); i++) {
            int ascii = specialCharacters.charAt(i);
            intAscii.add(ascii);
        }
        
        if(password.length() < 8){
            return false;
        }
        boolean small = false;
        boolean large = false;
        boolean numbers = false;
        boolean specialChars = false;
        for(int i = 0 ; i < password.length() ; i++){
            int ascii = (int)(password.charAt(i));
            if(ascii <= 90 && ascii>=65){
                large = true;
            }
                if(ascii <= 122 && ascii>=97){
                small = true;
            }
            if(ascii <=57 && ascii >=48){
                numbers = true;
            }
            if(intAscii.contains(ascii)){
                specialChars = true;
            }
            if(i> 0 && password.charAt(i)== password.charAt(i-1)){
                return false;
            }
        }
        if(large == false || small == false || numbers == false || specialChars ==false){
            return false;
        }
        return true;
    }
}
