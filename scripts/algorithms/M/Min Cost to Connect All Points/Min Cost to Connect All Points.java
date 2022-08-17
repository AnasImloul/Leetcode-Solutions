class Solution {
	public int minCostConnectPoints(int[][] points) {
		int n = points.length;
		PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[0]-b[0]);
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				pq.add(new int[]{calDis(points,i,j),i,j});
			}
		}
		int c = 0, ans = 0;
		UnionFind uf = new UnionFind(n);
		while(c < n-1){
			int[] cur = pq.poll();
			if(uf.find(cur[1]) != uf.find(cur[2])) {
				ans += cur[0];
				uf.union(cur[1],cur[2]);
				c++;
			}
		}
		return ans;
	}
	private int calDis(int[][] points, int a, int b) {
		return Math.abs(points[a][0] - points[b][0]) + Math.abs(points[a][1] - points[b][1]);
	}
	class UnionFind{
		int[] parent;
		UnionFind(int n){
			this.parent = new int[n];
			for(int i=0;i<n;i++)parent[i]=i;
		}
		public int find(int u){
			if(parent[u]!=u)parent[u] = find(parent[u]);
			return parent[u];
		}
		public void union(int u, int v){
			parent[find(u)] = parent[find(v)];
		}
	}
}
