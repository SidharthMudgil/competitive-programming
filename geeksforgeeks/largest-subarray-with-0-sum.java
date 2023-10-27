// USER: SIDHARTH MUDGIL
// DATE: Friday 27, Oct 2023
// PROBLEM: Largest subarray with 0 sum

class GfG
{
    int maxLen(int arr[], int n)
    {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int res = 0;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (map.get(sum) == null) { 
                map.put(sum, i); 
            } else {
                res = Math.max(res, i - map.get(sum));
            }
        }
        
        return res;
    }
}