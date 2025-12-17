This is mostly unnecessary. There are comments in the programs where needed. This is to clarify why I've done things as I have if I think it needs clarification.

int main() vs int main(void).
int main() allows calling of main with arguments but none of them will be used.
int main(void) does not allow calling main with argumets and would result in an error.
I choose to use int main(void) as I see no place in our programs where the difference matters.
main returns an int and not void because not all compilers work with it returning void.
Adding a return statement to the end of main() is unnecessary since C99 as it automatically returns 0 at the end if not specified.
I create and use a large number of functions in my programs, which are unnecessary as they arent being reused. This is mostly just for me to learn the specifics of functions in C, as I'm used to Java and dont want to make any assumtions about how they work in C from that knowledge. Not being able to return arrays is the only difference ive noticed.

1: Write a program to determine if the sum of three user-input integers is even or odd as well as if the number is prime or composite.
A very basic summing and checking code, makes sure the inputs are integers, makes sure to avoid checking if the number is <=1(they cannot be prime).

2: Create a program that converts seconds into hours, minutes, and remaining seconds.
Basic division and modulus application, makes sure the input is an integer.
The input check has a unique behaviour here, where if a mixed(integer followed by anything), it accepts the integer part but nothing beyond it.
Enter time in seconds: -23d3
Invalid input. Please enter a non-negative integer.
Enter time in seconds: 23d3
Time: 0 hours, 0 minutes, 23 seconds

This same method of accepting inputs with this quirk is used in most following codes as well, as I see it as a non-issue(a user could enter 13e, having pressed e by accident but it would still calculate for 13).

3: Create a program to calculate electricity bills based on usage slabs.
Simple if else if else usage, again has input checking.

4: Create a program to simulate a simple login system with 3 attempts to enter the correct password.
Simple string program, usage of the strcmp() function. Accepts inputs with spaces too since its a password.
I've used a while(true) loop, which breaks if the correct password is entered. Counter triggered exit if incorrect password is entered three times.

5: Create a program to remove all duplicates from an array of integers.
Input checking present.
Essentially searches the array beyond the current index for every instance of the value, shifting the entire array back one if found(Preserves the first instance of number, deletes later ones).
However the actual size of the array remains the same, which wastes memory.

6: Implement a program count the number of vowels and consonants in the given string as well as to scramble the characters of a string randomly.
The randomizer is seeded with the current time, this is to eliminate repeating values in the randomness, as if the randomizer is not seeded it will take srand(1) as the seed, giving you the same values each time its run. This is done because 'randomness' is never truly random but always a function run on a starting point(which in our case is the time in seconds since 1st Jan, 1970).
If more randomness is required, the seed can be taken as time, and then the output of the randomizer can be run as a second seed after which the randomizer runs. Multiple iterations of this can be used.
The problem was expanded to include counting numbers afer meeting 1, and to count special characters after meeting 2.
The program does this simply by running through the elements and running a counter for each case.
The randomization ignores special characters, preserving their position in the string, and using rand()%l where l is the length of the string to send a character to the index rand()%l, provided neither the current nor the position being sent to are special characters.

7: Write a program to find the second-largest element in an array using pointers.
Input checking present.
Search the arrray twice, find largest, compare and find second largest in second pass.

8: Develop a program to swap every two adjacent elements in an array using pointers.
Input checking present.
Simple variable swapping, ignores the last index if the number of elements is odd.

9: Take each element of the 4x4 matrix from the user and print it, then add each element from the 4x4 matrix and print the sum, print the sum of both the diagonals.
Input checking present.
Simple summing, understanding how to represent both diagonals using only one loop instead of running through the entire array.

10: Write a Program to Rotate a matrix by 90 degrees in the clockwise direction in C.
Input checking present.
For an array m*n make another array n*m and enter values into it.
Thanks to using functions, I think my program has excess length and complexity, however i chose to do so as it taught me about passing arrays to functions via pointers and double pointers.
malloc function allocates memory for the row of pointers, preventing a situation in which the allocation is interrupted(perhaps due to parallel processing?). It acts as a null check, returning null if memory allocation fails.
Shambhavi mentioned trying to use one display function, but I could not get it to work. Perhaps this is due to a lack of information on my part in derefrencing pointers.

11: Implement Bubble sort or Selection sort on an array based on the input from the user and on the sorted array perform binary search algorithm to find an element.
Input checking present.
Bubble sort and Selection sort are simple the basic sorting.
Binary search has an added bit to ensure if multiple instances os the element are found, all should be made known to the user.
Binary search only works on sorted arrays, having a time complexity of O(log n). This makes it an efficient basic searching algorithm.
It does this by checking to the left and right of the found element. It has to check both right and left due to the way binary seach works, checking only the middle index of the high and low.
It keeps checking further left and right till the elements do not match, making sure all matching indexs are found.

12: Write a program that accepts n products' details and calculates and displays the total value of the inventory (i.e., quantity*price). Find the product with the highest quantity and the product with the highest Price and display their details. 
Input checking present.
Simple array searching and printing.

13: Write a C program to print equilateral triangle or Pyramid star pattern series of n rows.
Input checking present.
The given example is isoceles, not equilateral, and I chose to try to print as close to the example.
My example prints stars n-(i/2)[implicit type conversion] spaces and i stars per row.
For an equilateral triangle, print n-i spaces and a maximum of 2i stars per row.
The choice of multiplication or division 'shifts' the output in opposite ways from the default, which is a right angle triangle(type II nested loop).

14: Write a program to read a file and count the number of characters, words, and lines in a file.
Input checking present.
Basic operation on file.

15: Create a recursive function to find the nth term of the Fibonacci series.
Input checking present.
It works on negatives as well, such that ...f(-1)=1, f(0)=0, f(1)=1...

16: Implement a recursive function to compress a string by replacing consecutive duplicate characters with their count (e.g., aaabbc becomes a3b2c1).
Essentially works on the same logic as the 5th program, deleting all duplicates, except its also counting up how many duplicates exist and adding that each time its done with a set of duplicates.
