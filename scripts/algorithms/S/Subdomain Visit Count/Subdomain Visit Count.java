class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> result = new LinkedList<>();
        HashMap<String, Integer> hmap = new HashMap<>();
        
        for(int i = 0; i < cpdomains.length; i++){
            String[] stringData = cpdomains[i].split(" ");
            String[] str = stringData[1].split("\\.");
            String subDomains = "";
            
            for(int j = str.length-1; j >= 0; j--){
                subDomains = str[j] + subDomains;
                    
                if(!hmap.containsKey(subDomains))
                    hmap.put(subDomains, Integer.parseInt(stringData[0]));
                else
                    hmap.put(subDomains, hmap.get(subDomains) + Integer.parseInt(stringData[0]));
                subDomains = "." + subDomains;
            }
            
        }
        
        for(Map.Entry<String, Integer> entry: hmap.entrySet()){
            result.add(entry.getValue() + " " + entry.getKey());
        }
        
        return result;
    }
}
