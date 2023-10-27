// USER: SIDHARTH MUDGIL
// DATE: Friday 27, Oct 2023
// PROBLEM: Subarray with given XOR

public class Solution {
    public int solve(ArrayList<Integer> A, int B) {
        int res = 0;
        int x = 0;
        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, 1);
        for (int n: A) {
            x ^= n;
        
            if (m.get(B ^ x) != null) {
                res += m.getOrDefault(B ^ x, 0);
            }
    
            m.put(x, m.getOrDefault(x, 0) + 1);
        }
        
        return res;
    }
}
