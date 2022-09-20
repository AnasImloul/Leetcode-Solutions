// Runtime: 68 ms (Top 48.70%) | Memory: 45.5 MB (Top 96.95%)
class Solution
{
    public List<List<String>> suggestedProducts(String[] products, String searchWord)
    {
        PriorityQueue<String> pq= new PriorityQueue<String>();
        List<List<String>> res= new LinkedList<List<String>>();
        List<String> segment= new LinkedList<String>();
        for(int i=0;i<products.length;i++)
            pq.offer(products[i]);

        for(int j=0;j<searchWord.length();j++)
        {
            segment= new LinkedList<String>();
            pq= reduce(pq,searchWord.substring(0,j+1));
            PriorityQueue<String> pri= new PriorityQueue<>(pq);
            int p=0;
            while(p<pq.size()&&p<3)
            {
                segment.add(pri.poll());
                p++;
            }
            res.add(segment);
        }
        return res;
    }
    public PriorityQueue<String> reduce(PriorityQueue<String> pr, String filter)
    {
        PriorityQueue<String> p= new PriorityQueue<>();
        String s="";
        while(!pr.isEmpty())
        {
            s=pr.poll();
            if(s.startsWith(filter))
                p.add(s);
        }
        return p;
    }
}