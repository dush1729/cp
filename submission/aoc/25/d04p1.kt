import kotlin.math.min

val di = arrayListOf(-1,-1,-1, 0, 0,+1,+1,+1)
val dj = arrayListOf(-1, 0,+1,-1,+1,-1, 0,+1)

fun main() {
    val a = arrayListOf<String>()
    repeat(140) {
        val str = readLine()!!
        a.add(str)
    }

    val n = a.size
    val m = a[0].length
    var ans = 0
    for(i in a.indices) {
        for(j in a[i].indices) {
            if(a[i][j] != '@') {
                continue
            }
            var rolls = 0
            for(dir in 0 .. 7) {
                val ni = i + di[dir]
                val nj = j + dj[dir]
                if(min(ni, nj) >= 0 && ni < n && nj < m && a[ni][nj] == '@') {
                    rolls++
                }
            }
            if(rolls < 4) {
                ans++
            }
        }
    }
    print(ans)
}