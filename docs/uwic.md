# The uwi compiler

Uwic is the official compiler for uwilang. Its funcionalitat is to compile an uwi file into machine code to be executed by the machine.
### Available architectures

Uwic compiler currently supports the following architectures:

- x86-64: Commonly used in modern 64-bit PCs running GNU/Linux.

*Note: Ensure that your target architecture is supported before attempting to compile uwi files.*

## Installation

There are different methods to install the uwic compiler:

### Prebuild packages

- Not available yet.

### Manual installation (recommended)

Before installing the compiler there are some dependencies that should be installed:

``` shell
git
make
gcc
```

Once the dependencies are installed, you can already clone the repo and comile the compiler

`git clone https://github.com/lxbx44/uwi.git`

`cd uwi`

`make install`

*Note: Running the `make install` command will automatically add **uwic** to your path.*

**Testing**

If your purpose is to test the compiler, you can simply run `make`, this will create a binary on the build/ directory.

### Download last release

If you don't want to go through any installation process you can simply download the last uwic version from the releases tab:

[Releases](https://github.com/lxbx44/uwi/releases)

## Usage

To compile a uwi file, you just need to run the following command:

`uwic <uwi file>`

The uwi file must have the .uwi extension.

If you prefer to displaying some information about the compiler, you can run the `uwic -h` command.

## Uninstalling uwic

You can remove the uwic compiler in two different ways:

**Manually**

- remove the compiler from path: `sudo rm -f /usr/local/bin/uwic`

**From Makefile (recommended)**

- Simply run `make uninstall` on the uwi gir repository folder.

