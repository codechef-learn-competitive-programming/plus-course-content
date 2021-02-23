https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003381cb <br> <br>
Find the largest substring of even length, s.t. its 1st half is eaxctly equal to its 2nd half <br> <br>

Given 2 sorted arrays A and B of size N and an integer K. <br>
Assume you build C = [A1 + B1, A1 + B2,...A1 + Bn, A2 + B1, .... A2 + Bn, ... An + B1, An + B2, ....An + Bn] of size N*N. Find the Kth largest element in C. <br> <br>

To Do: <br>

Given a list of Tasks. For each task we are given: <br>
1. Arrival Time
2. Execution Time
3. task_id <br> <br>

Priority Order: <br>
1. Shorter Execution time first
2. if exec_time same, then the one with smaller arrival_time first
3. If both same, the one with smaller task_id first. <br> <br>

Print the order in which tasks will be executed by the processor. <br>
