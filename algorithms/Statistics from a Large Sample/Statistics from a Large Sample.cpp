class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> results;

        results.push_back(findMin(count));
        results.push_back(findMax(count));

        const int sum = std::accumulate(std::begin(count), std::end(count), 0);
        results.push_back(findMean(count, sum));

        if (sum % 2 == 0)
        {
            const auto left = findMedian(count, sum/2);
            const auto right = findMedian(count, sum/2 + 1);
            results.push_back ((left + right) / 2.0);
        }
        else
            results.push_back(findMedian(count, sum/2 + 1));

        results.push_back(findMode(count));

        return results;
    }
    
private:
    int findMin(const vector<int> &count) {
        const auto minPtr = std::find_if(std::begin(count), std::end(count), 
                                         [](const int& c) { return c > 0; });

        return minPtr - std::begin(count);
    }

    int findMax(const vector<int> &count) {
        const auto maxPtr = std::find_if(std::rbegin(count), std::rend(count), 
                                         [](const int& c) { return c > 0; });

        return (std::rend(count) - 1) - maxPtr;
    }

    int findMode(const vector<int> &count) {
    
        const auto maxCountPtr = std::max_element(begin(count), end(count));

        return maxCountPtr - std::begin(count);
    }

    double findMean(const vector<int> &count, const int &sum) {
        auto ratio = 1.0 / sum;
        auto mean = 0.0;

        for (int i = 0; i < count.size(); ++i)
            mean += count[i] * ratio * i;

        return mean;
    }

    int findMedian(const vector<int> &count, int medianCount) {
        for (int i = 0; i < count.size(); ++i)
            if (count[i] < medianCount)
                medianCount -= count[i];
        else
            return i;
        
        return -1;
    }
};
