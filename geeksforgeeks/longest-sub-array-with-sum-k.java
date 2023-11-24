// USER: SIDHARTH MUDGIL
// DATE: Friday 24, Nov 2023
// PROBLEM: Longest Sub-Array with Sum K

class Solution{
    
    public static int lenOfLongSubarr (int A[], int N, int K) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int sum = 0;
        int res = 0;
        
        for (int i = 0; i < N; i++) {
            sum += A[i];
            res = Math.max(res, i - map.getOrDefault(sum - K, i));
            if (map.get(sum) == null) {
                map.put(sum, i);
            }
        }
        
        return res;
    }   
}