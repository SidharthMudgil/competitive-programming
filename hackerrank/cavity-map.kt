// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Oct 2023
// PROBLEM: Cavity Map

fun cavityMap(grid: Array<String>): Array<String> {
    val n = grid.size

    for (i in 1 until n - 1) {
        for (j in 1 until n - 1) {
            val currentChar = grid[i][j]
            val top = grid[i - 1][j]
            val bottom = grid[i + 1][j]
            val left = grid[i][j - 1]
            val right = grid[i][j + 1]

            if (currentChar > top && currentChar > bottom && currentChar > left && currentChar > right &&
                top != 'X' && bottom != 'X' && left != 'X' && right != 'X'
            ) {
                val rowCharArray = grid[i].toCharArray()
                rowCharArray[j] = 'X'
                grid[i] = String(rowCharArray)
            }
        }
    }

    return grid
}