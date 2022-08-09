class LRUCache {
    // Declare Node class for Doubly Linked List 
    class Node{
        int key,value;// to store key and value 
        Node next,prev; // Next and Previous Pointers
        Node(int k, int v){
            key=k;
            value=v;
        }
    }
    Node head=new Node(-1,-1); // Default values 
    Node tail=new Node(-1,-1);
    Map<Integer,Node>mp;  // to store key and Node
    int cap;
    public LRUCache(int capacity) {
        // initializing in constructor
        cap=capacity;
        head.next=tail;
        tail.prev=head;
        mp=new HashMap<Integer,Node>();
    }
    
    public int get(int key) {
        // if map contains the specific key 
        if(mp.containsKey(key)){
            Node existing=mp.get(key);
            del(existing);
            ins(existing);// reinserting to keep key after the head pointer and to update LRU list
            return existing.value;
        }
        //otherwise
        return -1;
    }
    
    public void put(int key, int value) {
        // if map contains the key
        if(mp.containsKey(key)){
            Node existing=mp.get(key);
            // remove from the map and delete from the LRU list
            mp.remove(key);
            del(existing);
        }
        // if map size is equal to spcified capacity of the LRU list
        if(mp.size()==cap){
            // remove from the map and delete from the LRU list
            mp.remove(tail.prev.key);
            del(tail.prev);
        }
        Node newNode = new Node(key,value);
        ins(newNode); 
        mp.put(key,head.next); 
    }
    public void ins(Node newNode){
        //Insert always after the head of the linkedList
        Node temp=head.next;
        head.next=newNode;
        newNode.prev=head;
        newNode.next=temp;
        temp.prev=newNode;
    }
    public void del(Node newNode){
        //Remove the specified node using previous and next pointers
        Node pr=newNode.prev;
        Node nx=newNode.next;
        pr.next=nx;
        nx.prev=pr;
        
    }
}

