// USER: SIDHARTH MUDGIL
// DATE: Tuesday 24, Oct 2023
// PROBLEM: Find frequency of each number in the array

fun findFrequency(arr: IntArray) {
    arr.groupBy{it}.mapValues{it.value.count()}.forEach(::println)
}