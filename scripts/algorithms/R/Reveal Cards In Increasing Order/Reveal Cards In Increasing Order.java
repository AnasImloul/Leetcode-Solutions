// Runtime: 5 ms (Top 59.29%) | Memory: 44.5 MB (Top 28.33%)
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) { // deck=[ 17,13,11,2,3,5,7 ]
        Queue<Integer> ql = new LinkedList<Integer>();
        for(int i=0;i<deck.length;i++)
            ql.add(i);
            // now the queue is [ 0, 1, 2, 3, 4, 5, 6 ]

        int[] ans = new int[deck.length];
        int k=0;
                                     //index : 0 1 2 3 4 5 6
        Arrays.sort(deck); //deck=[ 2 ,3 ,5, 7, 13, 11, 17 ]

        while(!ql.isEmpty())
        {
            ans[ql.peek()]=deck[k];
            ql.poll();
            k++;
            if(!ql.isEmpty())
            {
                ql.add(ql.peek());
                ql.poll();
            }
        }
        /*
        ql=[0,1,2,3,4,5,6]
        k=0;
        ql=[2,3,4,5,6,1]
        ans=[2,0,0,0,0,0,0] ans[0]=deck[0]
        k=1;
        ql=[4,5,6,1,3]
        ans=[2,13,0,0,0,0,0] ans[2]=deck[1]
        k=2;
        ql=[6,1,3,5]
        ans=[2,13,3,0,0,0,0] ans[4]=deck[2]
        k=3;
        ql=[3,5,1]
        ans=[2,13,3,11,0,0,0] ans[6]=deck[3]
        k=4;
        ql=[1,5]
        ans=[2,13,3,11,5,0,0] ans[3]=deck[4]
        k=5;
        ql=[5]
        ans=[2,13,3,11,5,17,0] ans[1]=deck[5]
        k=6;
        ql=[]
        ans=[2,13,3,11,5,17,7] ans[5]=deck[6]
        */

      return ans;
    }
}