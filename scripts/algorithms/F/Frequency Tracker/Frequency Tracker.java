// Runtime: 42 ms (Top 65.45%) | Memory: 104.10 MB (Top 90.91%)

class FrequencyTracker {
    int ele[], freq[];
    public FrequencyTracker() {
        ele=new int[100001];
        freq=new int[100001];
    }
    
    public void add(int number) {
        if(ele[number]>0)
        {
            freq[ele[number]]--;
        }
        ele[number]++;
        freq[ele[number]]++;
    }
    
    public void deleteOne(int number) {
        if(ele[number]>0)
        {
            freq[ele[number]]--;
            ele[number]--;
            freq[ele[number]]++;
        }
    }
    
    public boolean hasFrequency(int frequency) {
        return freq[frequency]>0;
    }
}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker obj = new FrequencyTracker();
 * obj.add(number);
 * obj.deleteOne(number);
 * boolean param_3 = obj.hasFrequency(frequency);
 */
