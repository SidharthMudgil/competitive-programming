// USER: SIDHARTH MUDGIL
// DATE: Saturday 28, Oct 2023
// PROBLEM: Find Nth root of M

class Solution
{
    public int NthRoot(int n, int m)
    {
        int l = 1;
        int r = m;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            double x = Math.pow(mid, n);
            if (x == m) return mid;
            if (x < m) l = mid + 1;
            else r = mid - 1;
        }
        
        return -1;
    }
}