# Problem 1: Multiples of 3 and 5
## Problem Description:
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.
 
## Breaking it down:
1. Get a list of all numbers between 1 and 999 inclusive
2. Create a new list from the first returning only those divisable by 3 or 5 (possibly more than one step required)
3. Sum the resultant list
 
## Ruby-specific
1. Using a splat ```(1..999)``` we can easily create an array with all numbers from 1 to 999 inclusive.
2. Many methods take code blocks as parameters. 
3. Multi-line code blocks are enclosed  ```do``` and ```end```. Single-line code blocks use ```{``` and ```}```. 
4. Variables within code blocks are wrapped in pipes and can be comma-delimited e.g. ```|name, school|```
5. The Enumerable module uses 'mix-ins' which the Array class sort-of inherits.
6. One mix-in, the Enumerable#find_all method takes an array and a code block and returns a filtered array of only the elements to which the code block returns true e.g. ```[1,2,3].findall { |a| a.even? }``` returns ```=>[2]```
7. Another method ```inject``` takes an optional starting value e.g. ```(0)``` and a code block and folds the array e.g ```[1,2,3].inject(0) { |totalToDate, currentIndex| totalToDate + currentIndex }``` is the idiomatic way to sum an array in Ruby *which seems pretty unnecessarily complex for what otherwise seems like a very programmer-friendly language*
8. Method chaining exists using ```.```. Hooray.
9. The ruby print method is called ```puts```. A minor nuisance.
 
## C++-specific
1. I kind of lucked out and this solution was pretty easy having developed the algorithm previously. Conversely I didn't learn much on this exercise.
2. There is an C++ interpreter on tutorialspoint.com to save compilation (although once I download gcc I'd like to get more comfortable with it).
3. Arrays in C are immutable (the length cannot change). As such I realised an even simpler solution, instead of summing the contents of an array, I declared a variable of value 0 and added to it each iteration where the divisible by 3 or 5 condition returned true.
4. C syntax is refreshingly similar to javascript. This is nice.

## Bash-specific
Oh I _really_ did not enjoy this. I love the idea of bash scripting, running input and piping it through other programs, but the syntax was frustratingly finicky and confusing.
1. i = 1 is not equal to i=1. Remember this.
 
# Problem 2
## Problem Description:
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 
## Breaking it down:
1. Define a function to return a fibonacci number
2. Populate an array with even fibonacci numbers. Stop populating when the fibonacci number exceeds 4 million.
3. Sum that array.
 
## Ruby Specific:
1. The ```puts``` method has an alias ```p```. This is good because one can pretend it means ```print```. Also less keystrokes.
2. Comparative variable assignment which also exists in python (but not javascript) is awesome and means you can do this
```   a, b = 0, 1
    a, b = b, a + b```
instead of:
```   a = 0
    b = 1
    c = b
    a = c
    b = a + c```
    
3. The ```until``` statement runs a anteceding code statement until it returns true
4. The ```until``` modifier runs a preceding code statement until it returns false
5. The ```until``` statement is functionally equivalent to the ```while``` modified and the ```until``` modifier is functionally equivalent to the ```while``` statement.
6. Points 3->5 enable you to write code logically, whatever way your brain is thinking at the time. This can be seen in my posted solution where I used the until statement in the method definition and the until modifier later on. Surely projects involving one or more people would set usage standards. ```if``` has a modifier and it's counterpart is ```unless```.
7. Ruby has a for a in expression syntax much like python's for loops. I didn't get to use this but I would like to remember it for the next Ruby solution. It is functionally equivalent to Array.each { |a| a.expression }

# Problem 6
_to come..._

# Problems 18 and 67
## Problem description:
See https://projecteuler.net/problem=18 and https://projecteuler.net/problem=67.

## Breaking it down:
Since 18 and 67 are the same problem with different inputs I decided it was worth working on a solution that would solve for both inputs. The algorithm for parsing each triangle I chose is one I've seen elsewhere previously that works from the bottom up, and folds one row into the next, taking the maximum combination of the two proximate cells in the first row and their shared cell in the second and returning the sum.

I've simply extended the base algorithm to read in .txt files and parse them into 2D matrices, ready to fold.

## C++ Specific
Oh wow. I struggled and learned a lot in solving this one. 
1. Arrays in C/++ are not extensible. 
2. Vectors are. Vectors are part of the Standard Template Library (STL). 
3. Many items in the STL have iterator counterparts. I didn't use them because I wanted to stop one iteration short each time. 
4. Javascript-like for (statement; condition; execution) syntax worked fine. 
5. Breaking code up into smaller and smaller functions made testing much simpler.
6. You get segmentation faults at runtime when trying to access memory that hasn't been allocated. I got this a lot. I originally thought it was because I was low on ram and the 1000 rows in 67.txt were a lot more than the 15 in 18.txt but eventually worked out it was because I was passing a reference to a file that didn't exist as a parameter. Duh!
7. Neither C or C++ have good, built-in string tokenisation (think ```.split()``` in python). The simplest to understand implementation I found was using getline(input_string, output_vector, optional_delimiter).
8. Vectors require a parameter type described as so: ```vector<int> myVector;```. A two-dimensional vector of integers is described as vector<vector<int> >```. Note the seperating space between greater-thans (this is required, else gcc throws a fit).
9. Command line arguments are realised using syntax ```int main(int argc, char* argv[]) {...}``` where argc is a count of arguments (including the program name running and argv is a space-delimited array).
10. Functions must be declared before they are called. Easiest way to do this is to define all functions at the top of the document and declare them later.