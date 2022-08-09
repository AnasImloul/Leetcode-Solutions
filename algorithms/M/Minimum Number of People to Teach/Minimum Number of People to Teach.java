class Solution {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        //This is the language map . Key is the person , The hashSet is the languages he can speak. We use a hashset to optimize the searching
        HashMap<Integer,HashSet<Integer>> languageMap = new HashMap<>();
        
        //We put the languages known to a map
        for(int i=0;i<languages.length;i++){
            
            languageMap.put(i+1,new HashSet<>());
            
            for(int l : languages[i])
                languageMap.get(i+1).add(l);
            
        }
        
        //THis is the length of languages matrix
        int ans = languages.length;
        
        //For each language we count the minimum no of people whom we need to teach a particular language i
        for(int i=1;i<=n;i++){
            ans = Math.min(ans,num_of_users_to_teach(i,friendships,languageMap));
        }
        
        //The minimum no of people is returned
        return ans;
        
        
        
    }
    //This method counts the minimum no of people to teach a given language lang so that all of them can communicate.
    private int num_of_users_to_teach(int lang,int[][] friendships,  HashMap<Integer,HashSet<Integer>> languageMap){
        
        //We put the unique no of people whom we need to teach languages
        HashSet<Integer> temp = new HashSet<>();
        
        for(int i=0;i<friendships.length;i++){
            //first and second refers to two persons forming a friendship
            int first = friendships[i][0];
            int second = friendships[i][1];
            //languages spoken by the first user
            HashSet<Integer> lang_first = languageMap.get(first);
            //Languages spoken by the second user
            HashSet<Integer> lang_second = languageMap.get(second);
            
            //We first check whether they can communicate which adding this language lang.
            if(!isCommon(lang_first,lang_second)){
                //If the language lang is not present in the first persons vocabulary we add it.
                if(!lang_first.contains(lang))
                    temp.add(first);
                //If the language lang is not present in the second  persons vocabulary we add it.
                if(!lang_second.contains(lang))
                    temp.add(second);
                
            }
            
            
            
        }
        
        return temp.size();
        
        
    }
    
    //This method checks whether the communication between two person is possible or not .
    private boolean isCommon(HashSet<Integer> first,HashSet<Integer> second){
        
        for(int k : first){
            if(second.contains(k))
                return true;
        }
        return false;
        
        
    }
    
    
}
