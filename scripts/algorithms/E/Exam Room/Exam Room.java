// Runtime: 27 ms (Top 87.99%) | Memory: 52.8 MB (Top 24.67%)
class ExamRoom {

    private final int max;
    private final TreeSet<Interval> available;
    private final TreeSet<Integer> taken;

    public ExamRoom(int n) {
        this.max = n - 1;
        this.available = new TreeSet<>((a, b) -> {
            var distA = getMinDistance(a);
            var distB = getMinDistance(b);
            return distA == distB ? a.s - b.s : distB - distA;
        });
        this.available.add(new Interval(0, max));
        this.taken = new TreeSet<>();
    }

    public int seat() {
        var inter = available.pollFirst();
        var idx = getInsertPosition(inter);
        taken.add(idx);
        if ((idx - 1) - inter.s >= 0)
            available.add(new Interval(inter.s, idx - 1));
        if (inter.e - (idx + 1) >= 0)
            available.add(new Interval(idx + 1, inter.e));
        return idx;
    }

    public void leave(int p) {
        taken.remove(p);
        var lo = taken.lower(p);
        if (lo == null)
            lo = -1;
        var hi = taken.higher(p);
        if (hi == null)
            hi = max + 1;
        available.remove(new Interval(lo + 1, p - 1));
        available.remove(new Interval(p + 1, hi - 1));
        available.add(new Interval(lo + 1, hi - 1));
    }

    private int getInsertPosition(Interval inter) {
        if (inter.s == 0)
            return 0;
        else if (inter.e == max)
            return max;
        else
            return inter.s + (inter.e - inter.s) / 2;
    }

    private int getMinDistance(Interval in) {
        return in.s == 0 || in.e == max ? in.e - in.s : (in.e - in.s) / 2;
    }

    private final class Interval {
        private final int s;
        private final int e;

        Interval(int s, int e) {
            this.s = s;
            this.e = e;
        }

        @Override
        public String toString() {
            return "[" + s + "," + e + "]";
        }
    }
}