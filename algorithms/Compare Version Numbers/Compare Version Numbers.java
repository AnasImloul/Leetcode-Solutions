class Solution {
    public int compareVersion(String version1, String version2) {
	//Here we are going to Split the numbers by  . but since we cannot do that in java we will replace . with # and then do it 
        version1=version1.replace('.', '#');
        version2=version2.replace('.', '#');
        
        String v1[]=version1.split("#");
        String v2[]=version2.split("#");
        
        int i=0;
        
		
        while(i<v1.length || i<v2.length){
            //we will have inital value  0 as our array can out out index so taking that in considerration 
            Integer i1= 0;
            Integer i2= 0;
			//Here we are using removeing Zero function which will remove all the zeros before the string 
            if(i<v1.length){
                i1= Integer.valueOf(removezero(v1[i]));
            }
            if(i<v2.length){
                i2= Integer.valueOf(removezero(v2[i]));
            }
            //and the rest is just the comparison
            if(i1<i2){
                return -1;
            }
            else if(i1>i2){
                return 1;
            }
            i++;
        }
		//if all the statments are false then at last we can say that they are equal
        return 0;
    }
    String removezero(String s){
        String result ="";
        int i =0;
        while(i<s.length()){
            if(s.charAt(i)!='0'){
                result=s.substring(i, s.length());
                break;
            }
            i++;
        }
        return result!=""?result:"0";
    }
}
