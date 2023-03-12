class Solution {

    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> result = new ArrayList<>();

        int minDifference = Integer.MAX_VALUE;
        for (int i = 1; i < arr.length; i++) {
            int currentDifference = Math.abs(arr[i] - arr[i - 1]);
            if (minDifference > currentDifference) {
                minDifference = currentDifference;
            }
        }

        for (int i = 1; i < arr.length; i++) {
            if (minDifference == Math.abs(arr[i] - arr[i - 1])) {
                result.add(List.of(arr[i - 1], arr[i]));
            }
        }

        return result;
    }
}