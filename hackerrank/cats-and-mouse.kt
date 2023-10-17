// USER: SIDHARTH MUDGIL
// DATE: Tuesday 17, Oct 2023
// TASK: Cats and Mouse

fun catAndMouse(x: Int, y: Int, z: Int): String {
    val distX = Math.abs(x - z)
    val distY = Math.abs(y - z)
    
    return when {
        distX < distY -> "Cat A"
        distX > distY -> "Cat B"
        else -> "Mouse C"
    }
}