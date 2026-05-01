# In-Place Selection Sort for Singly Linked List

A rigorous C++ implementation of a Selection Sort algorithm for a singly linked list. This project solves a challenging set of algorithmic constraints by sorting the list entirely through pure pointer manipulation, without relying on data swapping or temporary memory structures.

## 🚀 Overview

Standard linked list sorting tutorials often take the easy route by simply swapping the internal `data` values of the nodes. This implementation takes the strict, structurally correct approach: it physically moves the nodes in memory by meticulously rewiring their `next` pointers. 

### 🛑 Algorithmic Constraints Conquered
This implementation strictly adheres to the following rules:
* **No Data Swapping:** The `data` payload of the nodes is completely untouched during the sort.
* **No Node Creation:** No new nodes or dummy/sentinel nodes are instantiated to aid in the sorting process.
* **No Auxiliary Structures:** The algorithm operates entirely in-place (O(1) auxiliary space). No temporary arrays, vectors, or secondary linked lists are used.

## 🧠 How It Works: The "Lazy Bridge" Technique

The algorithm utilizes a modified Selection Sort approach with a custom traversal technique to safely extract nodes:

1. **Divide and Conquer:** The list is logically divided into a forming sorted tail and a remaining unsorted sequence.
2. **Track the Minimum:** During each pass, it scans the unsorted portion to find the absolute minimum node (`currMin`) while critically tracking the node immediately preceding it (`prevMin`).
3. **Bridge the Gap:** To remove the minimum node without losing the traversal state, the algorithm bridges the pointers over the minimum node (`temp->next = temp->next->next`). This ensures the unsorted chain remains intact for the next pass.
4. **Append and Sever:** The isolated minimum node's ties to the old list are severed to prevent infinite loops, and it is appended to the growing sorted chain.

## 🛠️ Getting Started

### Prerequisites
You need a standard C++ compiler (like GCC) installed on your machine.

### Compilation & Execution
Clone the repository and compile the code using `g++`:
```bash
# Compile the code
g++ main.cpp -o selection_sort

# Run the executable
./selection_sort
