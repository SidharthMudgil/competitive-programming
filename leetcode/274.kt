// USER: SIDHARTH MUDGIL
// DATE: Saturday 16, Sep 2023
// TASK: 274. H-Index

// Sorting
class Solution {
    fun hIndex(citations: IntArray): Int {
        var x = citations.size
        citations.sorted().forEach {
            if (x <= it) {
                return x
            } else {
                x--
            }
        }
        return 0
    }
}

// Second Approach
class Solution {
    fun hIndex(citations: IntArray): Int {
        citations.mapIndexed { i, it -> 
            i + 1 to citations.count{ v -> v >= i + 1 }
        }.reversed().forEach {
            if (it.first <= it.second) {
                return it.first
            }
        }
        return 0
    }
}

// First Approach
class Solution {
    fun hIndex(citations: IntArray): Int {
        return citations.mapIndexed { i, it -> 
            i + 1 to citations.count{ v -> v >= i + 1 }
        }.toMap().filter{ it.key <= it.value }
        .map { it.key }.lastOrNull() ?: 0
    }
}