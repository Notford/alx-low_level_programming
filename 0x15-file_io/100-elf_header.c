#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <elf.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(98);
    }

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        fprintf(stderr, "Error reading ELF header: %s\n", strerror(errno));
        exit(98);
    }

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "File is not an ELF file\n");
        exit(98);
    }

    printf("Magic: %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
           header.e_ident[EI_MAG0], header.e_ident[EI_MAG1], header.e_ident[EI_MAG2],
           header.e_ident[EI_MAG3], header.e_ident[EI_MAG4], header.e_ident[EI_MAG5],
           header.e_ident[EI_MAG6], header.e_ident[EI_MAG7], header.e_ident[EI_MAG8],
           header.e_ident[EI_MAG9], header.e_ident[EI_MAG10]);
    printf("Class: %s\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("Data: %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("Version: %d\n", header.e_ident[EI_VERSION]);
    printf("OS/ABI: %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX System V ABI" : "Unknown");
    printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
    printf("Type: %s\n", header.e_type == ET_EXEC ? "EXEC (Executable file)" :
                         (header.e_type == ET_DYN ? "DYN (Shared object file)" :
                          (header.e_type == ET_REL ? "REL (Relocatable file)" :
                           "Unknown")));
    printf("Entry point address: 0x%lx\n", header.e_entry);

    return 0;
}

