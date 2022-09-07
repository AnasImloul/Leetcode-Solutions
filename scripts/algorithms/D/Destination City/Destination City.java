// Runtime: 4 ms (Top 58.98%) | Memory: 44 MB (Top 40.73%)
class Solution {
    public String destCity(List<List<String>> paths) {
        HashSet<String> set1 = new HashSet<>();

        for (int i = 0; i < paths.size(); ++i) {
            set1.add(paths.get(i).get(0));
        }
        for (int i = 0; i < paths.size(); ++i) {
            if (!set1.contains(paths.get(i).get(1))) return paths.get(i).get(1);
        }
        return "placeholder";
    }
}