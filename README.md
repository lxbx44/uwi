# UWI the programming language

## Docs


```
%%

Comments are made by two percentage symbols
at the beggining and one at the end.

Both single and multiple line comments are
done the same way.

%


%%

To declare a variable do the following:
  <type> <name> = <value>;

TYPES:
    - str -> string
    - int -> integers

NAMES:
    - Only alphanumeric values.
    - Cap sensitive.
    - No spaces.
    - IT MUST START WITH `$`

VALUES:
    - String values are between '', "", "' or '".
    - Integers are just integers.

SEMICOLON:
    - Is mandatory

%

str $varName = "Bojour";
int $int1 = 23;


%%

To print some text in the terminal
just call the function `printline();`

If you wanna include variables inside
the `printline();` do so within square
brakets:
    - printline("Hello world");
    - printline("$[varName] monde");

%

printline("Hello world");


%%

To get user input just call the `tinput()`
function.
  tinput(<variable to store input>, <some string>);

%

tinput($varName2, "enter some text ");


%%

Every program MUST end with a exit status
this is given by a `return`:
  return <value from 0 to 255>;

%

return 0;

```



## How to compile **uwic** (uwi compiler)

`cmake -S . -B build && cmake --build build`

## How to compile **uwi** (.uwi file)

`build/uwic <filename.uwi to compile>`

The binary of the uwi file will be in your current directory
