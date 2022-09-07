// Runtime: 234 ms (Top 86.20%) | Memory: 71.1 MB (Top 79.66%)
/*
    https://leetcode.com/problems/range-module/

    Idea is to use a height balanced tree to save the intervals. Intervals are kept
    according to the start point.
    We search for the position where the given range can lie, then check the previous if it overlaps
    and keep iterating forward while the intervals are overlapping.

    QueryRange:
    We first find the range of values in [left, right). Then for each of the overlapping intervals,
    we subtract the common range. Finally if the entire range is covered, then the range will become zero.
*/
class RangeModule {
private:
    struct Interval {
        const bool operator<(const Interval& b) const {
            // Important to implement for == case, otherwise intervals
            // with same start won't exist
            // return start < b.start || (start == b.start && end < b.end);

            // This is the best way to compare since tuple already have ordering implemented for
            // fields
            return tie(start, end) < tie(b.start, b.end);
        }

        int start = -1, end = -1;
        Interval(int start, int end): start(start), end(end) {};
    };

    set<Interval> intervals;
public:
    RangeModule() {

    }

    // TC: Searching O(logn) + O(n) Merging, worst case when current interval covers all, insertion would take O(1)
    // SC: O(1)
    void addRange(int left, int right) {
        Interval interval(left, right);
        // Find the position where interval should lie st the next interval's
        // start >= left
        auto it = intervals.lower_bound(interval);

        // check if previous overlaps, move the iterator backwards
        if(!intervals.empty() && it != intervals.begin() && prev(it)->end >= interval.start) {
            --it;
            interval.start = min(it->start, interval.start);
        }

        // merge while intervals overlap
        while(it != intervals.end() && it->start <= interval.end) {
            interval.end = max(it->end, interval.end);
            intervals.erase(it++);
        }
        intervals.insert(interval);
    }

    // TC: Searching O(logn) + O(n) Merging, worst case when current interval covers all
    // SC: O(1)
    bool queryRange(int left, int right) {
        Interval interval(left, right);
        // Range of numbers that needs to be checked
        int range = right - left;
        // Find the position where interval should lie st the next interval's
        // start >= left
        auto it = intervals.lower_bound(interval);

        // check if previous interval overlaps the range, previous only
        // covers iff the open end > start of current. [prev.start, prev.end) [left, right)
        if(!intervals.empty() && it != intervals.begin() && prev(it)->end > interval.start) {
            // remove the common portion
            int common = min(interval.end, prev(it)->end) - interval.start;
            range -= common;
        }
        // for all the following overlapping intervals, remove the common portion
        while(it != intervals.end() && it->start <= interval.end) {
            int common = min(interval.end, it->end) - it->start;
            range -= common;
            ++it;
        }
        // Check if the entire range was covered or not
        return range == 0;
    }

    // TC: Searching O(logn) + O(n) Merging, worst case when current interval covers all
    // SC: O(1)
    void removeRange(int left, int right) {
        Interval interval(left, right);
        // Find the position where interval should lie st the next interval's
        // start >= left
        auto it = intervals.lower_bound(interval);

        // check if previous overlaps, then move the iterator position backwards
        if(!intervals.empty() && it != intervals.begin() && prev(it)->end > interval.start)
            --it;

        // For each of the overlapping intervals, remove the common portions
        while(it != intervals.end() && it->start < interval.end) {
            // Start and End of common portion
            int common_start = max(interval.start, it->start);
            int common_end = min(interval.end, it->end);

            // only a section of interval overlaps, remove that part
            // an overlapping interval might have to be broken into two non-overlapping parts
            // Eg [---------------------) Bigger interval
            // [--------) Ongoing interval
            // [------) [-----) Original interval broken into left and right parts

            // check if there is some range left on the left side
            if(it->start < common_start)
                intervals.insert(Interval(it->start, common_start));

            // check if there is some range left on the right side
            if(it->end > common_end)
                intervals.insert(Interval(common_end, it->end));

            // Remove the original interval
            intervals.erase(it++);
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */