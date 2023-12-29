# <div align="center"> Jotter CLI </div>
```Simple command line utility for keeping track of notes```

## To build it run the following commands from the *project root folder* like so:
### First we want Conan to prepare the generators:
```console
conan install . --build=missing
```
### Then we want to build and install the program in the local bin folder of the current user:
```console
conan build .
```

## Usage:

```
Command line utility for managing notes
Usage:
  jotter [OPTION...]

  -n, --note arg  Note to write
  -h, --help      Print usage
```

### For example:

```console
jotter --note "This is a note"
```
### or
```console
jotter -n "This is a note"
``` 
