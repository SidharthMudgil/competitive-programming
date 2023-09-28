// USER: SIDHARTH MUDGIL
// DATE: Thursday 28, Sep 2023
// TASK: Apple and Orange

fun countApplesAndOranges(s: Int, t: Int, a: Int, b: Int, apples: Array<Int>, oranges: Array<Int>): Unit {
    var nApple = 0
    var nOrange = 0
    
    apples.forEach {
        if (a + it in s .. t) {
            nApple++
        }
    }
    
    oranges.forEach {
        if (b + it in s .. t) {
            nOrange++
        }
    }
    
    print("$nApple\n$nOrange")
}
