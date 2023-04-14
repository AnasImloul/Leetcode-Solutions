class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) 
    {
         //to keep the track of the number of extra rung to be added
         long long int count = 0;
       
         //our curr pos at the beggining
         long long int currpos = 0;

         //to keep the track of the next pos to be climed
         long long int nextposidx = 0;

         while(true)
         {
             if(currpos == rungs[rungs.size()-1])
             {
                 break;
             }

             if((rungs[nextposidx] - currpos) <= dist)
             {
                 currpos = rungs[nextposidx];
                 nextposidx++;
             }
             else
             {
                 //cout<<"hello"<<endl;
                 long long int temp = (rungs[nextposidx] - currpos);
                 //cout<<"temp = "<<temp<<endl;
                 
                 if((temp%dist) == 0)
                 {
                     long long int val = temp/dist;
                     count = count + (val - 1);
                 }
                 else
                 {
                    long long int val = floor(((temp*1.00)/(dist*1.00)));
                    count = count + (val);
                 }
                 currpos = rungs[nextposidx];
             }
         }
         return count;
    }
};