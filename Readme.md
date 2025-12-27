get_next_line

This project was created as part of the 42 / 1337 curriculum  
Author: hatimdride

--------------------------------------------------

OVERVIEW

get_next_line is a project from the 42 curriculum.
Its goal is to implement a function that reads from a file descriptor
one line at a time.

Each call to get_next_line returns the next line from the file descriptor,
including the newline character if it exists.

--------------------------------------------------

WHAT YOU LEARN

- How static variables work
- How file descriptors behave
- Using the read() system call
- Memory allocation and freeing
- Handling edge cases such as EOF and small buffers

--------------------------------------------------

FUNCTION PROTOTYPE
```c
char *get_next_line(int fd);
```
Behavior:
- Returns the next line read from fd
- Includes the newline character if present
- Returns NULL on end of file or error
- The returned line must be freed by the caller

--------------------------------------------------

COMPILATION

Mandatory part:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```
Bonus part:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```
BUFFER_SIZE can be set to any positive value.

--------------------------------------------------

USAGE EXAMPLE
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

--------------------------------------------------

HOW IT WORKS

- A static buffer keeps unread data between function calls
- Data is read using read() into a temporary buffer
- The temporary buffer is appended to the static buffer
- Reading continues until a newline or EOF is found
- When a newline is found, the line is returned
- Remaining data is saved for the next call
- When EOF is reached and no data remains, NULL is returned

This works even with:
- BUFFER_SIZE = 1
- Lines longer than BUFFER_SIZE
- Multiple reads per line

--------------------------------------------------

FILES
```c
get_next_line.c
get_next_line_utils.c
get_next_line_bonus.c
get_next_line_utils_bonus.c
get_next_line.h
README.md
```
--------------------------------------------------

RESOURCES

- 42 get_next_line subject PDF
- man 2 read
- man 3 malloc
- man 3 free

AI tools were used only for understanding concepts.
Code was written manually.
