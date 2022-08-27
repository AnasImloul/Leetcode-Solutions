// Runtime: 604 ms (Top 5.08%) | Memory: 138.6 MB (Top 22.35%)
class Solution {
// Uncomment/comment the below two lines for logs
// #define ENABLE_LOG(...) __VA_ARGS__
#define ENABLE_LOG(...)

public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int chunk_size = (int)(sqrt(nums.size())) / 2 * 2 + 2; // make it always an even number
        const int original_n = nums.size();
        constexpr int kPadPositive = 100006;
        constexpr int kPadNegative = -100006;
        // Pad the array to have size of a multiple of 4 * chunk_size
        for (int i=0; i<nums.size() % (4 * chunk_size); ++i) {
            nums.push_back(i % 2 == 0 ? kPadPositive : kPadNegative);
        }
        ENABLE_LOG(
            cout << "chunk_size: " << chunk_size << endl;

            cout << "padded array: ";
            for (int v: nums) cout << v << " "; cout << endl;
        )
        // Denotion:
        // the i-th positive number in original array: P_i.
        // the i-th negative number in original array: N_i

        // Step 1: Sort each chunk stably so that positive numbers appear before
        // negative numbers
        vector<int> chunk_buffer(chunk_size); // stores sorted result
        for (int i=0; i < nums.size(); i += chunk_size) {
            chunk_buffer.clear();
            for (int j=i; j<i+chunk_size; ++j)
                if (nums[j] > 0)
                    chunk_buffer.push_back(nums[j]);
            for (int j=i; j<i+chunk_size; ++j)
                if (nums[j] < 0)
                    chunk_buffer.push_back(nums[j]);
            // Copy chunk_buffer back to nums[i:i+chunk_size]
            copy_n(chunk_buffer.cbegin(), chunk_size, nums.begin() + i);
        }
        ENABLE_LOG(
            cout << "chunk-sorted array: ";
            for (int v: nums) cout << v << " "; cout << endl;
        )

        // Step 2: Merge every two chunks so that each chunk are either all positive numbers
        // or all negative numbers
        //
        // This is based on the observation that:
        // assuming chunk A having m positives followed by n negatives,
        // chunk B having p positives followed by q negatives,
        // a) if m+p >= chunk_size, we extract chunk_size positives into an all-positive chunk and put the remaining (m+p-chunk_size positives and n+q negatives) into the "buffer" chunk
        // b) if n+q >= chunk_size, we extract chunk_size negatives into an all-negative chunk and make the remaining (m+p positives and n+q-chunk_size negatives) the "buffer" chunk
        // Note that in either of the above two cases, the relative order for positive/negative numbers are unchanged

        chunk_buffer = vector<int>{nums.begin(), nums.begin() + chunk_size};
        for (int i = chunk_size; i<nums.size(); i+= chunk_size) {
            const int m = find_if(chunk_buffer.cbegin(), chunk_buffer.cend(), [](int v) {
                return v < 0;
            }) - chunk_buffer.cbegin();
            const int n = chunk_size - m;
            const int p = find_if(nums.cbegin() + i, nums.cbegin() + i + chunk_size, [](int v) {
                return v < 0;
            }) - (nums.cbegin() + i);
            const int q = chunk_size - p;

            if (m + p >= chunk_size) {
                // Copy positives to the previous chunk
                copy_n(chunk_buffer.cbegin(), m, nums.begin() + i - chunk_size);
                copy_n(nums.cbegin() + i, chunk_size - m, nums.begin() + i - chunk_size + m);
                vector<int> new_buffer;
                // the remaining positives (m+p-chunk_size) from this chunk
                copy_n(nums.cbegin() + i + (chunk_size - m),
                       p - (chunk_size - m),
                       back_inserter(new_buffer));
                // the remaining negatives in buffer
                copy_n(chunk_buffer.cbegin() + m, n, back_inserter(new_buffer));
                // the remaining negatives in this chunk
                copy_n(nums.cbegin() + i + p, q, back_inserter(new_buffer));
                chunk_buffer = move(new_buffer);
            } else {
                // Copy negatives to the previous chunk
                copy_n(chunk_buffer.cbegin() + m, n, nums.begin() + i - chunk_size);
                copy_n(nums.cbegin() + i + p, chunk_size - n, nums.begin() + i - chunk_size + n);
                vector<int> new_buffer;
                // the remaining positives in buffer
                copy_n(chunk_buffer.cbegin(), m, back_inserter(new_buffer));
                // the remaining positives in this chunk
                copy_n(nums.cbegin() + i, p, back_inserter(new_buffer));
                // the remaining negatives from this chunk
                copy_n(nums.cbegin() + i + p + chunk_size - n, q - (chunk_size - n),
                      back_inserter(new_buffer));
                chunk_buffer = move(new_buffer);
            }
        }
        copy_n(chunk_buffer.cbegin(), chunk_size, nums.begin() + nums.size() - chunk_size);

        ENABLE_LOG(
            cout << "homonegeous array: ";
            for (int v: nums) cout << v << " "; cout << endl;
        )

        // Step 3:
        // After the above step, we will have sqrt(N) / 2 all-positive chunks and sqrt(N) / 2 all-negative chunks.
        // Their initial chunk location is at (0, 1, 2, ..., sqrt(N))
        // We want them to interleave each other, i.e., Positive Chunk1, Negative Chunk 1, Positive Chunk 2, Negative Chunk 2
        // which could be achieved via cyclic permutation using an additional array tracking the target location of each chunk

        // due to above padding, chunk_cnt is always a multiple of 4
        const int chunk_cnt = nums.size() / chunk_size;

        vector<int> target(chunk_cnt); // O(sqrt(N))
        int positive_chunks = 0, negative_chunks = 0;
        for (int i=0; i<chunk_cnt; ++i) {
            if (nums[i * chunk_size] > 0)
                target[i] = (positive_chunks++) * 2;
            else
                target[i] = (negative_chunks++) * 2 + 1;
        }
        for (int i=0; i<chunk_cnt; ++i) {
            while (target[i] != i) {
                swap_ranges(nums.begin() + i * chunk_size,
                            nums.begin() + i * chunk_size + chunk_size,
                            nums.begin() + target[i] * chunk_size);
                swap(target[target[i]], target[i]);
            }
        }
        ENABLE_LOG(
            cout << "sorted array: ";
            for (int v: nums) cout << v << " "; cout << endl;
        )

        // Step 4:
        // Now we get Positive Chunk1, Negative Chunk 1, Positive Chunk 2, Negative Chunk 2, ...
        // For each pair of adjacent (positive, negative) chunks, we can reorder the elements inside
        // to make positive and negative numbers interleave each other
        vector<int> two_chunk_elements_interleaved; // O(2 * chunk_size) = O(sqrt(N))
        for (int i=0; i<nums.size(); i += 2 * chunk_size) {
            two_chunk_elements_interleaved.clear();
            for (int j=0; j<chunk_size; ++j)
            {
                two_chunk_elements_interleaved.push_back(nums[i + j]);
                two_chunk_elements_interleaved.push_back(nums[i + chunk_size + j]);
            }
            copy_n(two_chunk_elements_interleaved.cbegin(), 2 * chunk_size, nums.begin() + i);
        }
        // Remove paddings
        nums.resize(original_n);
        return nums;

    }
};