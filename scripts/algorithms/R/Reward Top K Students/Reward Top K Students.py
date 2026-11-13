# Runtime: 82 ms (Top 25.17%) | Memory: 26.90 MB (Top 97.62%)

class Solution:
    def topStudents(self, pos_feed: List[str], neg_feed: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        pos, neg, score_id = set(pos_feed), set(neg_feed), []
        for r, id in zip(report, student_id):
            score = sum(3 if w in pos else -1 if w in neg else 0 for w in r.split(" "))
            score_id.append((-score, id))
        return [id for _, id in sorted(score_id)[0 : k]]
