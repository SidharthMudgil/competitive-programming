// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Oct 2023
// PROBLEM: Insertion Sort 1

fun insertionSort1(n: Int, arr: Array<Int>): Unit {
    var curr = arr[n - 1]
    
    for (i in n - 1 downTo 1) {
        if (curr < arr[i - 1]) {
            arr[i] = arr[i - 1]
        } else {
            arr[i] = curr
            curr = arr[i - 1]
        }
        println(arr.joinToString(" "))
    }
}fun insertionSort1(n: Int, arr: Array<Int>): Unit {
    var curr = arr[n - 1]
    
    for (i in n - 1 downTo 0) {
        if (i == 0) {
            arr[0] = curr
        } else if (curr < arr[i - 1]) {
            arr[i] = arr[i - 1]
        } else {
            arr[i] = curr
            println(arr.joinToString(" "))
            return
        }
        println(arr.joinToString(" "))
    }
}