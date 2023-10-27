// USER: SIDHARTH MUDGIL
// DATE: Friday 27, Oct 2023
// PROBLEM: Max distance between same elements

class Solution
{
    int maxDistance(int arr[], int n)
    {
        Map<Integer, Integer> map = new HashMap<>();
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            res = Math.max(res, i - map.getOrDefault(arr[i], n));
            
            if (map.get(arr[i]) == null) {
                map.put(arr[i], i);
            }
        }
        
        return res;
    }
}