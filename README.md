# Interactive Sudoku Game (C) — Major Project (UPES)

This is a fully interactive, modular, terminal-based Sudoku game written in C, designed according to the **UPES Major Project Guidelines**.

---

# 📌 Features

### ✔ Full Terminal Interface  
Clean, structured Sudoku grid display with 3×3 block separators.

### ✔ Real-Time Input Validation  
- Prevents overwriting filled cells  
- Checks Sudoku rules (row, column, 3×3 block)  
- Rejects invalid numbers  
- Handles invalid formatting gracefully  

### ✔ Timer & Automatic Certificate  
When Sudoku is solved:  
- Shows total time taken  
- Displays success certificate  
- Includes Name, SAP ID, College  

### ✔ Modular C Design  
- `main.c` (UI + timer)  
- `sudoku.c` (logic + puzzle)  
- `sudoku.h` (function declarations + extern puzzle)  

### ✔ UPES-Compliant GitHub Structure  
```
/src
/include
/docs
/assets
README.md
Makefile
sample_input.txt
```

### ✔ Auto-Evaluator Friendly  
- GCC-compilable  
- Modular functions  
- No unused variables  
- PDF report included  

---

# 🛠 How to Build

### Linux / macOS / WSL
```
make
./main
```

### Windows (MinGW)
```
gcc src/main.c src/sudoku.c -o main
main.exe
```

---

# 🎮 How to Play
You will be prompted:

```
Enter your move (row col value):
```

- Row = 0–8  
- Col = 0–8  
- Value = 1–9  
- Enter `-1` to exit  

Example:
```
3 4 7
```

---

# 📄 Documentation Included
Inside `docs/ProjectReport.pdf`:
- Abstract  
- Problem Definition  
- System Design  
- Algorithms  
- Flowcharts  
- Implementation  
- Results  
- Conclusion  

---

# 🧪 Sample Input
(Optional; unused since game is interactive)  
Included as `sample_input.txt`.

---

# 👨‍💻 Author
*UPES Major Project — CSEG1032*  
Sudoku Implementation in C

---

# 📦 Ready for GitHub  
Just upload the contents of this ZIP to your repository.

