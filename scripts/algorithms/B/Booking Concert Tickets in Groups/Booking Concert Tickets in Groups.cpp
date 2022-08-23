// Runtime: 639 ms (Top 96.14%) | Memory: 288.6 MB (Top 75.29%)
class BookMyShow {
    int occ = -1; // No row occupied initially
    vector<long long> sumTree, maxTree;
    int treeSize = 0, rowSeats = 0;

public:

    BookMyShow(int n, int m) {
        // Seg tree size
        this->treeSize = (int) 2 * pow(2, ceil((double)log2(n)));
        sumTree.resize(treeSize);
        maxTree.resize(treeSize);

        this->rowSeats = m;
        constructSumTree(m);
        constructMaxTree(m);
    }

    void constructSumTree(int m){
        int n = this->treeSize/ 2;

        // Filling the leaves
        for(int i=n; i<2*n;i++)
            this->sumTree[i] = (long long) m;

        // Forming the higher nodes
        for(int i=n-1;i>=1;i--)
            this->sumTree[i] = this->sumTree[2*i] + this->sumTree[2*i+1];
    }

    void constructMaxTree(int m){
        int n = this->treeSize/ 2;

        // Filling the leaves
        for(int i=n; i<2*n;i++)
            this->maxTree[i] = (long long) m;

        // Forming the higher nodes
        for(int i=n-1;i>=1;i--)
            this->maxTree[i] = max(this->maxTree[2*i], this->maxTree[2*i+1]);
    }

    long long rangeSum(int minRow, int maxRow){
        long long sum = 0;
        int n = treeSize / 2;
        minRow += n; maxRow += n;
        while(minRow <= maxRow){
            if(minRow % 2 == 1) sum += this->sumTree[minRow++]; // Right child
            if(maxRow % 2 == 0) sum += this->sumTree[maxRow--]; // Left child
            minRow /= 2; maxRow /= 2;
        }

        return sum;
    }

    void updateSumTree(int index, int newValue){
        int n = this->treeSize / 2;
        int temp = index;
        index += n;
        this->sumTree[index] = newValue; // Update leaf
        index /= 2;
        while(index > 0){
            this->sumTree[index] = this->sumTree[2*index] + this->sumTree[2*index + 1];
            index /= 2;
        }
    }

    long long rangeMax(int minRow, int maxRow){
        long long ans = 0;
        int n = this->treeSize / 2;
        minRow += n; maxRow += n;
        while(minRow <= maxRow){
            if(minRow % 2 == 1) ans = max(ans, this->maxTree[minRow++]); // Right child
            if(maxRow % 2 == 0) ans = max(ans, this->maxTree[maxRow--]); // Left child
            minRow /= 2; maxRow /= 2;
        }

        // cout<<"range max over"<<'\n';
        return ans;
    }

    void updateMaxTree(int index, int newValue){
        int n = this->treeSize / 2;
        int temp = index;
        index += n;
        this->maxTree[index] = newValue; // Update leaf
        index /= 2;
        while(index > 0){
            this->maxTree[index] = max(this->maxTree[2*index], this->maxTree[2*index + 1]);
            index /= 2;
        }
    }

    vector<int> gather(int k, int maxRow) {
        int minRow = occ + 1;
        if(maxRow < minRow) return {};
        if(rangeMax(minRow, maxRow) < k) return {};

        int minIndex = maxRow;
        int seats = 0;
        int low = minRow, high = maxRow;
        while(low <= high){
            int midRow = (low + high)/2;
            int maxSeats = rangeMax(minRow, midRow);
            if(maxSeats >= k){
                high = midRow - 1;
                seats = maxSeats;
                minIndex = midRow;
            }
            else low = midRow + 1;
        }

        int r = minIndex, c = this->rowSeats - seats;

        // Updatng the segment trees
        this->updateMaxTree(minIndex, seats - k);
        this->updateSumTree(minIndex, seats - k);
        return {r,c};
    }

    bool scatter(int k, int maxRow) {
        int minRow = occ + 1;
        if(maxRow < minRow) return false;
        if(rangeSum(minRow, maxRow) < k) return false;

        int minIndex = maxRow;
        long long seats = 0;
        int low = minRow, high = maxRow;
        while(low <= high){
            int midRow = (low + high)/2;
            long long rangeSeats = rangeSum(minRow, midRow);
            if(rangeSeats >= k){
                high = midRow - 1;
                seats = rangeSeats;
                minIndex = midRow;
            }
            else low = midRow + 1;
        }

        // Updating the occupied rows
        occ = minIndex - 1;

        // Updating the segment trees
        this->updateSumTree(minIndex, seats - k);
        this->updateMaxTree(minIndex, seats - k);
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */