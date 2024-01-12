// Runtime: 33 ms (Top 95.27%) | Memory: 45.90 MB (Top 56.76%)

class Solution {
    class Basket{
        int appleCount;
        int day;
        Basket(int appleCount, int day){
            this.appleCount = appleCount;
            this.day = day;
        }
    }
    public int eatenApples(int[] apples, int[] days) {
        int n = apples.length;
        PriorityQueue<Basket> q = new PriorityQueue<>(n,(b1,b2) -> b1.day-b2.day);
        int i; // counter for day 
		int apple = 0; // count of consumed apple
        
        for(i=0; i<n; i++){
            while(q.peek()!=null && (q.peek().appleCount < 1 || q.peek().day < i+1)){
                q.poll();
            }
            if(apples[i] != 0 && days[i] !=0){
                q.add(new Basket(apples[i], i+days[i]));
            }
            if(q.peek()==null) continue;           
            q.peek().appleCount--;
            apple++;
        }
                
        while(q.peek() != null){
            Basket basket = q.poll();
            if(basket.day < i) continue;
            apple += Math.min(basket.appleCount, basket.day-i);
            i += Math.min(basket.appleCount, basket.day-i);
        }
        return apple;
    }
}
