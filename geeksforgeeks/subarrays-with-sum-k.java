// USER: SIDHARTH MUDGIL
// DATE: Friday 27, Oct 2023
// PROBLEM: Subarrays with sum K

class Solution
{
    static int findSubArraySum(int Arr[], int N, int k)
    {
        Map<Integer, Integer> m = new HashMap<>();
        m.put(0, 1);
        int sum = 0;
        int res = 0;
        
        for (int i = 0; i < N; i++) {
            sum += Arr[i];
            
            if (m.get(sum - k) != null)
                res += m.get(sum - k);
                
            m.put(sum, m.getOrDefault(sum, 0) + 1);
        }
        
        return res;
    }
}