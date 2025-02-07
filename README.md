# File System Explorer
A simple command-line file system explorer written in C.

How to Compile

    make all

How to clean

    make fclean

Run the program:

    ./FSExplorer


You'll see the following menu:

    text
    > File System Explorer~#

    >/[Nothing] | Exit
    >           | Show Path
    >           | List Objects

    > Enter option:

    Enter your choice:
        0 or press Enter without input to exit the program
        1 to display the current path
        2 to list all files and directories in the current location

What I Learned
This project helped me understand and implement several important system calls and functions in C:

fork()

    Creates a new process by duplicating the calling process
    Child process gets a return value of 0, parent gets the child's PID

waitpid()

    Suspends the calling process until a specific child process terminates
    Allows waiting for a particular child process, unlike wait()
    Useful for synchronizing parent and child processes

system()

    Executes a command specified in a string by calling /bin/sh
    Combines fork(), execl(), and waitpid() in a single function call
    Convenient for executing shell commands from within a C program

read() *had to refresh my memory on it*

    Reads data from a file descriptor into a buffer
    Returns the number of bytes read or -1 on error
