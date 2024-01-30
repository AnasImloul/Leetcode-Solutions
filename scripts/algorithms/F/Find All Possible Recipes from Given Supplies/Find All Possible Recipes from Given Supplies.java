// Runtime: 32 ms (Top 86.45%) | Memory: 46.50 MB (Top 57.39%)

class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        HashSet<String> sup = new HashSet<>();
        HashMap<String, Integer> index = new HashMap<>();
        HashMap<String, List<String>> map = new HashMap<>();
        
        // create hashset of supplies
        for(String s: supplies) {
            sup.add(s);
        }
        
        // store index of all recipes
        for(int i = 0; i < recipes.length; i++) {
            index.put(recipes[i], i);
        }
        
        int[] indegree = new int[recipes.length];
        // create a mapping of all the recipes that are Ingredients as well
        // to the recipes they are ingredients for
        for(int i = 0; i < recipes.length; i++) {
            for(String need: ingredients.get(i)) {
                if(sup.contains(need))
                    continue;
                
                map.putIfAbsent(need, new ArrayList<String>());
                map.get(need).add(recipes[i]);
                indegree[i]++;
            }
        }
        
        LinkedList<Integer> q = new LinkedList<>();
        // add all the recipes with indegree 0 to the queue
        for(int i = 0; i < recipes.length; i++) {
            if(indegree[i] == 0) {
                q.add(i);
            }
        }
        
        List<String> cooked = new ArrayList<>();
        while(!q.isEmpty()) {
            int i = q.poll();
            cooked.add(recipes[i]);
            
            if(!map.containsKey(recipes[i])) {
                // if the map does not contain this recipe, this means
                // this recipe is not an ingredient for any other recipe
                // and no further processing is required
                continue;
            }
            
            for(String recipe: map.get(recipes[i])) {
                if(--indegree[index.get(recipe)] == 0) {
                    q.add(index.get(recipe));
                }
            }
        }
        
        return cooked;
    }
}
