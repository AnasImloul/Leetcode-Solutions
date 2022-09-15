// Runtime: 98 ms (Top 88.24%) | Memory: 61 MB (Top 77.65%)
class Solution {
    public int openLock(String[] deadends, String target) {
// Converted target to Integer type.
        int t = Integer.parseInt(target);
        HashSet<Integer> visited = new HashSet<>();

// Converting deadend strings to Integer type. To prevent from visiting deadend, we already mark them visited.
        for(String str: deadends){
            visited.add(Integer.parseInt(str));
        }
// BFS
        Queue<Integer> q = new ArrayDeque<>();
// We make sure that 0 itself isn't a deadend
        if(visited.contains(0)){
            return -1;
        }
        q.add(0);
        visited.add(0);
        int level = 0;
        while(q.size() > 0){
            int size = q.size();
            while(size-->0){
                int elem = q.remove();
                if(t == elem){
                    return level;
                }
// Will help check 4 digits of the element. From digit with low precendence(ones place) to high precedence(thousands place)
                for(int i = 1; i < 10000; i= i*10){
// The wheel can be rotated in two directions. Hence two numbers.
                    int num1;
                    int num2;
// The wheel at 0 can become 1 or 9 due to wrapping.
                    if(elem / i % 10 == 0){
                        num1=elem + i;
                        num2 = elem+ i * 9;
                    }
// The wheel at 9 can become 0 or 8 due to wrapping.
                    else if(elem / i % 10 == 9){
                        num1 = elem - i * 9;
                        num2 = elem -i;
                    }
                    else{
                        num1 = elem -i;
                        num2 = elem + i;
                    }
// Checking if numbers have already been visited.
                    if(!(visited.contains(num1))){
                            visited.add(num1);
                            q.add(num1);
                        }
                    if(!(visited.contains(num2))){
                        visited.add(num2);
                        q.add(num2);
                    }
                }
            }
            level++;
        }
        return -1;
    }
}