class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        HashMap<Integer, HashSet<Integer>> usersMap = new HashMap();
        
        for(int[] log : logs){
            int user = log[0];
            int min = log[1];
            
            //add current user mapping, if not exist
            usersMap.putIfAbsent(user, new HashSet<Integer>());
            
            //add unique new minute 
            usersMap.get(user).add(min);
        }
        
        
        
        int[] result = new int[k];
        for(int user : usersMap.keySet()){
            int uam = usersMap.get(user).size();
            //increment users count
            result[uam - 1]++;
         }

		return result;
        
    }
    
}
