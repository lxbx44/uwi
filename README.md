# uwi Programming Language

- *version: alpha 1.1*

## Introduction

uwi is a simple, lightweight, and easy-to-learn programming language designed for basic programming as it has a straightforward sintax.

## Features

- Simple sintax
- Lightweight
- Easy to learn
- Easy to compile
- Fast

## Getting Started

### Instalation

Installing the uwi compiler (uwic) is an easy task:

#### Prebuild packages

- Not aviable yet

#### Manual installation (recomended)

Before installing the compiler there are some dependencies that should be installed:

```
git
make
gcc
```

Once the dependencies are installed, you can already clone the repo and comile the compiler

```
git clone https://github.com/lxbx44/uwi.git
```

```
cd uwi
```

```
make install
```

Running the `make install` command will automatically add **uwic** to your path.


**Testing**

If your porpuse is to test the compiler, you can simply run `make`, this will create a binary on the `build/` directory.


### Usage

To compile a uwi file, you just need to run the following command:

`uwic <uwi file>`

The uwi file must have the `.uwi` extension.

If you prefear displying some information about the compiler, you can run the `uwic -h` command

### Uninstalling uwic

You can remove the uwi compiler in two different ways:

**Manually**

- remove the compiler from path: `sudo rm -f /usr/bin/uwic`

**From Makefile (recomended)**

- Simply run the `make uninstall`


## Language Guide

### Basic sintax

Every statement ends with a semicolon `;`.

**return**

Every program must have a return value, in other words every program must end the following way:

```
// prev code

return <int between 0-255>;
```

For example, returning `0` will mean succes, returning `1` will mean failure. (other return values will be added soon)

**comments**

In uwi, comments are denoted by `//`. Anything following a `//` on a line is considered a comment and is ignored by the interpreter.

Example:

```
// This is a comment
printline("Hello world!"); // This is also a comment

return 0;
```

### Variables

Variables in uwi are used to store data. Variable names are case-sensitive and must adhere to the following rules:

- Variable names must be declared by its type at the beggining followed by the variable name
- The variable name must start with a dollar sign `$` and letters and numbers
- To assign a value to a variable, use the `=` symbol.


```
str $string1 = "This is a string";
int $integer1 = 3;
float $float1 = 3.4;
char $character1 = 'd';
bool $boolean = true;
```

- *New types will be added in future releases.*

When has no value it is `null`

```
str $nullValue1;
printline("$nullValue1"); // null

// you can also give a variable a null value not caring about the type

str $nullValue2 = null;
printline("$nullValue2"); // null
```

### Output/Input

**Output**

In this programming language, the output is handled by the `printline()` function. It works as folloed:

```
printline("Hello world!"); // Hello world!

str $name = "Alice";
int $age = 23;

printline("I'm $name and I am $age yeas old!"); // I'm Alice and I am 23 years old!
```

**input**

To handle input you need and declard variable (int, str, float or char) and then call the `tinput()` function:

```
str $myString;
tinput($myString, "Enter some text: ");

int $myInteger;
tinput($myInteger, "Enter some integer: ");
```

### Loops

The uwi language provides two types of loops:

- *loop* loops
- *for* loops

**loop**

This type of loop uses the `loop` keyword:

```
loop {
    // stuff to do
}
```

**for**

This other type of loops uses the `for keyword`.

- It can be used with the `in` or the `times` keyword:

```
str $string = "Hello";

for (int $i = 1) in $string.length {
    printline("$i");
}

// Output:
// H
// e
// l
// l
// o
```

```
int $a = 10;

for times($a, 3) {
    $a += $a;
}

printline("$a") // 80
```

- When using the `break` keyword the loop will end.
- When using the `continue` keyword the loop will ignore the rest of the code and go back to the top of the loop

### Conditionals and operators

- Conditionals in uwi are handled by the `if`, `elif` and `else` keywords
- Inside the condition you can use `||` or `or`, `&&` or `and`, `!` or `not`

#### Operators

- Greater than: `>`
- Greater or equal than: `>=` 
- Smaller than: `<`
- Smaller or eual than: `<=`
- Equal: `==`
- Not equal: `!=`

```
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

### Functions

To declare a function you jut use the `funct` keyword in the following way:

```
funct myFunction(int arg1, int arg2, str arg3) {
    // code here
}
```


## Examples

[Include code examples or links to example programs]


## Contributing

[Explain how others can contribute to the development of uwi]

## License

[Specify the license for uwi, e.g., MIT, GPL, etc.]

## Contact

[Provide contact information for the project maintainers or developers]

## Acknowledgments

[Mention any libraries, tools, or resources that you used or were inspired by while developing uwi]


