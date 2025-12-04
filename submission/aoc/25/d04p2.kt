import kotlin.math.min

val di = arrayListOf(-1,-1,-1, 0, 0,+1,+1,+1)
val dj = arrayListOf(-1, 0,+1,-1,+1,-1, 0,+1)

fun main() {
    val a = arrayListOf<CharArray>()
    repeat(140) {
        val str = readLine()!!
        a.add(str.toCharArray())
    }

    val n = a.size
    val m = a[0].size
    val vis = Array(n) { Array(m) {0} }
    for(i in a.indices) {
        for(j in a[i].indices) {
            if(a[i][j] != '@') {
                continue
            }
            for(dir in 0 .. 7) {
                val ni = i + di[dir]
                val nj = j + dj[dir]
                if(min(ni, nj) >= 0 && ni < n && nj < m && a[ni][nj] == '@') {
                    vis[ni][nj]++
                }
            }
        }
    }

    var ans = 0
    val rolls = ArrayDeque<Pair<Int, Int>>()
    val done = Array(n) { Array(m) {0} }
    for(i in a.indices) {
        for (j in a[i].indices) {
            if (a[i][j] == '@' && vis[i][j] < 4) {
                rolls.add(i to j)
                done[i][j] = 1
                ans++
            }
        }
    }

    while(!rolls.isEmpty()) {
        val (i, j) = rolls.removeFirst()

        a[i][j] = '.'
        for(dir in 0 .. 7) {
            val ni = i + di[dir]
            val nj = j + dj[dir]
            if(min(ni, nj) >= 0 && ni < n && nj < m && a[ni][nj] == '@') {
                vis[ni][nj]--
                if(vis[ni][nj] < 4 && done[ni][nj] == 0) {
                    rolls.add(ni to nj)
                    done[ni][nj] = 1
                    ans++
                }
            }
        }
    }
    print(ans)
}