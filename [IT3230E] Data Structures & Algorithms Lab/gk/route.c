/*
A fleet of KK identical trucks having capacity QQ need to be scheduled to delivery pepsi packages from a central depot 0 to clients 
1,2,…,n1,2,…,n. 
Each client ii requests d[i]d[i] packages. The distance from location ii to location jj is c[i,j]c[i,j], 0≤i,j≤n.0≤i,j≤n.. 
A delivery solution is a set of routes: each truck is associated with a route, starting from depot, visiting some clients and 
returning to the depot for deliverying requested pepsi packages such that:
    - Each client is visited exactly by one route.
    - Total number of packages requested by clients of each truck cannot exceed its capacity
    - Each truck must visit at least one client

Goal
Find a solution having minimal total travel distance
Note that: the orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.

Input
Line 1: n,K,Qn,K,Q (2≤n≤12,1≤K≤5,1≤Q≤502≤n≤12,1≤K≤5,1≤Q≤50)
Line 2: d[1],...,d[n]d[1],...,d[n] (1≤d[i]≤101≤d[i]≤10)
Line i+3i+3: the i-th i-th row of the distance matrix c(i=0,…,n)c(i=0,…,n) (1≤c[i,j]≤30 1≤c[i,j]≤30)
Output
Minimal total travel distance

Example
Input
4 2 15
7 7 11 2
0 12 12 11 14
14 0 11 14 14
14 10 0 11 12
10 14 12 0 13
10 13 14 11 0

Output
70

*/