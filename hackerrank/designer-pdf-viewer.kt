// USER: SIDHARTH MUDGIL
// DATE: Friday 20, Oct 2023
// PROBLEM: Designer PDF Viewer

fun designerPdfViewer(h: Array<Int>, word: String): Int {
    var max = 0
    
    word.forEach {
        val curr = it - 'a'
        
        if (h[curr] > max) {
            max = h[curr]
        }
    }
    
    return max * word.length
}