// Runtime: 1580 ms (Top 6.50%) | Memory: 171.4 MB (Top 19.88%)

class Solution {
public:
    vector < int > Ar , Ap , Br , Bp; // alice and bob parent and rank arrays
    static bool cmp(vector < int > & a , vector < int > & b){
      return a[0] > b[0];
    }
    // lets create the alice graph first
    // find function for finding the parent nodes
    int find1(int x){
     if(x == Ap[x]) return x;
         return Ap[x] = find1(Ap[x]);
    }
    // if nodes are already connected return 1 else make the connection and return 0
    bool union1( int x , int y){
      int parX = find1(x);
    int parY = find1(y);
        if(parX == parY) return 1;
        if(Ar[parX] > Ar[parY]){
          Ap[parY] = parX;
        }
         else if(Ar[parX] < Ar[parY]){
          Ap[parX] = parY;
        }
        else {
           Ap[parY] = parX;
            Ar[parX]++;
        }
        return 0;
    }
    // same thing do for bob graph
     int find2(int x){
     if(x == Bp[x]) return x;
         return Bp[x] = find2(Bp[x]);
    }

    bool union2( int x , int y){
      int parX = find2(x);
    int parY = find2(y);
        if(parX == parY) return 1;
        if(Br[parX] > Br[parY]){
          Bp[parY] = parX;
        }
         else if(Br[parX] < Br[parY]){
          Bp[parX] = parY;
        }
        else {
           Bp[parY] = parX;
            Br[parX]++;
        }
        return 0;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
       Ar.resize(n , 1); Ap.resize(n , 1); Br.resize(n , 1); Bp.resize(n , 1);

        for(int i = 0; i<n ; i++){
         Ap[i] = i;
            Bp[i] = i;
        }

        sort(edges.begin() , edges.end() , cmp);
        int ans = 0;
        // give priority to 3rd type of vertices
        for(auto a : edges){
         if(a[0] != 3) continue;
            if(union1(a[1]-1 , a[2]-1))ans++;

           union2(a[1] -1, a[2]-1);

        }
        // now try the edges one by one and check if it the given nodes are already connected in respective alice and bob graph or not
        for(auto a : edges){
        if(a[0] == 3) continue;
            if(a[0] == 1) {
             if(union1(a[1]-1 , a[2]-1))ans++; }

            else {
              if(union2(a[1]-1 , a[2]-1))ans++;}
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i< n ; i++){
          if(Ap[i] == i) cnt1++;
            if(Bp[i] == i) cnt2++;
        }
        if(cnt1 >1 | cnt2 >1) return -1;

        return ans;

    }
};