# 🐚 **Minishell**  
A minimal Bash shell clone developed as part of the 42 School curriculum. This project challenges you to dive deep into shell programming, system calls, and teamwork while delivering a functional and interactive command-line interface.

---

## 🌟 **About the Project**

**Minishell** is a core project at 42 School where students create a simplified version of Bash. It emphasizes understanding key components of shell functionality, such as:  
- Parsing commands and handling syntax.  
- Managing system processes with `fork`, `exec`, and `wait`.  
- Handling pipes, redirections, and environment variables.  
- Implementing built-in commands like `echo`, `cd`, `pwd`, `env`, `export`, `unset`, and `exit`.  

This project not only develops low-level programming skills but also instills problem-solving and collaboration practices.

---

## 🚀 **Features**

### ✅ **Core Shell Capabilities**
- **Prompt Display:** Shows the shell prompt, waiting for user input.  
- **Command Execution:** Handles executables from `$PATH` and local directories.  
- **Built-in Commands:** Implements core shell commands:
  - `echo` (with `-n` option).
  - `cd` (relative/absolute paths).
  - `pwd`, `env`, `export`, `unset`, and `exit`.
- **Environment Variables:** Expands variables like `$HOME` or `$USER`.  

### 🔗 **Advanced Functionalities**
- **Pipes (`|`)**: Redirect output from one command to the input of another.  
- **Redirections:** Supports operators like `>`, `>>`, `<`, and `<<`.  
- **Command History:** Navigate previous commands with arrow keys.  

---

## 🛠️ **How to Use**

### 1️⃣ **Installation**  
Clone the repository and compile the project:  
```bash
git clone https://github.com/dhsudev/minishell.git
cd minishell
make
```
### 2️⃣ Running the Shell
Launch Minishell:
```bash
./minishell
```

### 3️⃣ Exiting
To exit the shell, type:
```bash
exit
```

## 🔍 Technical Insights
### Key Concepts
- **Lexical Analysis & Parsing:** Breaking down user input into tokens and parsing commands to interpret their structure.
- **Process Management:** Leveraging fork, execve, and waitpid for running commands and handling child processes.
- **Signal Handling:** Responding gracefully to signals like Ctrl+C (interrupt).
- **Memory Management:** Avoiding memory leaks and ensuring efficient usage.
### Challenges
Handling edge cases in redirections, piping, and variable expansions.
Ensuring compliance with POSIX standards while maintaining simplicity.
