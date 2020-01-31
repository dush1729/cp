# Project Euler

![Project Euler progress](http://projecteuler.net/profile/dush1729.png)

**Disclaimer** - These solutions are done in my own free time for fun. Please feel free to use it **only** after you have solved the problem on your own.

My key - `740042_QaRd9BIO46mRgfWrUagkJ5R8Pqt60yDK`

This repo contains my solutions to Project Euler problems.

- [032](032.cpp) - Add speedup checks - len(s3)>=max(len(s1),len(s2)) and last digit of s3 should be equal to multiplication of last digit of s1 and s2 mod 10. These checks reduces runtime from 7.1s to 0.6s.

- [079](079.cpp) - Solved using topological sorting. Fortunately there were no cycles present in input like (123, 321). Maybe we can solve that using LCS?

- [059](059.py) - Try to look for a faster method. Current approach takes 10 seconds.

- [206](206.cpp) - Initially my solution took 7 minutes on my laptop! Observe that last digit is 0, then our answer will also have last digit as 0. This will make last two digit of square zero. So we can remove last two digit and find 9 is the last digit. We can get 9 at last digit only by squaring numbers ending with 3 or 7. So we try to check numbers ending with 30 and 70 only. This whole optimization brings down runtime to 4.3 seconds!

- [074](074.cpp) - Optimize. Currently takes 38 seconds.

- [357](357.cpp) - Optimize.