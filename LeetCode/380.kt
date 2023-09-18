// USER: SIDHARTH MUDGIL
// DATE: Monday 18, Sep 2023
// TASK: 380. Insert Delete Random O(1)

// Working
class RandomizedSet() {
    val rand = kotlin.random.Random
    val map = mutableMapOf<Int, Int>()
    val li = mutableListOf<Int>()

    fun insert(`val`: Int): Boolean {
        if (map.contains(`val`).not()) {
            map[`val`] = li.size
            li.add(`val`)
            return true
        }
        return  false
    }

    fun remove(`val`: Int): Boolean {
        if (map.contains(`val`)) {
            val idx = map[`val`]!!
            
            val lst = li[li.lastIndex]
            li[idx] = lst
            map[lst] = idx

            li.removeAt(li.lastIndex)
            map.remove(`val`)
            return true
        }
        return false
    }

    fun getRandom(): Int {
        return li[rand.nextInt(li.size)]
    }
}

// Kotlin Set Approach
import kotlin.random.Random

class RandomizedSet() {
    val localSet = mutableSetOf<Int>()

    fun insert(`val`: Int): Boolean {
        return localSet.add(`val`)
    }

    fun remove(`val`: Int): Boolean {
        return localSet.remove(`val`)
        
    }

    fun getRandom(): Int {
        val i = Random.nextInt(0, localSet.size)
        return localSet.elementAt(i)
    }
}

// My Approach
class RandomizedSet() {
    val nums = mutableMapOf<Int,Boolean>()

    fun insert(`val`: Int): Boolean {
        if (nums.getOrDefault(`val`, false) == false) {
            nums[`val`] = true
            return true
        }
        return  false
    }

    fun remove(`val`: Int): Boolean {
        if (nums.getOrDefault(`val`, false) == true) {
            nums[`val`] = false
            return true
        }
        return false
    }

    fun getRandom(): Int {
        val keys = nums.filter{ it.value == true }
        val key = kotlin.random.Random.nextInt(keys.size)
        return nums.keys.toList()[key]
    }
}
