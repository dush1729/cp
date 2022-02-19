/*
Blog
https://codeforces.com/blog/entry/11080

Problems
https://codeforces.com/problemset/problem/61/E
https://cses.fi/problemset/task/1076

Description
pbds is basically set on steroids!
It can perform all operations as efficiently as set.
Plus it can find kth smallest value & rank in logn time for which set takes linear time.

find kth smallest value(0 based indexing)
*s.find_by_order(k)

rank of number i.e. number of items < k
s.order_of_key(k)

BEWARE in case of duplicates, use pair <int, int>
*/

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;