class Solution {
    private static final int NOT_VISITED = 0;
    private static final int VISITING = 1;
    private static final int VISITED = 2;
    
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        Map<String, Integer> status = new HashMap<>();
        Map<String, List<String>> prereqs = new HashMap<>();
        
        for (int i = 0; i < recipes.length; ++ i) {
            status.put(recipes[i], NOT_VISITED);
            prereqs.put(recipes[i], ingredients.get(i));
        }
        
        for (String s: supplies) {
            status.put(s, VISITED);
        }
        
        List<String> output = new ArrayList<>();
        for (String s: recipes) {
            dfs (s, prereqs, status, output);
        }
        
        return output;
    }
    
    public boolean dfs(String s, Map<String, List<String>> prereqs, Map<String, Integer> status, List<String> output) {
        if (!status.containsKey(s)) {
            return false;
        }
        
        if (status.get(s) == VISITING) {
            return false;
        }
        
        if (status.get(s) == VISITED) {
            return true;
        }
        
        status.put(s, VISITING);
        for (String p: prereqs.get(s)) {
            if (!dfs(p, prereqs, status, output)) {
                return false;
            }
        }
        status.put(s, VISITED);
        output.add(s);
        
        return true;
    }
}
