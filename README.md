# Spell Checker with C++

Dictionary contains 370105 English words.

## Known bugs

- Infinite loop and segmentation fault on clang 14.0.0

## How to compile?

### Requirements

- Suitable C++ compiler (g++ with C++17 support recommended)
  - We used `g++ 11.4.0 on Ubuntu 22.04`. Other compilers like `clang` throws errors such as segmentation fault or infinite loops.
- CMake or Make (recommended)

### Using Make

```sh
cd spell-checker
make
```

### Using CMake

```sh
cd spell-checker
cmake -S . -B build
cd build
make
```

Build binary files locates in `bin` folder in root folder.

```sh
cd bin
./spell-checker
```

## To-do

- [x] Use smart pointers instead of raw pointers.
- [x] Implement suggestion algorithm.
- [x] Compare suggestions by distance with Levenshtein.
- [ ] Adding colors for better understanding.
- [ ] Improve suggestions. ([source](https://stackoverflow.com/a/2294926/12463055))
