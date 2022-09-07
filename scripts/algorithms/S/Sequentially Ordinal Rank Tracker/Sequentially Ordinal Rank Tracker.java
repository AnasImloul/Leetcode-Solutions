// Runtime: 996 ms (Top 5.13%) | Memory: 131.3 MB (Top 81.29%)
class SORTracker {

    private TreeMap<Integer, List<String>> map;
    private int queryNum;

    // Find suitable position for name in the list
    private int getIndex(String name, List<String> list) {
        int l = 0, r = list.size() - 1, m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if(name.compareTo(list.get(m)) > 0) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return name.compareTo(list.get(l)) > 0 ? l+1 : l;
    }

    public SORTracker() {
        map = new TreeMap<>((a,b) -> (b-a));
        queryNum = 0;
    }

    public void add(String name, int score) {
        List<String> list = map.getOrDefault(score, new ArrayList<>());
        int index = (list.size() == 0) ? 0 : getIndex(name, list);
        list.add(index, name);
        map.put(score, list);
    }

    public String get() {
        int index = queryNum;
        for (int score: map.keySet()) {
            if (index < map.get(score).size()) {
                queryNum++;
                return map.get(score).get(index);
            }
            index -= map.get(score).size();
        }
        return "";
    }
}