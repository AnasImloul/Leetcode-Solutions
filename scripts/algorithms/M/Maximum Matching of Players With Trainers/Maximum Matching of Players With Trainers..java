// Runtime: 27 ms (Top 30.0%) | Memory: 59.60 MB (Top 65.56%)

class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);
        int j = 0, matches = 0;
        for(int i=0; i<trainers.length && j < players.length; i++){
            if(players[j] <= trainers[i]){
                j++;
                matches++;
            }
        }
        return matches;
    }
}
