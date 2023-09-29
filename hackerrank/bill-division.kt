// USER: SIDHARTH MUDGIL
// DATE: Friday 29, Sep 2023
// TASK: Bill Division

fun bonAppetit(bill: Array<Int>, k: Int, b: Int): Unit {
    val sum = (bill.sum() -  bill[k]) / 2
    
    if (b > sum) {
        print(b - sum)
    } else {
        print("Bon Appetit")
    }
}
