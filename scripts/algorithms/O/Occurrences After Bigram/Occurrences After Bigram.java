// Runtime: 0 ms (Top 100.0%) | Memory: 41.60 MB (Top 23.12%)

class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] st = text.split(" ");
        List<String> l = new ArrayList<String>();
        int  i =0,n = st.length;

        while(i<n)
        {
            if(st[i].equals(first))
                if(i+1<n-1 && st[i+1].equals(second))
                    l.add(st[i+2]);
            i++;
        }

        return l.toArray(new String[0]);
    }
}

