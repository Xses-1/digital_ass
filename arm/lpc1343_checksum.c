/*
 * The NXP LPC-1343 ARM Cortex-M3 microcontroller requires that exception vector
 * 7 contains the 2's complement of the checksum of the exception vector entries
 * 0 - 6. This is described in UM10375 LPC1311/13/42/43 User manual section 21.7,
 * page 322 (Rev. 4, 28 September 2011).
 * This program calculates that checksum and writes it to the binary image.
 * This program should expects the binary file to be in little endian format,
 * it should be independent of the endianess of the platform the program runs
 * on. This is accomplished by reading in data in single bytes. This is not the
 * fastest approach, but in this case the low number of bytes processed
 * (8*4 = 32) makes the delay unnoticeble.
 */

/* C-99 */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define NUM_OF_VECTORS		7
#define BYTES_PER_VECTOR	4
#define NUM_OF_BYTES		((NUM_OF_VECTORS) * (BYTES_PER_VECTOR))


int main (int argc, char *argv[])
{
	// Check arguments
	if (argc != 2)
	{
		fprintf (stdout, "Usage: %s <file>\n", argv[0]);
		exit (EXIT_SUCCESS);
	}

	// Open file
	FILE *file;

	if ((file = fopen(argv[1], "rb+")) == NULL)
	{
		fprintf (stderr, "Error: cannot open file\n");
		exit (EXIT_FAILURE);
	}

	// Read vectors
	uint8_t buffer[NUM_OF_BYTES];

	if (fread (buffer, sizeof(uint8_t), NUM_OF_BYTES, file) != NUM_OF_BYTES)
	{
		fprintf (stderr, "Error: cannot read file\n");
		fclose (file);
		exit (EXIT_FAILURE);
	}

	// Calculate checksum
	uint32_t checksum = 0;

	for (int i = 0; i < NUM_OF_BYTES; i+=4)
	{
		uint32_t temp = 0;
		// Binary file is in little endian
		// Read in in bytes for endianess-neutrality
		temp |= ((uint32_t)(buffer[i+0])) <<  0;
		temp |= ((uint32_t)(buffer[i+1])) <<  8;
		temp |= ((uint32_t)(buffer[i+2])) << 16;
		temp |= ((uint32_t)(buffer[i+3])) << 24;
		checksum += temp;
	}
	// 2's complement
	checksum = -checksum;

	// Switch to write mode
	if (fseek (file, 0, SEEK_CUR) != 0)
	{
		fprintf (stderr, "Error: cannot switch to write mode\n");
		fclose (file);
		exit (EXIT_FAILURE);
	}

	// Write checksum
	// Write as bytes for endianess-neutrality
	const uint8_t checksum_array[] = {checksum, checksum>>8, checksum>>16, checksum>>24};

	if (fwrite (checksum_array, sizeof(uint8_t), sizeof(checksum_array), file) != sizeof(checksum_array))
	{
		fprintf (stderr, "Error: cannot write to file\n");
		fclose (file);
		exit (EXIT_FAILURE);
	}

	// Exit
	fclose (file);
	exit (EXIT_SUCCESS);
}
