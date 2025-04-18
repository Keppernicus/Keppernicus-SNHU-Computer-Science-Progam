## Project Summary

This project is a C++ item tracking program developed for a made up grocery store. The goal is to read a list of purchased items from the provided text file, , track how many times each item appears, back up that data to file, then depending on the menu choices below:

- Look up the count of a specific item
- View all items and their count
- Display a text based histogram
- Exit the program

---

## What I Did Well

- I organized code using classes: `DataHandler`, `Menu`, and `Display`
- Implemented input validation with exception handling
-- If the input was invalid, rather than crashing it informed the user of the error and prompted them for input again
- Normalized user input for better usability
-- Specifically as it pertains to capitalization. The input file had title case, so I normalized the user input to title case
- I made sure there was clean and readable structure, each file and function has a clear role

---

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

- Move string formatting helpers (like my `capitalizeFirstLetter`) into a separate utility file
- Improve input capability with multi-word item names
- Make item lookup fully case-insensitive
-- If I were to do it again I believe I would format the data and input into lower case across the board.
- I could improve upon the GUI, adding colors to make it more attractive


---

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

Getting the input file to load was the hardest part—not the code itself, but how Visual Studio handles resource files. I learned that files need to be explicitly added to the project and set to “Copy to Output Directory” in the file’s properties. Stack Overflow and some trial and error got me through it. The various C++ websites have been a great help as well, with well formatted guides on anything I've needed.

---

## What skills from this project will be particularly transferable to other projects or course work?

- Working with `std::map` for counting and lookup
- Validating and sanitizing user input
-- I've applied this across other programs in Python recently as well
- Modular C++ project structure using headers and classes
-- This has greatly improved my understanding of how to build projects, regardless of language
- Exception handling with `try`, `throw`, and `catch`
- File I/O with `ifstream` and `ofstream`

---

## How did you make this program maintainable, readable, and adaptable?

This program is split into three modules:

- `DataHandler` manages all file and map operations
- `Menu` controls user interaction and menu flow
- `Display` formats output for the console

This separation makes the program easier to maintain, extend, or port into a different interface later on.
