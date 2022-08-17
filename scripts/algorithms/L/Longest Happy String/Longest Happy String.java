class Solution {
    public String longestDiverseString(int a, int b, int c) {
        StringBuilder sb = new StringBuilder();
        PriorityQueue<Pair> queue = new PriorityQueue<>((x, y) -> y.val - x.val);
        
        if (a > 0) {
            queue.add(new Pair('a', a));
        }
        if (b > 0) {
            queue.add(new Pair('b', b));
        }
        if (c > 0) {
            queue.add(new Pair('c', c));
        }
        
        sb.append("dd");
        
        while (!queue.isEmpty()) {
            //get max count pair
            Pair first = queue.remove();
            
            //check if last two chars in sb are same as first pair char
            if (first.c == sb.charAt(sb.length() - 2) && first.c == sb.charAt(sb.length() - 1)) {
                //if queue is empty we can't add anymore to sb as it will violate rule for max 2 same chars
                if (queue.isEmpty()) {
                    break;
                }
                
                //we can add the next max count pair now
                Pair second = queue.remove();
                sb.append(second.c);
                
                // update second pair and add it back
                if (second.val > 1) {
                    second.val--;
                    queue.add(second);
                }
                //add first pair (which we did not use) back to queue
                queue.add(first);
            } else { // this means we can add first pair char as it doesn't violate the max 2 same chars rule
                sb.append(first.c);
                
                //update first pair and add it back
                if (first.val > 1) {
                    first.val--;
                    queue.add(first);
                }
            }
        }
        
        //exclude "dd" from the result
        return sb.substring(2);
    }
}

class Pair {
    char c;
    int val;
    
    Pair(char c, int val) {
        this.c = c;
        this.val = val;
    }
}
