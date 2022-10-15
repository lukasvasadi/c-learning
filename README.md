# C

Classroom exercises to practice C programming.

## Compiling instructions

1. **Install GCC toolchain**

For Mac (requires Homebrew):

```zsh
brew install gcc@11
```

For Linux (requires a Debian-based distribution):

```bash
sudo apt update
sudo apt install build-essential
sudo apt-get install manpages-dev
```

For Windows (requires Chocolatey):

```ps1
choco install mingw
```

2. **Create binary executable**

Compile `main.c` to `program` executable (substitute for other source files):

```zsh
gcc main.c -o program
```
