typedef struct _SmallerValueCount {
    _SmallerValueCount(const int &value, const int &originalIndex) :
        mValue(value), mOriginalIndex(originalIndex) {}
    
    int mValue = 0;
    int mOriginalIndex = 0;
} SmallerValueCount;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<SmallerValueCount> convertedNums;
        convertedNums.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i)
            convertedNums.emplace_back(SmallerValueCount(nums[i], i));

        vector<int> smallerCounts(convertedNums.size(), 0);
        merge_sort(convertedNums, smallerCounts, 0, nums.size() - 1);

        return smallerCounts;
    }

    void merge_sort(vector<SmallerValueCount> &nums, vector<int> &smallerCounts, const int &left, const int &right) {
        if (left >= right)
            return;
        const auto mid = (left + right) / 2;
        merge_sort(nums, smallerCounts, left, mid);
        merge_sort(nums, smallerCounts, mid+1, right);
        merge(nums, smallerCounts, left, mid, right);
    }

    void merge(vector<SmallerValueCount> &nums, vector<int> &smallerCounts, const int &left, const int &mid, const int &right)
    {
        vector<SmallerValueCount> buffer;
        buffer.reserve(right - left + 1);

        int i = left, j = mid + 1;
        int smallerCount = 0;
        while (i <= mid && j <= right)
            if (nums[i].mValue > nums[j].mValue)
            {
                ++smallerCount;
                buffer.push_back(nums[j]);
                ++j;
            }
            else
            {
                smallerCounts[nums[i].mOriginalIndex] += smallerCount;
                buffer.push_back(nums[i]);
                ++i;
            }

        while (i <= mid)
        {
            smallerCounts[nums[i].mOriginalIndex] += smallerCount;
            buffer.push_back(nums[i]);
            ++i;
        }

        while (j <= right)
        {
            buffer.push_back(nums[j]);
            ++j;
        }

        std::move(std::begin(buffer), std::end(buffer), std::next(std::begin(nums), left));
    }

};
