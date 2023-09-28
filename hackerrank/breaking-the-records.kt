// USER: SIDHARTH MUDGIL
// DATE: Thursday 28, Sep 2023
// TASK: Breaking the Records

fun breakingRecords(scores: Array<Int>): Array<Int> {
    var res = Array<Int>(2){ 0 }
    var min = scores[0]
    var max = scores[0]
    
    scores.forEach {
        if (it > max) {
            max = it
            res[0] += 1
        }
        
        if (it < min) {
            min = it
            res[1] += 1
        }
    }
    
    return res
}
