#include <stdio.h>
#include "encode.h"
#include "types.h"
#include <string.h>
#include "common.h"


/*************************************************************************************************
 * FUNCTION DEFINITION: read_and_validate_encode_args()
 
 ----> this function validates if correct type of files are passed or not
 */

Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    if (strcmp(strchr(argv[2], '.'), ".bmp") == 0)				//checking if 3rd CLA is a .bmp file or not
	encInfo -> src_image_fname = argv[2];					//if yes, storing the address of source bmp file name in src_image_fname
    else
	return e_failure;

    if (strcmp(strchr(argv[3], '.'), ".txt") == 0)				//checking if 4th CLA is a .txt file or not
	encInfo -> secret_fname = argv[3];					//if yes, storing the address of secret txt file name in secret_fname
    else
	return e_failure;

    if (argv[4] == NULL)							//checking if 5th CLA is passed or not
	encInfo -> stego_image_fname = "stego.bmp";				//if not, storing the default name in address pointed by stego_image_fname
    else
	encInfo -> stego_image_fname = argv[4];					//if passed, storing the given name in address pointed by stego_image_fname

    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: open_files()

 ----> Get File pointers for i/p and o/p files
 ----> Inputs: Src Image file, Secret file and
 ----> Stego Image file
 ----> Output: FILE pointer for above files
 ----> Return Value: e_success or e_failure, on file errors
 */

Status open_files(EncodeInfo *encInfo)
{
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");				// Src Image file
    
    if (encInfo->fptr_src_image == NULL)							// Do Error handling
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

	return e_failure;
    }
    
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");					// Secret file
    
    if (encInfo->fptr_secret == NULL)								// Do Error handling
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

	return e_failure;
    }

    
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");				// Stego Image file
    
    if (encInfo->fptr_stego_image == NULL)							// Do Error handling
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

	return e_failure;
    }

    return e_success;										// No failure return e_success
}



/*************************************************************************************************
 * FUNCTION DEFINITION: check_capacity()

 ----> this function checks if the source image has the required space or not to store the secret file
 */

Status check_capacity(EncodeInfo *encInfo)
{
    encInfo -> image_capacity =  get_image_size_for_bmp(encInfo -> fptr_src_image);		//storing source image capacity in image_capacity
    
    encInfo -> size_secret_file = get_file_size(encInfo -> fptr_secret);			//storing size of secret file in size_secret_file

    if( encInfo -> image_capacity > (16 + 32 + 32 + 32 + (encInfo -> size_secret_file * 8 )))	//checking if required space is avaiable or not
	return e_success;
    else
	return e_failure;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: get_image_size_for_bmp()
 
 ----> Get image size
 ----> Input: Image file ptr
 ----> Output: width * height * bytes per pixel (3 in our case)
 ----> Description: In BMP Image, width is stored in offset 18,
 ----> and height after that. size is 4 bytes
 */

uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;					// Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);
    
    fread(&width, sizeof(int), 1, fptr_image);		// Read the width (an int)
    printf("width = %u\n", width);
    
    fread(&height, sizeof(int), 1, fptr_image);		// Read the height (an int)
    printf("height = %u\n", height);
    
    return width * height * 3;				// Return image capacity
}



/*************************************************************************************************
 * FUNCTION DEFINITION: get_file_size()

 ----> this function calculates the file size
 */

long get_file_size(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);							//moving FILE pointer 0 position from end
    return ftell(fptr);								//returns file size
}



