class Solution {
	private int minCost;
	private int gp1Size;
	private int gp2Size;
	public int connectTwoGroups(List<List<Integer>> cost) {
		minCost = Integer.MAX_VALUE;
		gp1Size = cost.size();
		gp2Size = cost.get(0).size();
		boolean[] connected = new boolean[gp1Size + gp2Size];
		dfs(0, 0, cost, connected);
		return minCost;
	}
	private void dfs(int idx, int sum, List<List<Integer>> cost, boolean[] connected){
		if (idx == gp1Size + gp2Size) { 
			minCost = Math.min(minCost, sum);
			return;
		}
        //pruning
		if (sum >= minCost) {
            return; 
        }
		if (idx < gp1Size) {
			//in group 1
			connected[idx] = true; 
            //brute force try connect to every point in group 2
			for(int i = 0; i < gp2Size; i++){
                boolean oldVal = connected[i+gp1Size];
				connected[i+gp1Size] = true;
				dfs(idx+1, sum + cost.get(idx).get(i), cost, connected);
                connected[i+gp1Size] = oldVal;
			}
		} else {
			//in group 2
			if (!connected[idx]) {
				int min = Integer.MAX_VALUE;
				for(int i = 0; i < gp1Size; i++){
					min = Math.min(min, cost.get(i).get(idx-gp1Size));
				}
				dfs(idx+1, sum + min, cost, connected);
			} else {
                //if already connect, no need to connect to group 1 again
				dfs(idx+1, sum, cost, connected);
			}
		}
	}
}
