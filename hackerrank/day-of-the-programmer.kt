// USER: SIDHARTH MUDGIL
// DATE: Wednesday 18, Oct 2023
// TASK: Day of the Programmer

fun dayOfProgrammer(year: Int): String {
    var date = when {
        year < 1918 && year % 4 == 0 -> 12
        year == 1918 -> 26
        year > 1918 && year % 4 == 0 && year % 100 != 0 -> 12
        year > 1918 && year % 400 == 0 -> 12
        else -> 13
    }
    return "$date.09.$year"
}