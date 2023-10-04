# UWI the programming language

## Things we can do with uwi

- Return a 8bit integer as an exit code
    
    `retuwirn <8bit value>;`

    Example 1:

    `retuwirn 2;`
  
  - output &rarr; nothing
  
  - `echo $?` &rarr; 2
 
    Example 2:

    `retuwirn 300;`
      
  - output &rarr; error


## How to compile **uwi**

`cmake -S . -B build && cmake --build build`

`build/uwic <filename.uwi to compile>`

The binary of the uwi file will be in your current directory
