// Runtime: 1278 ms (Top 91.11%) | Memory: 53.30 MB (Top 95.56%)

class Solution:
    def findMaximumElegance(self, items: List[List[int]], k: int) -> int:
        items.sort(key=lambda item: item[0], reverse=True)
        
        grouped = defaultdict(list)
        for profit, category in items[:k]:
            grouped[category].append(profit)
        
        duplicates = []
        for category, group in grouped.items():
            group.sort(reverse=True)
            if len(group) > 1:
                duplicates.extend(grouped[category][1:])
        heapify(duplicates)
            
        curSum = sum(profit for profit, category in items[:k])
        res = curSum + len(grouped) ** 2
        
        for profit, category in items[k:]:
            if category in grouped:
                continue
            
            if not duplicates:
                break
            
            duplicate = heappop(duplicates)
            curSum -= duplicate
            curSum += profit
            grouped[category].append(profit)
            
            res = max(curSum + len(grouped) ** 2, res)
        
        return res
