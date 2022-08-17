class Solution {

public boolean isSelfCrossing(int[] x) {
boolean arm = false;
boolean leg = false;
for (int i = 2; i < x.length; ++i) {
int a = f(x, i - 2) - f(x, i - 4);
int b = f(x, i - 2);

if (arm && x[i] >= b)          return true;  // cross [i - 2]
if (leg && x[i] >= a && a > 0) return true;  // cross [i - 4]

if (x[i] < a)       arm = true;
else if (x[i] <= b) leg = true;
}
return false;
}
private int f(int[] x, int index) {
return (index < 0) ? 0 : x[index];
}
}