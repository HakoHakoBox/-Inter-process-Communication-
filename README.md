# -Inter-process-Communication-

This program communicates between system processes to accomplish a task. This code needs to be run on Linux because the unistd.h library is for Linux system commands.
This program aims to:

1) Have the parent and child processes create 2 unique pipes using pipe() system call.
2) Have the parent process forks (using the fork() system call to spawn the child process).
3) Have the parent and child processes create 2 file descriptors, one for each pipe().
