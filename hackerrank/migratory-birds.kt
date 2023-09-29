// USER: SIDHARTH MUDGIL
// DATE: Friday 29, Sep 2023
// TASK: Migratory Birds

fun migratoryBirds(arr: Array<Int>): Int {
    var res = arr[0]
    var map = mutableMapOf<Int, Int>()
    
    arr.forEach {
        if (map.contains(it)) {
            map[it] = map.getValue(it) + 1
        } else {
            map[it] = 1
        }
        
        if (map.getOrDefault(res, 0) < map.getValue(it)) {
            res = it
        } else if (map.getOrDefault(res, 0) == map.getValue(it) && it < res) {
            res = it
        }
    }
    
    return res
}