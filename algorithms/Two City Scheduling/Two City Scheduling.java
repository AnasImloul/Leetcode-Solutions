// costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
//  The difference between them would be like this [511,  -394, -259, -45, -722, -108]  this will give us the differnce c[1] - c[0]
// Now after sorting them from highest to smallest would be [511, -45, -108, -259, -394,-722] from high to low c2[1] - c2[0], c1[1] - c1[0]  if we want low to high then it would be like this c1[1] - c1[0], c2[1] - c2[0]
// 

class Solution {
    public int twoCitySchedCost(int[][] costs) {
       Arrays.sort(costs, (c1, c2) -> Integer.compare(c2[1] - c2[0], c1[1] - c1[0]));// biggest to smallest
        int minCost = 0;               
        int n = costs.length;
        for (int i = 0; i < n; i++) {
            minCost += i < n/2? costs[i][0] : costs[i][1];//First half -> A; Last half -> B  259 + 184 + 577 + 54 + 667 + 118
        }
        return minCost;
    }
}
