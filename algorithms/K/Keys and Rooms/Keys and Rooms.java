class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
    		 boolean[] visited = new boolean[rooms.size()];
    		 visited[0]= true;
    		 for(int a:rooms.get(0))
    		 {
    			 if(!visited[a])
    			 {
    				 bfs(a, visited, rooms.size()-1, rooms);
    				 
    			 }
    		 }
    		 //System.out.println("arr -->>"+Arrays.toString(visited));
    		for(boolean a:visited)
    		{
    			if(!a)
    				return false;
    		}
    	      return true;
    	        
    	    }
    	 public void bfs(int key, boolean[] vivsted, int target,List<List<Integer>> rooms)
    	 {
    		
    		
    		 vivsted[key] = true;
    		 for(int a:rooms.get(key))
    		 {
    			 if(!vivsted[a])
    			 {
    				 bfs(a, vivsted, target, rooms);
    			 }
    		 }
    		 
    		 
    		
    	 }
       
}