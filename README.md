# Software Project Lab 1

## Overview
This project involves the development of a lexical analyzer and an abstract syntax tree (AST) generator for a programming language. The lexical analyzer processes the source code to generate tokens, and the AST generator creates an abstract syntax tree from these tokens.

## Features
- **Lexical Analysis**: The `Lexing.cpp` file reads the source code from `myCode.txt`, generates a string of tokens, and stores them in `Lexing.txt`.
- **AST Generation**: The `AST_nw.exe` executable reads the tokens from `Lexing.txt` and generates an abstract syntax tree (AST).

## Workflow
1. **Lexical Analysis**:
    - Input: `myCode.txt` (source code)
    - Output: `Lexing.txt` (tokens)
    - Process: `Lexing.cpp` reads the source code, generates tokens, and writes them to `Lexing.txt`.

2. **AST Generation**:
    - Input: `Lexing.txt` (tokens)
    - Output: AST (abstract syntax tree)
    - Process: `AST_nw.exe` reads the tokens from `Lexing.txt` and generates an AST.

## Installation
To set up and run the project, follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/fraxhost/SoftwareProjectLab1.git
    cd SoftwareProjectLab1
    ```

2. Compile the lexical analyzer:
    ```bash
    g++ -o Lexing Lexing.cpp
    ```

3. Ensure `AST_nw.exe` is in the project directory.

## Usage
1. Run the lexical analyzer to generate tokens:
    ```bash
    ./Lexing myCode.txt
    ```

2. Run the AST generator to create the abstract syntax tree:
    ```bash
    ./AST_nw.exe Lexing.txt
    ```

## Technologies Used
- **C++**: For the lexical analyzer (`Lexing.cpp`).
- **Executable**: `AST_nw.exe` for generating the AST.
