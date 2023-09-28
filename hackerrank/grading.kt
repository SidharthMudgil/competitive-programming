// USER: SIDHARTH MUDGIL
// DATE: Thursday 28, Sep 2023
// TASK: Grading

fun gradingStudents(grades: Array<Int>): Array<Int> {
    grades.forEachIndexed { i, v ->
        grades[i] = when {
            v < 38  -> v
            (v + 1) % 5 == 0 -> v + 1
            (v + 2) % 5 == 0 -> v + 2
            else -> v
        }
    }
    
    return grades
}