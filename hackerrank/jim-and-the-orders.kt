// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Oct 2023
// PROBLEM: Jim and the Orders

fun jimOrders(orders: Array<Array<Int>>): Array<Int> {
    return orders.map { it.sum() }.withIndex()
        .sortedBy { it.value }
        .map { it.index + 1 }.toTypedArray()
}