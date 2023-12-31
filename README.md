# <div align="center"> Jotter CLI </div>
```Simple command line utility for keeping track of notes```

## To build it run the following commands from the *project root folder* like so:
### Create the conan package:
```console
conan create .
```
### Deploy the binary to any folder, optionally in your PATH, for example:
```console
conan install --deployer-folder /Users/<username>/.bin --deployer-package jotter/<version> --requires jotter/<version>
```

## Usage:

```
Command line utility for managing notes
Usage:
  jotter [OPTION...]

  -n, --note arg   Note to write
  -t, --timestamp  Display timestamp for each note
  -g, --get        Get all notes
  -h, --help       Print usage
```

### For example:

```console
jotter --note "This is a note"
```
### or
```console
jotter -n "This is a note"
``` 
