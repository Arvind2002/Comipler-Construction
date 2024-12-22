# Compiler-Construction
The compiler translates a C-like programming language to machine-executable code.

## Steps to Execute 

1. To compile all the files, run the `make` command.
2. To run the compiler on a file 'input.txt' and storing the Parse Tree as an output in a file called 'output.txt' with a buffer size of 50, run `./runCompiler input.txt output.txt 50`

## Features Implemented
- Lexer
  1. Lexical Error Handling
  2. Keyword Handling
  3. Tokenization
- Parser
  1. Automatic First & Follow of the Grammar
  2. Parser Error Handling
- Parse Tree Generation
- Abstract Syntax Tree Generation
- Symbol Table
- Type Checking
- Semantic Analyzer


## File Structure

- Header Files
  
Files with the Def suffix are used to define the data structures for the project.
Other header files contain the declarations of functions.

- Implementation Files
  
The source files implement the functions declared in the header files.
