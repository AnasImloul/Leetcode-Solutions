class Solution {
    public List<String> ret;
    public List<String> ans;
    public List<String> ambiguousCoordinates(String s) {
        ret=new ArrayList<>();
        ans=new ArrayList<>();
        String start=s.substring(0,2);
        util(s,1);
        fun();
        return ans;
    }
    
    //putting comma
    void util(String s,int idx) {
        if(idx==s.length()-2) {
            return;
        }
        
        String ns=s.substring(0,idx+1)+", "+s.substring(idx+1);
        ret.add(ns);
        util(s,idx+1);
    }
    
    //helper function for puting decimals after comma
    void fun() {
        for(String s:ret) {
            int cIndex=0;
            for(int i=0;i<s.length();i++) {
                if(s.charAt(i)==',') {
                    cIndex=i;
                    break;
                }
            }
            String a=s.substring(1,cIndex);
            String b=s.substring(cIndex+2,s.length()-1);
            List<String> n1=dot(a);
            List<String> n2=dot(b);
            if(n1==null || n2==null) { //invalid strings
                continue;
            }else { //valid strings
                for(String fir:n1) {
                    for(String sec:n2) {
                        ans.add("("+fir+", "+sec+")");
                    }
                }
            }
        }
    }
    
    //putting decimal point
    List<String> dot(String n) {
        List<String> li=new ArrayList<>();
        if(n.length()==1) {
            li.add(n);
        }else {
            
            //just checking for first and last zeroes and making conditions accordingly

            if(n.charAt(n.length()-1)=='0') {
                if(n.charAt(0)=='0') {
                    return null;
                }else {
                    li.add(n);
                }
            }else if(n.charAt(0)=='0') {
                li.add("0."+n.substring(1));
            }else {
                for(int i=0;i<n.length()-1;i++) {
                    li.add(n.substring(0,i+1)+"."+n.substring(i+1));
                }
                li.add(n);  //without any decimal
            }
        }
        return li;
    }
}
