# pipex

Reimplementation of the Unix shell piping behavior. This project mimics how the shell handles command pipelines using `|`, redirections, and file descriptors — with minimal system calls.

---

## 🛠️ Project Goal

Recreate the shell behavior for a command like:

```bash
< infile cmd1 | cmd2 > outfile


✅ Features

Handle multiple commands (bonus)

File input/output redirection

Pipe creation and chaining

Path resolution using envp

Error handling and exit status propagation

Support for quoted arguments

    Support for here_doc (bonus)

🔧 Allowed Functions

You may use the following system calls and library functions:

    open, close, read, write, malloc, free, perror, strerror

    access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid

🧪 Usage
Basic execution:

./pipex infile "cmd1" "cmd2" outfile

Equivalent to:

< infile cmd1 | cmd2 > outfile

Example:

./pipex input.txt "grep a" "wc -l" output.txt

This will:

    Take input from input.txt

    Run grep a, then pipe its output to:

    wc -l, and finally write the result to output.txt

