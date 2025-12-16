## Dummy-Proof Notes: Streams and File Handling in C++

### 1. What is a Stream?
- A stream is like a pipe that moves data between your program and something else (like a file or the screen).
- Streams let you read (input) or write (output) data easily.

### 2. Types of Streams
- **ifstream**: For reading from files.
- **ofstream**: For writing to files.
- **fstream**: For both reading and writing.

### 3. Data Representation
- Data in memory is stored as binary (just bytes).
- Files can store data as text (human-readable) or binary (raw bytes).
- Binary I/O is fast and saves space, but is not human-readable.

### 4. Including the Header
Always add this at the top:
```cpp
#include <fstream>
```

### 5. Opening and Closing Files
- To open a file, create a stream object and give it a filename.
- Always close files when done (with `.close()`).
```cpp
std::ofstream outFile("output.txt"); // open for writing
std::ifstream inFile("input.txt");   // open for reading
outFile.close();
inFile.close();
```

### 6. Checking if a File Opened
Always check if the file opened successfully:
```cpp
if (!inFile.is_open()) {
	std::cout << "Could not open file!" << std::endl;
}
```

### 7. File Opening Modes
You can control how files are opened using modes:
- `std::ios::in` – open for reading
- `std::ios::out` – open for writing (overwrites file)
- `std::ios::app` – append to end
- `std::ios::binary` – open as binary
- `std::ios::trunc` – clear file contents if it exists
Example:
```cpp
std::ofstream outFile("data.bin", std::ios::binary | std::ios::app);
```

### 8. Reading and Writing Text
**Write:**
```cpp
outFile << "Hello, file!" << std::endl;
```
**Read:**
```cpp
std::string line;
while (std::getline(inFile, line)) {
	std::cout << line << std::endl;
}
```

### 9. Binary (Unformatted) I/O
- Use `.write()` to write raw bytes, `.read()` to read raw bytes.
- You need to cast your data to `char*` using `reinterpret_cast`.
Example:
```cpp
int number = 42;
outFile.write(reinterpret_cast<char*>(&number), sizeof(number));
inFile.read(reinterpret_cast<char*>(&number), sizeof(number));
```

### 10. Random-Access Files
- Sometimes you need to jump to a specific spot in a file (not just read/write in order).
- Use `seekg()` to move the read pointer, `seekp()` for the write pointer.
Example:
```cpp
inFile.seekg(0, std::ios::beg); // go to start
outFile.seekp(10, std::ios::cur); // move 10 bytes from current
```

### 11. Summary Table: File Modes
| Mode           | What it does                | Default for |
|----------------|----------------------------|-------------|
| std::ios::in   | Read from file             | ifstream    |
| std::ios::out  | Write to file (overwrite)  | ofstream    |
| std::ios::app  | Add to end of file         |             |
| std::ios::binary| Binary mode (raw bytes)   |             |
| std::ios::trunc| Clear file if it exists    | ofstream    |

### 12. Tips
- Always check if your file opened.
- Always close your files.
- Use binary mode for speed and space, text mode for human readability.
- Use random access for fast jumps in big files.
