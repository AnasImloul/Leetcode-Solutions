// Runtime: 13 ms (Top 71.24%) | Memory: 43.7 MB (Top 79.83%)
class Solution {
    public String rankTeams(String[] votes) {
        int n = votes.length;
        int teams = votes[0].length();
        Map<Character, int[]> map = new HashMap<>();
        List<Character> chars = new ArrayList<>();

        for(int i = 0 ; i < teams ; i++) {
            char team = votes[0].charAt(i);
            map.put(team, new int[teams]);
            chars.add(team);
        }

        for(int i = 0 ; i < n ; i++) {
            String round = votes[i];
            for(int j = 0 ; j < round.length() ; j++) {
                map.get(round.charAt(j))[j]+=1;
            }
        }

        chars.sort((a,b) -> {
            int[] l1 = map.get(a);
            int[] l2 = map.get(b);
            for(int i = 0 ; i < l1.length; i++) {
                if(l1[i] < l2[i]) {
                    return 1;
                }
                else if(l1[i] > l2[i]) {
                    return -1;
                }
            }
            return a.compareTo(b);
        });

        StringBuilder sb = new StringBuilder();
        for(char c : chars) {
            sb.append(c);
        }
        return sb.toString();
    }
}