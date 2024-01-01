# <div align="center"> Jotter CLI </div>

```Simple command line utility for keeping track of notes```

## To build it run the following commands from the *project root folder*

### Installing Conan
#### Visit the Conan website for detailed installation instructions: [Conan Installation Guide](https://docs.conan.io/2/installation.html).

### IDE Integration
#### If you are using a popular IDE like CLion, VSCode, or others, the relevant information can be found by following the link: [IDE Integration](https://docs.conan.io/2/integrations.html)

### Creating a Conan Profile (If None Exists)

```console
conan profile detect --force
```

### Create the conan package

```console
conan create . --build=missing
```

### Deploy the binary to any folder, optionally in your PATH

```console
conan install --deployer-folder=/Users/<username>/.bin --deployer-package=jotter/<version> --requires=jotter/<version>
```

## Usage

```
Command line utility for managing notes
Usage:
  jotter [OPTION...]

  -n, --note arg   Note to write
  -t, --timestamp  Display timestamp for each note
  -g, --get        Get all notes
  -h, --help       Print usage
```

### Examples

```console
jotter --note "This is a note"
```

```console
jotter -n "This is a note"
``` 
