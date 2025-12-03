fun main() {
    var ans = 0L
    repeat(200) {
        val a = readLine()!!
        var s = ""
        for(i in a.indices) {
            while(!s.isEmpty() && s.last() < a[i] && s.length + a.length - i > 12) {
                s = s.dropLast(1)
            }
            s += a[i]
        }
        while(s.length > 12) {
            s = s.dropLast(1)
        }
        ans += s.toLong()
    }
    print(ans)
}