// USER: SIDHARTH MUDGIL
// DATE: Thursday 26, Oct 2023
// PROBLEM: Find the frequency of a number in an array

class Solution{
    public int findFrequency(int[] arr, int x) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int num : arr) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        return map.getOrDefault(x, 0);
    }
}
