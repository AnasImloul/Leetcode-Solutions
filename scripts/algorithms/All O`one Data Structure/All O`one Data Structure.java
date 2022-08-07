//Intuitions get from the top answer by @AaronLin1992
class AllOne {
    //Thoughts
    //inc() and dec() can be done with a Simple Map, but how do we getMaxKey() and getMinKey() in O(1)?
    //in order to get max and/or min on the fly, we need to maintain some kind of ordering so that we can always access max and min
    //to maintain some kind of ordering, the first thing we think about is arrays/lists, however, arrays/lists when insert and delete in the middle, it is O(N) operation
    //so instead, a linked list might work
    //as a result, we considering using Map(s) and LinkedList for our supporting data structures, details below
    
    private Map<String, Bucket> stringToBucket; //maps a string to bucket
    private Map<Integer, Bucket> countToBucket; //maps string count to bucket, note that because when we design this we can have multiple strings in a bucket, that makes it convenient so that for each count, we only need 1 bucket, thus the map data structure
    private BucketList bucketList;
    
    //first, we need to create a class for the LinkedList elements
    class Bucket {
        private Bucket prev;
        private Bucket next;
        
        private int count; //recording the count of instances
        private Set<String> keys; //note that we are using Set of Strings. The reason is because multiple Strings can have the same count and we want to put them in one bucket. This makes the problem easier to solve instead of putting them into different buckets.
        
        Bucket() {
            this.keys = new HashSet<>();
        }
        
        Bucket(String key) {
            this();
            this.count = 1;
            this.keys.add(key);
        }
        
    }
    
    //second, we need to create a linked list data structure of buckets
    class BucketList {
        private Bucket dummyHead; //the fake head before the real head //useful for getMinKey()
        private Bucket dummyTail; //the fake tail before the real tail //useful for getMaxKey()
        
        public BucketList() {
            dummyHead = new Bucket();
            dummyTail = new Bucket();
            dummyHead.next = dummyTail;
            dummyTail.prev = dummyHead;
        }
        
        public Bucket createNewBucket(String key) {
            Bucket bucket = new Bucket(key);
            
            Bucket nextBucket = dummyHead.next;
            dummyHead.next = bucket;
            bucket.prev = dummyHead;
            nextBucket.prev = bucket;
            bucket.next = nextBucket;
            
            return bucket;
        }
        
        public Bucket createBucketToTheRight(Bucket fromBucket, String key, int count) {
            //initialize
            Bucket toBucket = new Bucket(key);
            toBucket.count = count;
            
            Bucket nextBucket = fromBucket.next;
            fromBucket.next = toBucket;
            toBucket.prev = fromBucket;
            nextBucket.prev = toBucket;
            toBucket.next = nextBucket;
            
            return toBucket;
        }
        
        public Bucket createBucketToTheLeft(Bucket fromBucket, String key, int count) {
            //initialize
            Bucket toBucket = new Bucket(key);
            toBucket.count = count;
            
            Bucket prevBucket = fromBucket.prev;
            prevBucket.next = toBucket;
            toBucket.prev = prevBucket;
            fromBucket.prev = toBucket;
            toBucket.next = fromBucket;
            
            return toBucket;
        }
        
        public boolean clean(Bucket oldBucket) {//clean bucket if bucket does not have any keys
            if (!oldBucket.keys.isEmpty()) {
                return false;
            }
            
            removeBucket(oldBucket);
            
            return true;
        }
        
        public void removeBucket(Bucket bucket) {
            Bucket prevBucket = bucket.prev;
            Bucket nextBucket = bucket.next;
            
            prevBucket.next = nextBucket;
            nextBucket.prev = prevBucket;
        }
    }
    

    public AllOne() {
        this.stringToBucket = new HashMap<>();
        this.countToBucket = new HashMap<>();
        this.bucketList = new BucketList();
    }
    
    public void inc(String key) {
        //first check if the string already present
        if (!stringToBucket.containsKey(key)) { //if not present 
            Bucket bucket = null;
            
            //check if there is count of 1 bucket already
            if (!countToBucket.containsKey(1)) { //if does not contain count of 1
                //we need to create a new bucket for count of 1 and add to the head (the minimum). Because count 1 should be the minimum exists in the bucket list
                bucket = bucketList.createNewBucket(key);
            } else { //if contains count of 1
                //then we just need to add the key to the bucket
                bucket = countToBucket.get(1);
                bucket.keys.add(key);
            }
            
            //don't forget to update the maps
            stringToBucket.put(key, bucket);
            countToBucket.put(1, bucket);
        } else { //if the key alreay present
            //first of all we need to get the current count for the key
            Bucket oldBucket = stringToBucket.get(key);
            Bucket newBucket = null;
            
            int count = oldBucket.count;
            count++; //increment 1
            //don't forget that we need to remove the key from existing bucket
            oldBucket.keys.remove(key);
            
            //now let's add the key with new count
            if (countToBucket.containsKey(count)) { //if there is already a bucket for this count
                //then just add to the set of keys
                newBucket = countToBucket.get(count);
                newBucket.keys.add(key);
            } else { //if there is no bucket for this count, create a new bucket, but where to place it? Ans: to the right of the old bucket
                newBucket = bucketList.createBucketToTheRight(oldBucket, key, count);     
            }
            
            //special scenario: if old bucket don't have any keys after removing the last key, then we need to remove the entire old bucket from the bucket list
            if (bucketList.clean(oldBucket)) {
                countToBucket.remove(oldBucket.count); //remove from map because the old bucket was removed
            }
            
            //don't forget to update the maps
            stringToBucket.put(key, newBucket);
            countToBucket.putIfAbsent(count, newBucket);
        }
    }
    
    public void dec(String key) {
        //since it is given that "It is guaranteed that key exists in the data structure before the decrement." we don't do additional validation for key exists here
        Bucket oldBucket = stringToBucket.get(key);
        Bucket newBucket = null;
        
        int count = oldBucket.count;
        count--; //decrement
        oldBucket.keys.remove(key);
        
        //special scenario - when count == 0
        if (count == 0) {
            stringToBucket.remove(key);
        } else {
            //now let's find a new bucket for the decremented count
            if (countToBucket.containsKey(count)) {//if there is already a bucket for the count
                newBucket = countToBucket.get(count);
                newBucket.keys.add(key);
            } else {//if there is no bucket for the count, then following similar logic as before, we need to add a bucket to the left of the existing bucket
                newBucket = bucketList.createBucketToTheLeft(oldBucket, key, count);
            }
            
            //don't forget to update the maps
            stringToBucket.put(key, newBucket);
            countToBucket.putIfAbsent(count, newBucket);
        }
        
        //special scenario: if old bucket don't have any keys after removing the last key, then we need to remove the entire old bucket from the bucket list
        if (bucketList.clean(oldBucket)) {
            countToBucket.remove(oldBucket.count); //remove from map because the old bucket was removed
        }
    }
    
    public String getMaxKey() {
        Set<String> maxSet = bucketList.dummyTail.prev.keys;
        
        return maxSet.isEmpty() ? "" : maxSet.iterator().next(); //if maxSet is empty, that means the bucketList don't have actual buckets
        
    }
    
    public String getMinKey() {
        Set<String> minSet = bucketList.dummyHead.next.keys;
        
        return minSet.isEmpty() ? "" : minSet.iterator().next(); //if minSet is empty, that means the bucketList don't have actual buckets
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */
