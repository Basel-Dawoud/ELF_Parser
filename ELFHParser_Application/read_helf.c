#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <stdint.h>
#include <string.h>

#define FILE_PATH "/home/vm/Desktop/ELF_Parser/Task1"

void print_elf_header_info(Elf64_Ehdr *header) {
    // Print ELF magic bytes
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; ++i) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    // Print ELF class
    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    // Print data encoding
    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    // Print ELF version
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    // Print OS/ABI
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    // Print ABI version
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    // Print type
    printf("  Type:                              ");
    switch (header->e_type) {
        case ET_NONE:
            printf("NONE (No file type)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

// Print machine
	printf("  Machine:                           ");
	switch (header->e_machine) {
	    case EM_X86_64:
		printf("Advanced Micro Devices X86-64\n");
		break;
	    case EM_ARM:
		printf("ARM\n");
		break;
	    case EM_386:
		printf("Intel 80386\n");
		break;
	    case EM_IA_64:
		printf("Intel Itanium\n");
		break;
	    default:
		printf("Unknown\n");
		break;
	}

    // Print version
    printf("  Version:                           0x%x\n", header->e_version);
    
    // Print entry point address
    printf("  Entry point address:               0x%lx\n", header->e_entry);

    // Print start of program headers
    printf("  Start of program headers:          %lu (bytes into file)\n", header->e_phoff);

    // Print start of section headers
    printf("  Start of section headers:          %lu (bytes into file)\n", header->e_shoff);

    // Print flags
    printf("  Flags:                             0x%x\n", header->e_flags);

    // Print size of this header
    printf("  Size of this header:               %u (bytes)\n", header->e_ehsize);

    // Print size of program headers
    printf("  Size of program headers:           %u (bytes)\n", header->e_phentsize);

    // Print number of program headers
    printf("  Number of program headers:         %u\n", header->e_phnum);

    // Print size of section headers
    printf("  Size of section headers:           %u (bytes)\n", header->e_shentsize);

    // Print number of section headers
    printf("  Number of section headers:         %u\n", header->e_shnum);

    // Print section header string table index
    printf("  Section header string table index: %u\n", header->e_shstrndx);
}

int main(int argc, char **argv) {
    FILE *elfFile = fopen(FILE_PATH, "rb");
    if (elfFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    Elf64_Ehdr elfHeader;
    fread(&elfHeader, sizeof(elfHeader), 1, elfFile);

    printf("ELF Header:\n");
    print_elf_header_info(&elfHeader);

    fclose(elfFile);

    return 0;
}

