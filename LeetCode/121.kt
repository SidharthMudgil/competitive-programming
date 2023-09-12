// USER: SIDHARTH MUDGIL
// DATE: Tuesday 12, Sep 2023
// TASK: 121. Best Time to Buy and Sell Stock

class Solution {
    fun maxProfit(prices: IntArray): Int {
       var max = 0
       var min = prices[0]

       for (i in 1 ..< prices.size) {
           max = maxOf(max, prices[i] - min)
           min = minOf(min, prices[i])
       }

       return max
    }
}