// Runtime: 46 ms (Top 83.25%) | Memory: 51.6 MB (Top 94.52%)
class Node{
    int data, freq, time;
    Node(int data, int freq, int time){
        this.data=data;
        this.freq=freq;
        this.time=time;
    }
}

class CompareNode implements Comparator<Node>{
    @Override
    public int compare(Node a, Node b){
        if(a.freq-b.freq==0){
            return b.time-a.time;
        }
        return b.freq-a.freq;
    }
}

class FreqStack {
    PriorityQueue<Node> pq;
    Map<Integer,Node> map;
    int c=0;
    public FreqStack(){
        pq=new PriorityQueue<>(new CompareNode());
        map=new HashMap<>();
    }

    public void push(int val){
        c++;
        int freq=1;
        if(map.containsKey(val)){
            freq+=map.get(val).freq;
        }
        map.put(val, new Node(val, freq, c));
        pq.add(new Node(val,freq,c++));
    }

    public int pop() {
        Node r=pq.remove();
        Node a=map.get(r.data);
        a.freq--;
        return r.data;
    }
}