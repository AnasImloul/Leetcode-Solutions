class Solution {
public:

	// Union Find Approach

	vector<int> root;

	int find(int node){
		if(root[node] != node){
			return find(root[node]);
		}
		return node;
	}

	int makeConnected(int n, vector<vector<int>>& connections) {

		int m = connections.size();

		if(m < n-1){
			return -1;
		}

		for(int i=0 ; i<n ; i++){
			root.push_back(i);
		}

		for(int i=0 ; i<m ; i++){

			int v1 = connections[i][0];
			int v2 = connections[i][1];

			int r1 = find(v1);
			int r2 = find(v2);

			if(r1 != r2){
				root[r1] = r2;
			}
		}

		int ans = 0;
		for(int i=0 ; i<n ; i++){
			if(root[i] == i){
				ans++;
			}
		}

		return ans - 1;
	}
};