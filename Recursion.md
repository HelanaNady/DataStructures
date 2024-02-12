# Recursion
![Myvtk0G](https://github.com/HelanaNady/DataStructure/assets/137416623/fbca26fb-09fc-43a6-a9ae-c8744a4c7029)

## Formal definitions 
- *Recursive call* : A method call in which the method being called is the same as the one making the call.  <br />
- *Direct recursion* : Recursion in which a method directly calls itself.  <br />
- *Indirect recursion* : Recursion in which a chain of two or more method calls returns to the method that originated the chain.  <br />
- *Tail recursion* : The case in which a function contains only a single recursive call and it is the last statement to be executed in the function.  <br />

## Why and why not?
![Screenshot 2024-02-06 025228](https://github.com/HelanaNady/DataStructure/assets/137416623/2a2c6245-499a-4ddd-b55f-820931ef81a8)

## general format
```Cpp

if (SomeKnownCondition)       //base case
   SolutionStatement;
else
   RecursiveFunctionCall;    //general case

```
*Note: If there're multiple recursion calls there might be multiple base casees*

------------------
## Tower of Hanoi problem
**Solutin pattern using recursion:** <br /> 
-- Shift ‘N-1’ disks from ‘A’ to ‘B’, using C. <br /> 
-- Shift last disk from ‘A’ to ‘C’. <br /> 
-- Shift ‘N-1’ disks from ‘B’ to ‘C’, using A. <br /> 

**Code implementation:** <br /> 
```Cpp
// C++ recursive function to 
// solve tower of hanoi puzzle 
#include <bits/stdc++.h> 
using namespace std; 

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
	if (n == 0) { 
		return; 
	} 
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
	cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl; 
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
} 

// Driver code 
int main() 
{ 
	int N = 3; 

	// A, B and C are names of rods
   towerOfHanoi(N, 'A', 'C', 'B'); 
	return 0; 
} 

// This is code is contributed by rathbhupendra 

```
>Time complexity:
>O(2^N), There are two possibilities for every disk. Therefore, 2 * 2 * 2 * . . . * 2(N times) is 2N


-----------------------------
## Useful videos 
[Recursion in Programming - Full Course](https://youtu.be/IJDJ0kBx2LM?si=NEXHFnrRiT8Sf8KG) <br />
[Recursion Abdul Bari](https://www.youtube.com/playlist?list=PL0x1zsLFiXsy62_l3Oum0nzyGM5VPkNyK) <br />
[Dr Mostafa Saad -competitive programming pov](https://www.youtube.com/watch?v=hyk46UmJPS4&list=PLPt2dINI2MIZPFq6HyUB1Uhxdh1UDnZMS&index=24) <br />
[Tower of Hanoi problem](https://youtu.be/q6RicK1FCUs?si=nYdiK7xfuIQxfj-G) <br /> 

## Useful articles
[GeeksForGeeks Tower of Hanoi](https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/) <br />

## For practice 
**codeforces** <br /> 
[Assiout sheet - Recursion](https://codeforces.com/group/MWSDmqGsZm/contest/223339) <br /> 
**LeetCode** <br /> 
[45 recursion problems](https://leetcode.com/tag/recursion/) <br />
