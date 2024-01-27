// Runtime: 41 ms (Top 77.18%) | Memory: 57.40 MB (Top 33.18%)

class Solution
{
public
    int longestSubsequence(int[] arr, int difference)
    {
        // Storing the final answer as 1
        int length = arr.length, max_length = 1;
        HashMap<Integer, Integer> Terms_till_now = new HashMap<>();
        for (int i = 0; i < length; i++)
        {
            /*
            Find the number of terms, till curr_element - difference , say terms
            Mapping 1 + n to the current term of the sequence, i.e. curr_element
            */
            int terms = ((Terms_till_now.get(arr[i] - difference) == null) ? 0 : Terms_till_now.get(arr[i] - difference));
            Terms_till_now.put(arr[i], 1 + terms);
            max_length = Math.max(max_length, 1 + terms);
        }
        return max_length;
    }
}
