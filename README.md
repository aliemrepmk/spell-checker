# Spell Checker with C++

Dictionary contains 370105 English words.

## How to compile?

### Requirements

- CMake (version >= 3.20)
- Suitable C++ compiler.
- Any build tool CMake supports. (Make or ninja prefered)

```sh
cd spell-checker
cmake -S . -B build
cd build
make
```

Build binary files locates in `bin` folder in root folder.

```sh
cd ..
cd bin
./spell-checker
```

## To-do

- [x] Use smart pointers instead of raw pointers.
- [x] Implement suggestion algorithm.
- [x] Compare suggestions by distance with Levenshtein.
