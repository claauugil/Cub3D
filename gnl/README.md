
## Get_next_line

Project overview:

get_next_line is a function that reads and returns a line from a given file descriptor. It is designed to read from files or standard input, reading each line individually until the end of the file is reached. The function operates effectively regardless of the line's length or the buffer size.

## Function Prototype 

```bash
char *get_next_line(int fd);
```

## Return Value

- Returns the line read from the file descriptor if successful.
- Returns NULL if there is an error or if the end of the file is reached.

## Key Features

- Reads from a file descriptor using the read function.
- Supports reading from both files and stdin.
- Ensures that the returned line ends with a newline character (\n), except when the end of the file is reached without one.
- It saves any remaining data in the buffer, ensuring it is not lost and can be used in subsequent calls.
- Compiles with the -D BUFFER_SIZE=xx flag (and also without it) to allow customizable buffer size for reading.

## Implementation details

Static Variables:

- The use of static variables is crucial for maintaining state between function calls, which is necessary for tracking the current position in the file.
- get_next_line() should behave as expected when used in a loop to read lines sequentially from a file.
