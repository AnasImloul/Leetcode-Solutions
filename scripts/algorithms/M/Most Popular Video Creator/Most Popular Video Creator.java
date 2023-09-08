// Runtime: 96 ms (Top 26.5%) | Memory: 129.58 MB (Top 6.0%)

class Solution {
    public List<List<String>> mostPopularCreator(String[] creators, String[] ids, int[] views) {
        Map<String, Long> popularity = new HashMap<>();
        Map<String, Map<String, Long>> info = new HashMap<>();
        List<List<String>> result = new ArrayList<>();
        int len = creators.length;
        long maxPop = 0;
        
        for (int i = 0; i < len; i++) {
            String name = creators[i];
            String id = ids[i];
            int view = views[i];
            long totalView = popularity.getOrDefault(name, (long)0) + (long)view;
            popularity.put(name, totalView);
            Map<String, Long> nameInfo = info.getOrDefault(name, new HashMap<>());
			
			// Uncomment next line and remove the line after will get the last one correct. The correct times of view is the maximum value instead of the accumulation of them.
			// long idView = Math.max(nameInfo.getOrDefault(id, (long)0), (long)view);
			
            long idView = nameInfo.getOrDefault(id, (long)0) + (long)view;
            nameInfo.put(id, idView);
            info.put(name, nameInfo);
            
            if (totalView > maxPop) {
                maxPop = totalView;
            }
        }
        
        for (Map.Entry<String, Long> entry : popularity.entrySet()) {
            if (entry.getValue() == maxPop) {
                List<String> temp = new ArrayList<>();
                temp.add(entry.getKey());
                result.add(temp);
            }
        }
        
        for (List<String> list : result) {
            String name = list.get(0);
            List<String> winner = new ArrayList<>();
            long maxView = 0;
            
            for (Map.Entry<String, Long> entry : info.get(name).entrySet()) {
                long view = entry.getValue();
                String id = entry.getKey();
                
                if (view > maxView) {
                    winner.clear();
                    winner.add(id);
                    maxView = view;
                } else if (view == maxView) {
                    winner.add(id);
                }
            }
            
            Collections.sort(winner);
            list.add(winner.get(0));
        }
        
        return result;
    }
}