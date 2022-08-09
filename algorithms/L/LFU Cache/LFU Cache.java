	class LFUCache {
    // Declare Node class for Doubly Linked List 
    class Node{
        int key,value,freq;// to store key,value and frequency
        Node prev,next;// Next and Previous Pointers
        Node(int k,int v){
        // initializing in constructor
            key=k;
            value=v;
            freq=1;
        }
        
    }
    // Declare class for List of Doubly Linked List
    class List{
        int size;
        Node head,tail;
        List(){
        // initializing in constructor
            size=0;
            head=new Node(-1,-1);// Default values
            tail=new Node(-1,-1);
            head.next=tail;
            tail.prev=head;
        }
        // To insert at the start of the list
        void ins(Node newNode){
            Node temp=head.next;
            head.next=newNode;
            newNode.prev=head;
            newNode.next=temp;
            temp.prev=newNode;
            size++;
            
        }
        // To delete specific node
        void del(Node newNode){
            Node pr=newNode.prev;
            Node nx=newNode.next;
            pr.next=nx;
            nx.prev=pr;
            size--;
        }
    }
    Map<Integer,Node>mp;// to store key and Node
    Map<Integer,List>listMap;// to store frequency and Doubly Linked List
    int maxSize,minFreq,currSize;// to store total size , minimum frequency and current size of the list
    public LFUCache(int capacity) {
        // initializing in constructor
        maxSize=capacity;
        minFreq=0;
        currSize=0;
        mp=new HashMap<Integer,Node>();
        listMap=new HashMap<Integer,List>();
    }
    
    public int get(int key) {
        // if map contains the specific key 
        if(mp.containsKey(key)){
            Node node=mp.get(key);
            int val=node.value;
            updateFreq(node);// to update the frequency of the node
            return val;            
        }
        //otherwise
        return -1;
    }
    
    public void put(int key, int value) {
        // one of the corner case
        if(maxSize==0)
            return;
        // if map contains the specific key 
        if(mp.containsKey(key)){
            Node node=mp.get(key);
            node.value=value; // update the value of the node
            updateFreq(node);// to update the frequency of the node
        }
        else{
        // if current size is equal to spcified capacity of the LFU list
            if(maxSize==currSize){
                List list=listMap.get(minFreq);
                mp.remove(list.tail.prev.key);// to remove the LRU of the LFU from key-node map
                
                // here LFU is list and even if its is a single element or multiple tail.prev(LRU) is the required element
                
                list.del(list.tail.prev);// to remove the LRU of the LFU from freq-list map
                currSize--;
            }
            currSize++;
            minFreq=1;// reset minFreq to 1 because of adding new node
            List list= new List();
            // If listMap already contains minFreq list
            if(listMap.containsKey(minFreq)){
                list=listMap.get(minFreq);
            }
            Node node = new Node(key,value);// creating a new node
            list.ins(node); // inserting new node to the list
            mp.remove(key); 
            mp.put(key,node); // inserting updated new node to the key-node map
            listMap.remove(minFreq);
            listMap.put(minFreq,list);// inserting updated list to the listMap        
        }
    }
    public void updateFreq(Node newNode){
        mp.remove(newNode.key);// to remove the node from key-node map
        listMap.get(newNode.freq).del(newNode);// to remove the node from listmap
        
        // If node's freq was minimum and after removing it from the listMap, size is 0
        if(newNode.freq==minFreq && listMap.get(newNode.freq).size==0){
            minFreq++;
        }
        List higherFreqList= new List();
        // If listMap already contains node's freq +1 th list
        if(listMap.containsKey(newNode.freq+1)){
            higherFreqList= listMap.get(newNode.freq+1);
        }
        newNode.freq++; // updating node's frequency
        higherFreqList.ins(newNode); // inserting node to list
        listMap.remove(newNode.freq);
        listMap.put(newNode.freq,higherFreqList);// reinserting list to listMap
        mp.remove(newNode.key);
        mp.put(newNode.key,newNode);// reinserting node to key-node map
    }
}
