// USER: SIDHARTH MUDGIL
// DATE: Wednesday 20, Sep 2023
// TASK: 58. Length of Last Word

class Solution {
    fun lengthOfLastWord(s: String): Int {
        var len = 0
        for (ch in s.trim().reversed()) {
            if (ch.equals(' ')) {
                return len
            }
            len++
        }
        return len
    }
}