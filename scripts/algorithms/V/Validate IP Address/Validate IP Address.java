// Runtime: 1 ms (Top 94.74%) | Memory: 41.50 MB (Top 35.64%)

class Solution {
    public String validIPAddress(String IP) {
        if(IP.length()==0) return "Neither";
        
        if(IP.indexOf(".")>=0) return validateIPV4(IP);
        
        if(IP.indexOf(":")>=0) return validateIPV6(IP);
        
        return "Neither";
    }
    
    private  String validateIPV4(String ip){
	   // step 1 
        if(ip.charAt(0)=='.' || ip.charAt(ip.length()-1)=='.') return "Neither";
           
		  //step 2 
          String[] component=ip.split("\\.");
          
		  //step 3
           if(component.length!=4) return "Neither";
           
		   //step 4
           for(String comp:component){
             if(comp.length()==0 || comp.length()>3 || (comp.charAt(0)=='0' && comp.length()>1)){
                 return "Neither";
             }
               
			   //step5
              for(char ch:comp.toCharArray()){
                  if(ch<'0' || ch>'9') return "Neither";
              }
               
			   //step6
              int num=Integer.parseInt(comp);
              if(num<0 || num>255) return "Neither";
               
           }
           
           return "IPv4";
           }
           
   private String validateIPV6(String ip){
     if(ip.charAt(0)==':' || ip.charAt(ip.length()-1)==':') return "Neither";
       
       String[] component=ip.split(":");
       
       if(component.length!=8) return "Neither";
       
       for(String comp:component){
       if(comp.length()==0 || comp.length()>4) return "Neither";
           
           
           for(char ch:comp.toLowerCase().toCharArray()){
             if((ch<'0' || ch>'9') && (ch!='a' && ch!='b' && ch!='c' && ch!='d' && ch!='e' && ch!='f')){
                 return "Neither";
             }  
           }
       }
       return "IPv6";
     }
 }
