// Runtime: 362 ms (Top 62.96%) | Memory: 52.4 MB (Top 92.59%)
class Solution {
    public List<Integer> peopleIndexes(List<List<String>> favoriteCompanies) {
        Set<String>[] fav = new Set[favoriteCompanies.size()];
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            set.add(i);
            fav[i] = new HashSet<>(favoriteCompanies.get(i));
        }
        for (int i = 1; i < favoriteCompanies.size(); i++) {
            if (!set.contains(i)) continue;
            for (int j = 0; j < i; j++) {
                if (!set.contains(j)) continue;
                if (isSubSet(fav[j], fav[i])) set.remove(j);
                if (isSubSet(fav[i], fav[j])) set.remove(i);
            }
        }
        List<Integer> ans = new ArrayList<>(set);
        Collections.sort(ans);
        return ans;
    }

    private boolean isSubSet(Set<String> child, Set<String> parent) {
        if (child.size() > parent.size()) return false;
        return parent.containsAll(child);
    }
}