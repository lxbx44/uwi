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

```git clone https://github.com/lxbx44/uwi.git```

```cd uwi```

```make install```

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

The main characteristic of uwi is the minimal and simple sintax, 

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


