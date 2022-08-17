class Solution:
    # 668 ms, 99.52%. Time: O(NlogN). Space: O(N)
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        
        def is_within_1hr(t1, t2):
            h1, m1 = t1.split(":")
            h2, m2 = t2.split(":")
            if int(h1) + 1 < int(h2): return False
            if h1 == h2: return True
            return m1 >= m2
        
        records = collections.defaultdict(list)
        for name, time in zip(keyName, keyTime):
            records[name].append(time)
        
        rv = []
        for person, record in records.items():
            record.sort()
			# Loop through 2 values at a time and check if they are within 1 hour.
            if any(is_within_1hr(t1, t2) for t1, t2 in zip(record, record[2:])):
                rv.append(person)
        return sorted(rv)
                  
