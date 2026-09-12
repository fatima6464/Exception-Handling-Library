# ⚠️ Exception Handling Library — OOP (C++)

A **menu-driven C++ application** demonstrating custom exception handling using **Object-Oriented Programming** and **templates**, with **9+ custom exception types** covering everything from signal handling to file I/O.

Developed as an academic project for **Object Oriented Programming**, BS Computer Science.

---

## 📋 Overview

Most beginner exception-handling demos stop at `try/catch` with built-in exceptions. This project goes further — building a full custom exception hierarchy from scratch using OOP principles, so each error type carries its own context and behavior instead of relying on generic error messages.

## ✨ Exceptions Implemented

| # | Exception Type | Handles |
|---|---|---|
| 1 | User Interruption | SIGINT (Ctrl+C) via signal handling |
| 2 | Overflow / Underflow | Numeric range violations |
| 3 | Division by Zero | Arithmetic errors |
| 4 | Invalid Input | Malformed/unexpected user input |
| 5 | File Existence | Checks file exists before access |
| 6 | File Append | Validates append operations |
| 7 | File Write/Create | Validates write/create operations |
| 8 | Index Out of Bound | Array/container bounds checking |
| 9 | Null Pointer | Null dereference protection |
| 10 | Data Conversion | Hexadecimal & Octal conversion errors |
| 11 | Default Exception | Catch-all fallback |

## 🧠 Concepts Used

- Classes & Objects
- Inheritance (custom exception hierarchy)
- Templates
- Custom Exception Handling
- File Handling
- Signal Handling
- Header Files
- Menu-Driven Program Design

## 📁 Project Structure

```
Exception-Handling-System/
│── ExceptionHandler.h    # Custom exception class hierarchy
│── main.cpp              # Menu-driven driver program
│── README.md
```

## ▶️ How to Run

1. Open the project in **Dev C++**, **Code::Blocks**, or **Visual Studio**
2. Compile `main.cpp`
3. Run the program
4. Choose an exception type from the menu to see it triggered and handled

> ⚠️ **Note:** This project is **Windows-based** — it uses `windows.h`, `Sleep()`, and `system("cls")`, so it won't compile as-is on Linux/macOS without modification.

## 📚 What I Learned

- Designing a custom exception class hierarchy using inheritance
- Using templates to write reusable, type-flexible exception handling
- Integrating OS-level signal handling (SIGINT) into application logic
- Structuring a menu-driven program cleanly across multiple files

## 🔮 Future Improvements

- Cross-platform support (remove `windows.h` dependency)
- Unit tests for each exception type
- Logging exceptions to file for debugging/audit trail

## 🎓 Course

Object Oriented Programming — BS Computer Science

## 👩‍💻 Author

**Fatima Nadeem**

## 📎 Notes

- No external libraries required
- Compiled files (`.exe`) are intentionally excluded from the repository