/*************************************************************************************************
 * FUNCTION DEFINITION: copy_bmp_header()

 ----> this function copies the bmp header data from source image to stego image
 */

Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image)
{
    char str[54];								//declaring a char array
    
    fseek(fptr_src_image, 0, SEEK_SET);						//moving the FILE pointer to 0th position
    
    fread(str, 54, 1, fptr_src_image);						//reading 54 bytes from beginning from source image
    
    fwrite(str, 54, 1, fptr_dest_image);					//writing 54 bytes to stego image from the beginning
    
    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: encode_magic_string()

 ----> this function encodes the magic string into stego image
 */

Status encode_magic_string(char *magic_string, EncodeInfo *encInfo)
{
    encode_data_to_image(magic_string, strlen(magic_string), encInfo);		//function call
    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: encode_extn_size()

 ----> this function encodes the secret file's extension size into the stego image
 */

Status encode_extn_size(int size, EncodeInfo *encInfo)
{
    encode_size_to_lsb(size, encInfo);				//function call
    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: encode_file_extn()

 ----> this function encodes the secret file's extension into the stego image
 */

Status encode_secret_file_extn(char *file_extn, EncodeInfo *encInfo)
{
    encode_data_to_image(file_extn, strlen(file_extn), encInfo);		//function call
    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: encode_secret_file_size()

 ----> this function encodes the secret file's size into the the stego image
 */

Status encode_secret_file_size(int file_size, EncodeInfo *encInfo)
{
    encode_size_to_lsb(file_size, encInfo);					//function call
    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: encode_secret_file_data()

 ----> this function encodes the secret file's data into the the stego image
 */

Status encode_secret_file_data(EncodeInfo *encInfo)
{
    fseek(encInfo -> fptr_secret, 0, SEEK_SET);					//moving the FILE pointer to 0th position
    
    char str[encInfo -> size_secret_file];					//declaring a char string
    
    fread(str, encInfo -> size_secret_file, 1, encInfo -> fptr_secret);		//reading data from secret file and storing to str
    
    encode_data_to_image(str, encInfo -> size_secret_file, encInfo);		//function call
    
    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: copy_remaining_img_data()

 ----> this function copies the leftover unmodified data from source bmp file to the stego file
 */

Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
    char ch;
    
    while(fread(&ch, 1, 1, fptr_src) > 0)
    {
	fwrite(&ch, 1, 1, fptr_dest);
    }
    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: do_encoding()

 ----> this function encodes the data
 */

Status do_encoding(EncodeInfo *encInfo)
{
    if (open_files(encInfo) == e_success)
    {
	printf("Open file is a success\n");

	if(check_capacity(encInfo) == e_success)
	{
	    printf("Check capacity is a success\n");

	    if(copy_bmp_header(encInfo -> fptr_src_image, encInfo -> fptr_stego_image) == e_success)
	    {
		printf("Copied bmp header successfully\n");

		if(encode_magic_string(MAGIC_STRING, encInfo) == e_success)
		{
		    printf("Encoded magic string successfully\n");

		    strcpy(encInfo -> extn_secret_file, strstr(encInfo -> secret_fname, "."));

		    if(encode_extn_size(strlen(encInfo -> extn_secret_file), encInfo) == e_success)
		    {
			printf("Encoded extension size successfully\n");

			if(encode_secret_file_extn(encInfo -> extn_secret_file, encInfo) == e_success)
			{
			    printf("Encoded secret file extension successfully\n");

			    if (encode_secret_file_size(encInfo -> size_secret_file, encInfo) == e_success)
			    {
				printf("Encoded secret file size successfully\n");

				if (encode_secret_file_data(encInfo) == e_success)
				{
				    printf("Encoded secret file data\n");

				    if(copy_remaining_img_data(encInfo -> fptr_src_image, encInfo -> fptr_stego_image) == e_success)
				    {
					printf("Copied remaining data\n");
				    }
				    else
				    {
					printf("Failed to copy remaining data\n");
					return e_failure;
				    }
				}
				else
				{
				    printf("Failed to encode secret data\n");
				    return e_failure;
				}
			    }
			    else
			    {
				printf("Failed to encode secret file size\n");
				return e_failure;
			    }
			}
			else
			{
			    printf("Failed to encode secret file extension\n");
			    return e_failure;
			}
		    }
		    else
		    {
			printf("Failed to encode extension size\n");
			return e_failure;
		    }
		}
		else
		{
		    printf("Failed to encode magic string\n");
		    return e_failure;
		}
	    }
	    else
	    {
		printf("Failed to copy bmp header\n");
		e_failure;
	    }
	}
	else
	{
	    printf("Check capacity is a failure\n");
	    return e_failure;
	}
    }
    else
    {
	printf("Open file is a failure\n");
	return e_failure;
    }
    return e_success;
}



/*===================================== GENERIC FUNCTIONS ========================================
 
 * FUNCTION DEFINITION: encode_data_to_image()

 ----> this is a generic function to encode character data
 */

Status encode_data_to_image(char *data, int size, EncodeInfo *encInfo)
{
    for(int i = 0; i < size; i++)							//loop till no. of character times
    {
	fread(encInfo -> image_data, 8, 1, encInfo -> fptr_src_image);			//reading 8 bytes from source bmp file and storing it to image_data

	encode_byte_to_lsb(data[i], encInfo -> image_data);				//function call

	fwrite(encInfo -> image_data, 8, 1, encInfo -> fptr_stego_image);		//storing 8 bytes of modified data into stego image
    }

    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: encode_bytes_to_lsb()

 ----> this function encodes 1 byte of secret data to 8 bytes of source bmp data into the LSB
 */

Status encode_byte_to_lsb(char data, char *image_buffer)
{
    for(int i = 0; i < 8; i++)
    {
	image_buffer[i] = (image_buffer[i] & 0xFE) | ((data >> (7 - i)) & 1);			//storing secret data to LSB
    }
    
    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: encode_size_to_lsb()

 ----> this is a generic function to encode integer data
 ----> it encodes 4 byte of secret data to 32 bytes of source bmp data into the LSB
 */

Status encode_size_to_lsb(int size, EncodeInfo *encInfo)
{
    char str[32];										//declaring char array
    
    fread(str, 32, 1, encInfo -> fptr_src_image);						//reading 32 bytes from souce bmp file and storing to str

    for(int i = 0; i < 32; i++)
    {
	str[i] = (str[i] & 0xFE) | ((size >> (31 - i)) & 1);					//storing secret data to LSB
    }

    fwrite(str, 32, 1, encInfo -> fptr_stego_image);						//storing 32 bytes of modified data into stego image
    
    return e_success;
}
