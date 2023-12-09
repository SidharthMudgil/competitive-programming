// USER: SIDHARTH MUDGIL
// DATE: Saturday 09, Dec 2023
// PROBLEM: Maximize the equal numbers in the Array

fun maximizeEqualNumbers(arr: IntArray, k: Int): Int {
    val map = mutableMapOf<Int, Int>()
    var res = 0
    
    arr.forEach {
        for (x in -1 * k .. k) {
         	map[it + x] = map.getOrDefault(it + x, 0) + 1
        	res = maxOf(res, map.getOrDefault(it + x, 0))   
        }
    }
    
    return res
}

// optimized using prefix
Int maximizeEqualNumbers(long[] arr, int k) {
    long[] map = new long[200005];
    i = 1;
    while (i <= n) {
        long l = a[(int)i] - k;
        long r = a[(int)i] + k;
        map[(int)l] = map[(int)l] + 1;
        map[(int)(r + 1)] = map[(int)(r + 1)] - 1;
        i = i + 1;
    }
    
    long res = 1;
    i = 1;
    while (i <= 200000) {
        map[(int)i] = map[(int)(i - 1)] + map[(int)i];
        answer = Math.max(map[(int)i], answer);
        i = i + 1;
    }
    
    return res;
}
