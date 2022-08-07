class SummaryRanges {
public:

    struct DSU {
        map<int, int>parent;
        map<int, int>sz;

        int find_parent(int a) {
            if(!parent.count(a)) {
                parent[a] = a;
                sz[a] = 1;
            }

            if(parent[a] == a) return a;
            return parent[a] = find_parent(parent[a]);
        }

        void union_sets(int a, int b) {
            if(!parent.count(a)) {
                parent[a] = a;
                sz[a] = 1;
            }

            if(!parent.count(b)) {
                parent[b] = b;
                sz[b] = 1;
            }


            a = find_parent(a);
            b = find_parent(b);

            if(a == b) return;

            parent[b] = a;
            sz[a] += sz[b];


        }

        void add(int a) {


            if(!parent.count(a)) {
                parent[a] = a;
                sz[a] = 1;
            } else return;



            if(parent.count(a + 1)) {
                union_sets(a, a + 1);
            }
            if(parent.count(a - 1)) {
                union_sets(a - 1, a);
            }
        }

        vector<vector<int>>getIntervals() {
            vector<vector<int>>intervals;
            for(auto [a, b]: parent) {
                if(a == b) {
                    intervals.push_back({a, a + sz[a] - 1});
                }
            }

            return intervals;
        }

    };
    
    DSU dsu;

    SummaryRanges() {
        this->dsu = DSU();
    }
    
    void addNum(int val) {
        dsu.add(val);
    }
    
    vector<vector<int>> getIntervals() {
        return dsu.getIntervals();
    }
};
