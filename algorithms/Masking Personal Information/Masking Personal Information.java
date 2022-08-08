class Solution {
    public String maskPII(String s) {
        StringBuilder sb  = new StringBuilder();
		         //email handeling
        if((s.charAt(0) >= 97 && s.charAt(0) <= 122) || (s.charAt(0) >= 65 && s.charAt(0) <= 90)){

            s = s.toLowerCase();
           int indexofAt = s.indexOf('@');
           String firstName = s.substring(0, indexofAt);
           sb.append(firstName.charAt(0)).append("*****").append(firstName.charAt(firstName.length()-1));
           sb.append(s.substring(indexofAt,s.length()));
        }
        //phone number handeling
        else{
           int digits = 0;
           for(int i = 0 ; i < s.length(); i++){
               if(Character.isDigit(s.charAt(i))){
                   digits++;
               }
           }
           if(digits > 10){
               sb.append('+');
           }
           while(digits > 10){
               sb.append('*');
               digits--;
           }
           if(sb.toString().isEmpty() == false){
               sb.append('-');
           }
           sb.append("***").append('-').append("***-");
           StringBuilder last4 = new StringBuilder();
           int count = 0;
           for(int i  = s.length()-1; i >=0; --i){
               if(count == 4){
                   break;
               }
               if(Character.isDigit(s.charAt(i))){
                   last4.append(s.charAt(i));
                   count++;
               }
           }
           sb.append(last4.reverse());
        }

        return sb.toString();
    }
}