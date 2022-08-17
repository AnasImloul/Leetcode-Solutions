class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int N = 1 << req_skills.length, INF = (int)1e9;
        int[] parent = new int[N];
        int[] who = new int[N];
        int[] dp = new int[N];
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for (int i = 0; i < N; i++){
            if (dp[i]!=INF){ // valid state 
                for (int k = 0; k < people.size(); k++){
                    int cur = i;
                    for (int j = 0; j < req_skills.length; j++){
                        for (String skill : people.get(k)){
                            if (req_skills[j].equals(skill)){
                                cur |= 1<<j; // set the mask
                                break;
                            }
                        }
                    }
                    if (dp[cur]>dp[i]+1){ // replace if better
                        dp[cur]=dp[i]+1;
                        parent[cur]=i;
                        who[cur]=k;
                    }
                }
            }
        }
        int[] ans = new int[dp[N-1]];
        for (int i = 0,cur=N-1; i < ans.length; i++){
            ans[i]=who[cur];
            cur=parent[cur];
        }
        return ans;
    }
}
