# C-notes
These are notes taken alongside CS50 week 1's lecture

## Format Rules

The main body of code should fall inside:
```c
int main(void)
{

}
```
`int main(void)` should be as high up in the code as possible.

Any functions should have their top line copy-pasted above the `int main(void)`. This will be enough to call the function later in the code, even though the function itself is defined below.

### Functions

Functions must also have their return values declared in the top line. A function that adds two numbers and returns an integer might look like:
```c
int add(int a , int b)
{
  return x + y;
}
```

## General Syntax Rules

A semicolon is required at the end of every line of code.

when declaring a variable, its type must be stated .
```c
// In the case of an integer:
int counter = 0;
//Placeholder is %i
// In the case of a string:
string answer = get_string("What's your name? ");
//Placeholder is %s
// In the case of a float:
float z =
//Placeholder is %f (%.xf can be used to decide the number of decimal places)
```

### Logical Operators

```c
//Many seem to be the same as JavaScript, such as:
//OR
||
//AND
&&
```

### Avoid truncation (type casting)
If you divide an int by an int, you will get an int. NO MATTER WHAT.
For this reason, when dividing two numbers, say 1 divided by 3, we will get zero. 
To avoid truncation in this case, both 1 and 3 must be declared as `float`

```c
float z = (float) x / (float) y
```

## Loops

While loops
```c
int i = 3;
while (i > 0)
{
  printf("meow\n");
  i--;
}~~
```
More succinct way (similar to Javascript as well)
```c
for (int i = 0; i < 3; i++)
{
  printf("meow\n")
}
```
