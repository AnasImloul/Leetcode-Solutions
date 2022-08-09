class Solution {
    public String findReplaceString(String s, int[] indices, String[] sources, String[] targets) {
        
        HashMap<Integer, String> subst = new HashMap<>();
        HashMap<Integer, String> tgt = new HashMap<>();
        
        for(int i = 0; i< indices.length; i++) {
            subst.put(indices[i], sources[i]);
            tgt.put(indices[i],targets[i]);
        }
        
        Arrays.sort(indices);
        
        String res = "";
        int count = 0;
        int avail[] = new int[indices.length];
        for(int i = 0; i< s.length(); i++) {
            if(count < indices.length && i == indices[count] && s.indexOf(subst.get(indices[count]), indices[count]) == indices[count]){
                res = res+""+tgt.get(indices[count]);
                i = i+ subst.get(indices[count]).length()-1;
                count++;
            } else {
                if(count < indices.length && i == indices[count])
                    count++;
                res+= s.charAt(i);
            }
        }
        
        return res;
    }
}
