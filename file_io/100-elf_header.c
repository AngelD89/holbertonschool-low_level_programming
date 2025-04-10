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
	dprintf(STDERR_FILENO, "%\n", msg);
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
 * print_elf_header - Prints the ELF header.
 * @header: ELF header struct.
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int i;
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", header->e_ident[i], (i < EI_NIDENT - 1) ? ' ' : '\n');

	printf("  Class:                             %s\n",
			header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
			header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "Invalid class");

	printf("  Data:                              %s\n",
			header->e_ident[EI_DATA] == ELFDATA2LSB ?
			"2's complement, little endian" :
			header->e_ident[EI_DATA] == ELFDATA2MSB ?
			"2's complement, big endian" : "Invalid data");

	printf("  Version:                           %d (current)\n",
			header->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            %s\n",
			header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
			header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
			header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
			header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
			"<unknown>");

	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);

	printf("  Type:                              %s\n",
			header->e_type == ET_EXEC ? "EXEC (Executable file)" :
			header->e_type == ET_DYN ? "DYN (Shared object file)" :
			header->e_type == ET_REL ? "REL (Relocatable file)" : "<unknown>");

	printf("  Entry point address:               %#lx\n",
			(unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
	Elf64_Ehdr header;
	int fd;
	ssize_t r;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file");

	r = read(fd, &header, sizeof(header));
	if (r != sizeof(header))
		print_error("Error: Cannot read ELF header");

	check_elf(header.e_ident);
	print_elf_header(&header);

	close(fd);
	return (0);
}
