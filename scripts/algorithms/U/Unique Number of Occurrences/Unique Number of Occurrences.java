class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Arrays.sort(arr);
        HashSet<Integer> set = new HashSet<>();

        int c = 1;
        for(int i = 1; i < arr.length; i++)
        {
            if(arr[i] == arr[i-1]) c++;

            else
            {
                if(set.contains(c)) return false;

                set.add(c);

                c = 1;
            }
        }

        if(set.contains(c)) return false;

        return true;
    }
}