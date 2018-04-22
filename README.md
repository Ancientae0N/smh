Hash Shell
==============

Simple shell written in C.

### Usage
### ------
`cd Hash`

`make`

`./Hash`

### --------
Features
--------

* Basic commands: `exit`, `pwd`, `clear` and `cd`
* Environment management with `setenv` and `unsetenv`
* Program invocation with forking and child processes
* I/O redirection (use of `dup2` system call) limited to the following:  
        `<cmd> <args> > <output>`  
        `<cmd> <args> < <input> > <output>`
* Background execution of programs with `&`
* Piping implemented (`<cmd1> | <cmd2>`) via `pipe` and `dup2` syscalls. Multiple piping is allowed.
* SIGINT signal when Ctrl-C is pressed (shell is not exited)
* Aliasing implemented, eg: `alias ll ls -l`. Input ll into the shell and get the result of ls -l.
* 2 new extensions to ls added: 
->`ls -z` which lists out all the files with a size of 0 bytes 
->`ls -e` which lists out all the files without an extension!
* History command which lists out all the commands entered until now. Use `history`
* Editor implemented in the shell. Use `hashit` to get the editor and follow the instructions after.
* Entering the up-arrow key executes the instruction which was entered previously.

