class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        //Decleration of HashMap of String , List of String
        HashMap<String,List<String>>HM=new HashMap<>();
        //Traversing each path in paths.
        for(String path:paths){
            int index_=path.indexOf(" ");
            int len=path.length();
            
            //splitting the directory from the filename.
            String dirName=path.substring(0,index_);
            
          // Declaring list for Files having same directory.
            List<String>list=new ArrayList<>();
            
            // remaining String containing different files having same directory.
            String rem= path.substring(index_+1,len);
         
            int j=0;
            
            // Iterating over the remaining String rem.
            for(int i=0;i<rem.length();i++){
                if(rem.charAt(i)==')'){
                    String tmp=rem.substring(j,i+1);
                    
                    j=i+2;
                    // adding all files seperated by a space ' '
                    list.add(tmp);
                }
            }
            for(String Subpath:list){
                int iotxt=Subpath.indexOf(".txt");
                int lengt=Subpath.length();
                
                //seperating file name from file content.
                String Prepath=Subpath.substring(0,iotxt+4);
                
                // storing filecontent in fcontent.
                String fcontent=Subpath.substring(iotxt+4,lengt);
                  if(!HM.containsKey(fcontent)){
                        HM.put(fcontent,new ArrayList<String>());
                    }
                
                //adding values as path of file at key as file content.
                  HM.get(fcontent).add(dirName+"/"+Prepath);
                     
            }
                
            
        }
        
        //declaring list of list to return
        List<List<String>>ans=new ArrayList<>();

        for(String txt:HM.keySet()){
            int n=HM.get(txt).size();
            // adding key having more than 1 files into list ans.
            if(n>1)ans.add(HM.get(txt));
        }
        
        
        return ans;
    }
}
