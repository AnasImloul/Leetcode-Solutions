Approach : Using dfs+ backtracking we can solve it	
	
	class Solution {
		public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
			List<List<Integer>> ans=new ArrayList<>();
			List<Integer> temp=new ArrayList<>();
			 boolean []visit=new boolean [graph.length];
			helper(graph,0,graph.length-1,ans,temp,visit);

			return ans;
		}
		public void helper(int[][] graph, int src,int dest,List<List<Integer>> ans,List<Integer> temp,boolean[]vis)
		{

			vis[src]=true;
			temp.add(src);
			if(src==dest)
			{
				List<Integer> b =new ArrayList<>();
				for(int h:temp){
					b.add(h);
				}
				ans.add(b);
			}

			for(int i:graph[src])
			{
				if(vis[i]!=true)
				{
					helper(graph,i,dest,ans,temp,vis);
				}

			}

			vis[src]=false;
			temp.remove(temp.size()-1);
		}
	}
