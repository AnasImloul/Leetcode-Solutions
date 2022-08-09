class Solution {
private:
    vector<bool> sieve(int n) {
        vector<bool> prime(n + 1);
        for (int i = 0; i <= n; i++)
            prime[i] = 1;
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == 1) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = 0;
            }
        }
        prime[1] = prime[0] = 0;
        return prime;
    }
    vector<int> factors(int n, vector<int> &primelist) {
        vector<int> facs;
        for (int i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
            if (n % primelist[i] == 0) {
                facs.push_back(primelist[i]);
                while (n % primelist[i] == 0) {
                    n /= primelist[i];
                }
            }
        }
        if (n > 1) facs.push_back(n);
        return facs;
    }
    void dfs(vector<vector<int>> &gr, int node, vector<int> &vis, int &compSize) {
        if(vis[node]) return;
        vis[node] = 1;
        compSize++;
        for(auto x : gr[node]) {
            dfs(gr, x, vis, compSize);
        }
    }
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> gr(n);
        vector<bool> prime = sieve(1e5 + 6);
        vector<int> primelist;
		// Getting all the primes till 10^5 as maximum value of nums[i] is 10^5
        for (int i = 2; i <= 1e5 + 5; i++) if (prime[i]) primelist.push_back(i);
        unordered_map<int, int> m; // to store the index of the node with prime factor x
        for(int i = 0; i < n; i++) {
            vector<int> facs = factors(nums[i], primelist);
            for(auto j : facs) {
                if(m.find(j) == m.end()) { // prime factor had not occured before
                    m[j] = i; // j is the prime factor and its index is i
                } else {
				    // prime factor has already been seen before in a previous number and nums[i] is connected to that number
                    gr[i].push_back(m[j]);
                    gr[m[j]].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int> vis(n);
        for(int i = 0; i < n; i++) { // running a simple dfs to calculate the maximum component size
            if(!vis[i]) {
                int compSize = 0;
                dfs(gr, i, vis, compSize);
                ans = max(ans, compSize);
            }
        }
        return ans;
    }
};
