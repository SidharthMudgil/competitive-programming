// USER: SIDHARTH MUDGIL
// DATE: Wednesday 13, Sep 2023
// TASK: 122. Best Time to Buy and Sell Stock II


// Optimized
class Solution {
    fun maxProfit(prices: IntArray): Int {
        var res = 0
        var min = prices[0]

        for (i in 1 ..< prices.size) { 
            when {
                i == prices.size - 1 -> res += max(0, prices[i] - min)
                prices[i] < min -> min = prices[i]
                i + 1 < prices.size && prices[i] > prices[i + 1] -> {
                    res += prices[i] - min
                    min = prices[i + 1]
                }
            }
        }

        return res
    }
}


// Solution 1
class Solution {
    fun maxProfit(prices: IntArray): Int {
        var res = 0
        var prev = prices[0]

        for (i in 1 ..< prices.size) {
            if (i == prices.size - 1) {
                res += max(0, prices[i] - prev)
            }
            if (prices[i] < prev) {
                prev = prices[i]
            } else {
                if (i + 1 < prices.size && prices[i] > prices[i + 1]) {
                    res += prices[i] - prev
                    prev = prices[i + 1]
                }
            }
        }

        return res
    }
}