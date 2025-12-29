*This project has been created as part of the 42 curriculum by hadrider.*

# get_next_line

## Description

get_next_line is a 42 / 1337 project that consists of implementing a function
that reads and returns one line at a time from a file descriptor.
Each call returns the next line, including the newline character (`\n`) if it exists,
until end of file.

## Function Prototype

```c
char *get_next_line(int fd);
```
   Returns the next line from fd

   Includes \n if present

   Returns NULL on EOF or error

   The returned string must be freed by the caller

## Instructions

### Compilation

#### Mandatory:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```
#### Bonus:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```
#### Usage
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
### example file 

#### file.txt
```
hello world\n
hello test\n
test\n
```
### expected output

#### first call
```
hello world\n
```
#### second call
```
hello test\n
```

## Algorithm

A static buffer stores unread data between calls.
Data is read using read() and appended until a newline or EOF is found.
When a newline exists, the line is returned and the remaining data is kept
for the next call.
At EOF, remaining data is returned once, then NULL.

This works with any BUFFER_SIZE, including 1, and with lines longer than
the buffer size.

## Resources

   42 get_next_line subject PDF

   man 2 read

   man 3 malloc

   man 3 free

## AI Usage

AI tools were used only to understand general concepts.
All code was written manually.

## Author

hadrider
