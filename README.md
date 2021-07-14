# the-cheapest-path
|project from 2020|   |the Bellman–Ford Algorithm has been implemented|

We have a "map of roads" (which are unidirectional) and crossroads. Each road has a cost associated with it, which could be a positive number (someone must pay for going through it), zero or negative number (someone can earn money on this road).
The goal of the program is to for each pair (a starting crossroad and a destination) find the lowest cost of a route between them.


Input:<br/>
n: the number of crossroads (non-negative integer),<br/>
m: the number of roads (non-negative integer),<br/>
Next m lines of roads definitions, in the form: v u d, where:<br/>
v and u are the indices of crossroads that are connected with a given road (non-negative integers from range [0, n-1]),<br/>
d is the cost of the road (integer).<br/>
t: the number of tests (non-negative integer),<br/>
Next t lines of tests definitions, in the form: a b, where:<br/>
a is the index of a crossroad that is the starting point of the path to be found (non-negative integer from range [0, n-1]),<br/>
b is the index of a crossroad that is the destination of the path to be found (non-negative integer from range [0, n-1]).<br/>


Output:<br/>
For each test: one line with the cost of the cheapest path for crossroads given in this test,<br/>
or '!' if there are no paths from the starting point to the destination,<br/>
or "-inf" if it is possible to earn an infinite amount of money on a route starting from the starting point to the destination.<br/>
