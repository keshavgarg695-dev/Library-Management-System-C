# Library-Management-System-C

A console-based Library Management System built in C that supports persistent storage using binary files. The application allows users to manage book records with full CRUD operations, searching, sorting, and export functionality.

This project demonstrates structured programming, file handling, memory management, and modular design in C.

---

## 🚀 Features

- Add new books with automatic unique ID generation
- View all stored books
- Search books by:
  - Unique ID
  - Title prefix
  - Author prefix
- Update existing book details with confirmation
- Delete books with confirmation
- Sort books by selected criteria
- Persistent storage using binary file (`books.dat`)
- Export book records to a readable text file (`books.txt`)
- Input validation and safe memory handling

---

## 🛠️ Technologies Used

- C (Standard Library)
- File Handling (`fread`, `fwrite`, `fopen`)
- MinGW (GCC Compiler on Windows)

---

## 📂 Project Structure

```
Library-Management-System-C/
│
├── lms.c        # Main source file
├── books.dat    # Binary data file (auto-generated)
└── books.txt    # Exported text file
```

---

## ▶️ How to Compile and Run (Windows)

Make sure MinGW is installed and added to PATH.

Open Command Prompt in the project folder and run:

```bash
gcc lms.c
.\a.exe
```
Run the program and add sample books using the Add Book option.
Data will persist automatically after exit.
---

## 💾 Data Persistence

- All book records are stored in a binary file (`books.dat`).
- Data automatically loads when the program starts.
- Any changes are saved back to the file before exit.
- A text export (`books.txt`) can be generated for viewing or sharing.

---

## 📌 Sample Operations

- Add books with title, author, genre
- Search by partial title (prefix match)
- Update or delete existing records
- Sort records for organized viewing
- Export records for external use

---

## 📈 Future Enhancements

- Pagination for large datasets
- User authentication
- Advanced filtering options
- Migration to C++ with OOP architecture
- GUI interface

---

## 👤 Author

**Keshav Garg**

---

## 📄 License

This project is open for learning and educational purposes.
