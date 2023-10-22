// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Oct 2023
// PROBLEM: Insertion Sort 2

fun insertionSort2(n: Int, arr: Array<Int>): Unit {
    for (i in 1 ..< n)
    {
        var j = i
        var temp = arr[i]
        while (j > 0 && temp < arr[j - 1])
            arr[j] = arr[j-- - 1]
        arr[j] = temp
        println(arr.joinToString(" "))
    }
}