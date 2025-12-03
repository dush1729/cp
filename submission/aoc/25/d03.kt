fun main() {
    var ans = 0
    repeat(200) {
        val a = readLine()!!
        val firstMaxIndex = a.indexOf(a.max())
        if(firstMaxIndex == a.length - 1) {
            val newa = a.take(a.length - 1)
            val secondMaxIndex = newa.indexOf(newa.max())
            ans += (newa[secondMaxIndex].toString() + a[firstMaxIndex]).toInt()
        } else {
            val newa = a.substring(firstMaxIndex + 1)
            val secondMaxIndex = newa.indexOf(newa.max())
            ans += (a[firstMaxIndex].toString() + newa[secondMaxIndex]).toInt()
        }
    }
    print(ans)
}