class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        auto isUndone = [](auto it, auto endIt) {
            return all_of(it, endIt, [](char c) { return c == '?'; });
        };
        vector<int> res;

        while (!isUndone(begin(target), end(target))) {
            auto prevResSize = size(res);

            for (size_t i = 0; i < size(target) - size(stamp) + 1; ++i) {
                auto it = begin(target) + i, endIt = it + size(stamp);
                if (isUndone(it, endIt))
                    continue;

                size_t j = 0;
                for (; j < size(stamp) && (*(it + j) == stamp[j] || *(it + j) == '?'); ++j);

                if (j == size(stamp)) {
                    fill(it, endIt, '?');
                    res.push_back(i);
                }
            }
            if (prevResSize == size(res))
                return {};
        }

        reverse(begin(res), end(res));
        return res;
    }
};
