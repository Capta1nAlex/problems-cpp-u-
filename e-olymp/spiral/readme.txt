https://www.eolymp.com/uk/problems/85
The easiest solution would be to fill the matrix and find the element by index, but this way is very time consuming.
In order to make this task slighty more challenging I did it a bit different, by searching the row in which element is, and next to it iterating throw the row till we find element.
Because of that instead of always getting time complexity of O(N^2) now we get O(N) as a worst case scenario.
This solution could be even better, by searching throw the row itself with a formula, but I decided to leave it as it is, due to the fact that all tests are passing even when the solution time complexity is N^2.
