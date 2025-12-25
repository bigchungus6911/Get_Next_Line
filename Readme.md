*This project has been created as part of the 42 curriculum by hatimdride.*

# get_next_line

## Description

**get_next_line** is a project from the 42 / 1337 curriculum whose goal is to implement a function capable of reading a file descriptor **line by line**.

Each call to `get_next_line()` returns the next line from the given file descriptor, including the terminating newline character (`\n`) if it exists. The function must correctly handle buffering, partial reads, end-of-file cases, and memory management, while respecting strict constraints on allowed functions.

This project is designed to strengthen understanding of:

* Static variables
* File descriptors and the `read()` system call
* Memory allocation and freeing
* String manipulation without standard library helpers

---

## Instructions

### Compilation

Compile the project with a chosen buffer size:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

You can change `BUFFER_SIZE` to any positive value at compile time.

---

### Usage

Example of usage in a program:

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```

The caller is responsible for freeing the returned line.

---

## Algorithm Explanation

The algorithm is based on **incremental reading and buffering**:

1. A **static buffer (`text`)** is used to store leftover data between function calls.
2. The function reads from the file descriptor into a temporary buffer of size `BUFFER_SIZE`.
3. Read data is appended to the static buffer until a newline character is found or EOF is reached.
4. Once a newline is detected:

   * A line is extracted from the buffer and returned.
   * The remaining data after the newline is saved for the next call.
5. If EOF is reached without remaining data, the function returns `NULL`.

This approach ensures:

* No data loss between calls
* Minimal reads
* Correct handling of lines longer than `BUFFER_SIZE`

Memory is carefully managed by freeing unused buffers and reallocating only what is necessary.

---

## Files

```
get_next_line.c        # Core logic
get_next_line_utils.c  # Utility functions
get_next_line.h        # Prototypes and macros
README.md
```

---

## Resources

* 42 Subject PDF: *get_next_line*
* `man 2 read`
* `man 3 malloc`
* `man 3 free`
* GNU C Library Documentation

---

## Author

Hatim Dride

## School

42 / 1337
