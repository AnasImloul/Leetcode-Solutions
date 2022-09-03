// Runtime: 183 ms (Top 63.97%) | Memory: 124.7 MB (Top 57.27%)
class MedianFinder {

    PriorityQueue maxHeap;
    PriorityQueue minHeap;

    public MedianFinder() {
        maxHeap= new PriorityQueue<Integer>((a,b)->b-a);
        minHeap= new PriorityQueue<Integer>();
    }

    public void addNum(int num) {

        //Pushing
        if ( maxHeap.isEmpty() || ((int)maxHeap.peek() > num) ){
            maxHeap.offer(num);
        }
        else{
            minHeap.offer(num);
        }

        //Balancing
        if ( maxHeap.size() > minHeap.size()+ 1){
             minHeap.offer(maxHeap.peek());
             maxHeap.poll();
        }
        else if (minHeap.size() > maxHeap.size()+ 1 ){
             maxHeap.offer(minHeap.peek());
             minHeap.poll();
        }

    }

    public double findMedian() {

        //Evaluating Median
        if ( maxHeap.size() == minHeap.size() ){ // Even Number
            return ((int)maxHeap.peek()+ (int)minHeap.peek())/2.0;
        }
        else{ //Odd Number
             if ( maxHeap.size() > minHeap.size()){
                 return (int)maxHeap.peek()+ 0.0;
             }
            else{ // minHeap.size() > maxHeap.size()
                 return (int)minHeap.peek()+ 0.0;
            }
        }
    }
}