
# Virtual File System (VFS)

Virtual File System is a Linux-like file system implemented in C.

This project simulates the internal working of a file system using:

- Inodes
- SuperBlock
- File Tables
- UFDT (User File Descriptor Table)

---

## Features

- File Creation
- File Listing (ls)
- Inode Management
- SuperBlock Management
- UFDT Management
- Permission Handling
- Manual Commands

---
---

## Data Structures

### BootBlock
Stores booting information.

### SuperBlock
Stores:

- Total Inodes
- Free Inodes

### Inode
Stores:

- File Name
- File Size
- File Type
- Permissions
- Buffer

### FileTable
Stores:

- Read Offset
- Write Offset
- Mode

### UFDT
Stores open file descriptors.

---

## Commands

| Command | Description |
|--------|-------------|
| creat filename permission | Create file |
| ls | List files |
| help | Help |
| man command | Manual |
| clear | Clear terminal |
| exit | Exit VFS |

---


---

## Technologies Used

- C Programming
- Linux System Programming
- Memory Management
- Data Structures
- Linked List

---

## Concepts Covered

- Virtual File System
- Inode Architecture
- File Descriptor Table
- Dynamic Memory Allocation
- Shell Interface

---

## Author

Samarth Deshmukh
