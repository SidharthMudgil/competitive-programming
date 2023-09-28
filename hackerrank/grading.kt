// USER: SIDHARTH MUDGIL
// DATE: Thursday 28, Sep 2023
// TASK: Grading

fun gradingStudents(grades: Array<Int>): Array<Int> {
    grades.forEachIndexed { i, v ->
        grades[i] = when {
            v > 37 && v % 5 > 2 -> v + (5 - v % 5)
            else -> v
        }
    }
    
    return grades
}