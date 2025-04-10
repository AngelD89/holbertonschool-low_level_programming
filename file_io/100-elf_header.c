#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error - Prints error message and exits with code 98.
 * @msg: error message.
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * check_elf - Checks if file is an ELF file.
 * @e_ident: ELF identification bytes.
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
		e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
	{
	print_error("Error: Not an ELF file");
	}
}

/**
 * print_magic - Prints the ELF magic bytes.
 * @e_ident: Pointer to ELF identification bytes
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:  ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", e_ident[i], (i < EI_NIDENT - 1) ? ' ' : '\n');
}

/**
 * print_class - Prints the ELF class.
 * @e_ident: Pointer to ELF identification bytes.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else
		printf("Invalid class\n");
}

/**
 * print_data - Prints the ELF data encoding.
 * @e_ident: Pointer to ELF identification bytes
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Invalid data\n");
}
/**
 * print_osabi - Prints the OS/ABI type.
 * @e_ident: Pointer to ELF identification bytes.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	default:
		printf("<unknown>\n");
	}
}

/**
 * print_elf_header - Prints the ELF header.
 * @header: Pointer to ELF header struct.
 */
void print_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	print_osabi(header->e_ident);
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
			(header->e_type == ET_EXEC) ? "EXEC (Executable file)" :
			(header->e_type == ET_DYN) ? "DYN (Shared object file)" :
			(header->e_type == ET_REL) ? "REL (Relocatable file)" : "<unknown>");
	printf("  Entry point address:               %#lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
	Elf64_Ehdr header;
	int fd;
	ssize_t bytes;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file");

	bytes = read(fd, &header, sizeof(header));
	if (bytes != sizeof(header))
		print_error("Error: Cannot read ELF header");

	check_elf(header.e_ident);
	print_elf_header(&header);

	close(fd);
	return (0);
}
