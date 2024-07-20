## ELF Parser

This program parses an ELF (Executable and Linkable Format) file and prints information from its header.

### Compilation

To compile the program, use the following command:

```bash
gcc -o elf_parser elf_parser.c -lelf
```

### Usage

Run the compiled executable with the ELF file path as an argument:

```bash
./elf_parser /path/to/your/elf/file
```

### Finding ELF Definitions

To find all the relevant `#define` options in the ELF header file (`elf.h`), you can use the following command:

```bash
grep -E '^\s*#define\s+EM_|^\s*#define\s+ELF|^\s*#define\s+EI_' /usr/include/elf.h
```

This command searches for lines starting with `#define EM_`, `#define ELF`, and `#define EI_` in `/usr/include/elf.h`, which typically define machine types (`EM_`), ELF constants (`ELF`), and ELF identification (`EI_`) constants.

### Example Output

Assuming you have an ELF file located at `/home/vm/Desktop/ELF_Parser/Task1`, here's an example of the output:

```plaintext
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Shared object file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x1060
  Start of program headers:          64 (bytes into file)
  Start of section headers:          14104 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         13
  Size of section headers:           64 (bytes)
  Number of section headers:         31
  Section header string table index: 30

```

---

### Explanation:

- **Compilation**: The `gcc` command compiles the `elf_parser.c` file and links with the `libelf` library (`-lelf`).
- **Usage**: After compilation, run `./elf_parser` followed by the path to your ELF file.
- **Finding ELF Definitions**: Use `grep` to search for relevant `#define` options (`EM_`, `ELF`, `EI_`) in `elf.h`, which include machine types, ELF constants, and ELF identification constants.
- **Example Output**: Demonstrates a sample output of the program, showing various fields parsed from the ELF header.
