class Solution {
    public int[] groupStrings(String[] words) {
        int n = words.length;
        Arrays.sort(words, Comparator.comparingInt(String::length));
        int[] parents = new int[n];
        int[] ranks = new int[n];
        for (int i = 0; i < n; i++) parents[i] = i;
        Arrays.fill(ranks, 1);

        int[] masks = new int[n];
        for (int i = 0; i < n; i++) {
            int val = 0;
            for (int j = 0; j < words[i].length(); j++) {
                val += (1 << (words[i].charAt(j) - 'a'));
            }
            masks[i] = val;
        }
        Set<Integer> seen = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (seen.contains(masks[i])) continue;
            for (int j = i + 1; j < n; j++) {
                if (words[i].length() + 1 < words[j].length()) break;
                int p1 = find(parents, i), p2 = find(parents, j);
                if (p1 == p2) continue;
                int a = masks[i], b = masks[j];
                if (a == b) merge(parents, ranks, p1, p2);
                int xor = a ^ b;
                int and = a & b;
                int xor1 = a ^ and, xor2 = b ^ and;
                if ((xor & (xor - 1)) == 0 || ((xor1 & (xor1 - 1)) == 0 && (xor2 & (xor2 - 1)) == 0)) {
                    merge(parents, ranks, p1, p2);
                }
            }
            seen.add(masks[i]);
        }

        Map<Integer, Integer> map = new HashMap<>();
        int max = 1;
        for (int i = 0; i < n; i++) {
            int f = find(parents, i);
            int cnt = map.getOrDefault(f, 0) + 1;
            map.put(f, cnt);
            max = Math.max(max, cnt);
        }

        return new int[]{map.size(), max};
    }

    private int find(int[] parents, int i) {
        return parents[i] = parents[i] == i ? i: find(parents, parents[i]);
    }

    private void merge(int[] parents, int[] ranks, int i, int j) {
        int p1 = find(parents, i), p2 = find(parents, j);
        if (p1 == p2) return;
        if (ranks[p1] > ranks[p2]) {
            parents[p1] = p2;
            parents[i] = p2;
            ranks[p2]++;
            return;
        }
        parents[p2] = p1;
        parents[j] = p1;
        ranks[p1]++;
    }
}
