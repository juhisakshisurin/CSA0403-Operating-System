# Operating Systems Lab Experiments in C

## About
This repository contains practical lab experiments completed as part of the Operating Systems course. The programs are implemented in C and demonstrate fundamental operating system concepts, algorithms, process management, synchronization, and file system operations.

## Topics Covered

- **CPU Scheduling:** First Come First Served (FCFS), Priority Scheduling, and Non-Preemptive Shortest Job First (SJF)
- **Inter-Process Communication (IPC):** Message queues and process communication
- **Multithreading:** Thread creation and execution using C
- **Process Synchronization:** Classical synchronization problems, including the Dining Philosophers Problem
- **Deadlock Avoidance:** Banker's Algorithm
- **File Management:** File creation, copying, and deletion
- **Directory Structures:** Single-Level and Two-Level Directory implementations
- **File Access:** Random access file operations and employee record management

## Technologies Used
- **Programming Language:** C
- **Operating System Concepts:** Process management, scheduling, synchronization, and file systems
- **Tools:** GCC, Visual Studio Code, or any compatible C development environment

## How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/juhisakshisurin/CSA0403-Operating-System.git
   ```

2. Navigate to the repository directory:

   ```bash
   cd CSA0403-Operating-System
   ```

3. Compile a C program:

   ```bash
   gcc "Exp - 17 Banker's Algorithm.c" -o bankers
   ```

4. Run the program:

   ```bash
   ./bankers
   ```

   On Windows, run:

   ```bash
   bankers.exe
   ```

Replace the filename with the exact name of the experiment you want to execute. Programs that use platform-specific APIs or additional libraries may require different compilation commands.

## Purpose
The purpose of this repository is to strengthen understanding of Operating Systems through hands-on implementation of scheduling algorithms, process communication, synchronization, deadlock avoidance, and file management.

## Repository Structure
Each source file represents an individual lab experiment covering a specific Operating Systems concept or algorithm.

## Author
**Juhi Surin**

---

*Developed for academic learning and practical implementation of Operating Systems concepts using C.*
