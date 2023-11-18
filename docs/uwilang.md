# uwilang

Like it has been said before, uwi is a easy to learn programming language due to its easy syntax. When reading this file you will learn how the language works and how to start developing some programs with it.

## Basic syntax

- Every statement must end with a semicolon `;`.
- In uwi, comments are denoted by `//`. Anything following a `//` on a line is considered a comment and is ignored by the compiler.
``` uwi
// This is a comment
printline("Hello world!"); // This is also a comment
```

## Variables

Variables in uwi are used to store data. Variable names are case-sensitive and must adhere to the following rules:

- Variable names must be declared by its type at the beginning followed by the variable name.
- The variable name must start with a dollar sign `$` and contain letters and numbers only.
- To assign a value to a variable, use the `=` symbol.

``` uwi
str $string1 = "This is a string";
int $integer1 = 3;
float $float1 = 3.4;
char $character1 = 'd';
bool $boolean = true;
```

*Note 1: - New types will be added in future releases.*

*Note 2: When a variable has been declared but hasn't been initialized value it is `null`*

``` uwi
str $nullValue1;
printline("$nullValue1"); // null

// you can also give a variable a null value not caring about the type

str $nullValue2 = null;
printline("$nullValue2"); // null
```

## Output/Input

### Output

In this programming language, the output is handled by the `printline()` function. It works as shown:

``` uwi
printline("Hello world!"); // Hello world!

str $name = "Alice";
int $age = 23;

printline("I'm $name and I am $age yeas old!"); // I'm Alice and I am 23 years old!
```

### Input

To handle input you need and declard variable (int, str, float or char) and then call the `tinput()` function:

``` uwi
str $myString;
tinput($myString, "Enter some text: ");

int $myInteger;
tinput($myInteger, "Enter some integer: ");
```

## Loops

The uwi language provides two types of loops:

- *loop* loops
- *for* loops

### Loop

This type of loop uses the `loop` keyword:

``` uwi
loop {
    // stuff to do

	if (<condition>) {
		break;
	}
}
```

### For loop

This other type of loops uses the `for` keyword.

- It can be used with the `in` or the `times` keyword:

``` uwi
str $string = "Hello";

for (int $i = 1) in ($string.length) {
    printline("$i");
}

// Output:
// H
// e
// l
// l
// o
```

``` uwi
int $a = 10;

for times(3) {
    $a += $a;
}

printline("$a") // 80
```

- When using the `break` keyword the loop will end.
- When using the `continue` keyword the loop will ignore the rest of the code and go back to the top of the loop

## Conditionals and operators

- Conditionals in uwi are handled by the `if`, `elif` and `else` keywords
- Inside the condition you can use `||` or `or`, `&&` or `and`, `!` or `not`

### Operators

- Greater than: `>`
- Greater or equal than: `>=` 
- Smaller than: `<`
- Smaller or equal than: `<=`
- Equal: `==`
- Not equal: `!=`

``` uwi
int $a = 2;
int $b = 13;

if ($a == 2 && $b <= 10) {
    printline("a is 2 and b is smaller or equal than 10");
} elif ($a != 2) {
    printline("a is not 2");
} elif ($b >= 13) {
    printline("b is bigger or equal than 13");
} else {
    printline("Something else");
}
```

## Functions

To declare a function you jut use the `funct` keyword in the following way:

``` uwi
funct myFunction(int arg1, int arg2, str arg3) {
    // code here

	return <>;
}
```

# Examples

All the examples for this programming language are in the `examples/` directory.
