# Linked List Implementations

This folder contains **C++ programs implementing different types of linked lists**, including singly linked list, doubly linked list, and circular singly linked list. Each program demonstrates core linked list operations like insertion, deletion, searching, and displaying elements.

---

## Programs

| File | Type | Description |
|------|------|-------------|
| `singly_linked_list.cpp` | Singly Linked List | Implements a singly linked list with the following operations: <br> - Insert at front <br> - Insert at back <br> - Sorted insert <br> - Search for a value <br> - Remove a value <br> - Display the list |
| `doubly_linked_list.cpp` | Doubly Linked List | Implements a doubly linked list with: <br> - Insert at end <br> - Display forward and backward <br> - Search for a value <br> - Remove a value |
| `circular_linked_list.cpp` | Circular Singly Linked List | Implements a circular singly linked list with: <br> - Insert at end <br> - Display the list <br> - Search for a value <br> - Delete a value |

---

## Features

- Dynamic memory allocation using `new` and proper memory cleanup with `delete`.  
- Search functions print the **position(s)** of a value in the list.  
- Display functions handle **empty lists** gracefully.  
- Supports deletion of **head, tail, and middle nodes**.  
- Circular linked list ensures the **last node points back to the head**, allowing continuous traversal.  

---

## Notes

Language: C++

- All programs are menu-driven, allowing interactive testing of linked list operations.

- Designed for learning and practicing core linked list operations.

- Can be expanded to include more advanced operations like reversing a list, detecting cycles, etc.