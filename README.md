# Jotter CLI
```Simple command line utility for keeping track of notes```

## To build it run the scripts from the project root folder like so:
### First we want to fetch all submodules:
```console
./scripts/get-all-submodules.sh
```
### Then we want to configure CMake:
```console
./scripts/configure-cmake.sh
```
### Finally we want to build and install the program in the local bin folder of the current user:
```console
./scripts/build-and-install.sh
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