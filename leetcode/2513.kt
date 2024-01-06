// USER: SIDHARTH MUDGIL
// DATE: Saturday 06, Jan 2024
// PROBLEM: 2513. Minimize the Maximum of Two Arrays

// Binary Search
class Solution {
    fun gcd(n1: Long, n2: Long): Long {
        if (n2 == 0L) return n1
        return gcd(n2, n1 % n2)
    }   

    fun lcm(n1: Long, n2: Long): Long {
        return (n1 * n2) / gcd(n1, n2)
    }

    fun minimizeSet(divisor1: Int, divisor2: Int, uniqueCnt1: Int, uniqueCnt2: Int): Int {
        var low = 0L
        var high = Int.MAX_VALUE.toLong()
        var res = high

        while (low < high) {
            var mid = (low + high) / 2L

            var x = mid - mid / divisor1 // total numbers not divisible by divisor1
            var y = mid - mid / divisor2 // total numbers not divisible by divisor1
            var z = mid - (mid / lcm(divisor1.toLong(), divisor2.toLong())).toInt() // total common numbers

            if (x >= uniqueCnt1 &&
                y >= uniqueCnt2 &&
                z >= uniqueCnt1 + uniqueCnt2
            ) {
                res = minOf(res, mid)
                high = mid
            } else {
                low = mid + 1
            }
        }
        
        return res.toInt()
    }
}

// O(N)
class Solution {
    fun minimizeSet(divisor1: Int, divisor2: Int, uniqueCnt1: Int, uniqueCnt2: Int): Int {
        var res = 1
        var num = 1
        var ar1 = 0
        var ar2 = 0
        
        while (true) {
            if (ar1 == uniqueCnt1 && ar2 == uniqueCnt2) {
                break
            }

            when {
                num % divisor1 != 0 && ar1 < uniqueCnt1 -> ar1++
                num % divisor2 != 0 && ar2 < uniqueCnt2 -> ar2++
            }

            res = maxOf(res, num)
            num++
        }

        return res
    }
}