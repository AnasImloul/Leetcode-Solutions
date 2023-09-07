// Runtime: 36 ms (Top 90.0%) | Memory: 59.11 MB (Top 43.3%)

class Fenwick {
    public int[] tree;  //Binary indexed Tree array
    
    //initialize a new Fenwick tree of size length
    public Fenwick(int length) {
        tree = new int[length];
    }
    
    //Returns the sum of values in an array from range [0, i]
    public int sum(int i) {
        int sum = 0;
        while(i > 0) {
            sum += tree[i];
            i = i - (i & -i);  //flip the last set bit using 2's compliment
        }
        return sum;
    }
    
    //Returns sum of values in the given range [start, end]
    public int sumRange(int start, int end) {
        return sum(end) - sum(start - 1);
    }
    
    //updates the value at index i by "k" in tree
    public void update(int i, int k) {
        while(i < tree.length) {
            tree[i] += k;
            i = i + (i & -i);  //add last set bit
        }
    }
}
class Solution {
    public int createSortedArray(int[] instructions) {
        //check for valid instructions
        if(instructions.length == 0) {
            return 0;
        }
        
        /*
            to check for values strictly greater than any ith value in the instructions, we 
            need to find the largest value in the instructions, this will denote the range 
			of values in the Fenwick tree
        */
        int max = 0;
        for(int value : instructions) {
            if(value > max) {
                max = value;
            }
        }
        
        /*
            initialize a Fenwick Tree structure to allow for the search of all values strictly less than and 
            strictly greater than instructions[i].
            
            since we need the tree to be 1 indexed, we add 1 to max
        */
        Fenwick tree = new Fenwick(max + 1);
        int cost = 0;
        
        for(int i = 0; i < instructions.length;i++) {
            int current_value = instructions[i];
            
            //get all the values less and greater than current_value
            int strictly_less = tree.sumRange(0, current_value - 1);
            int strictly_greater = tree.sumRange(current_value + 1, max);
            
            //update cost
            cost += Math.min(strictly_less, strictly_greater);
            
            //cost may be large so we mod it with 10^9 + 7
            cost = cost % ((int)1e9 + 7);
            
            //update the current_value's count in the FW tree
            tree.update(current_value, 1);
        }
        
        return cost;
    }
}