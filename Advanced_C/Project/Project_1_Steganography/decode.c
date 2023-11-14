#include <stdio.h>
#include "decode.h"
#include "types.h"
#include <string.h>
#include "common.h"


/*************************************************************************************************
 * FUNCTION DEFINITION: read_and_validate_decode_args() 

 ----> his function validates if correct type of files are passed or not
 */

Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    if (strcmp(strchr(argv[2], '.'), ".bmp") == 0)				//checking if 3rd CLA is a .bmp file or not
    {
	decInfo -> stego_image_fname = argv[2];;				//if yes, storing the address of stego bmp file name in stego_image_fname
    }
    else
    {
	return e_failure;
    }

    if (argv[3] == NULL)							//checking if 4th CLA is passed or not
    {
	decInfo -> decoded_file_fname = "decoded.txt";				//if not, storing the default name in address pointed by decoded_file_fname

    }else
    {
	decInfo -> decoded_file_fname = argv[3];				//if passed, storing the given name in address pointed by decoded_file_fname
    }
    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: get_files()

 ----> Get File pointers for i/p and o/p files
 ----> Inputs: Stego Image file, Decoded Text file
 ----> Output: FILE pointer for above files
 ----> Return Value: e_success or e_failure, on file errors
 */

Status get_files(DecodeInfo *decInfo)
{
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");			       // Stego Image file

    if (decInfo->fptr_stego_image == NULL)                                                     // Do Error handling
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);

	return e_failure;
    }


    decInfo->fptr_decoded_file = fopen(decInfo->decoded_file_fname, "w");			//Decode Text file

    if (decInfo->fptr_decoded_file == NULL)							// Do Error handling
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->decoded_file_fname);

	return e_failure;
    }

    return e_success;										// No failure return e_success
}



/*************************************************************************************************
 * FUNCTION DEFINITION: decode_magic_string() 

 ----> this fuction decodes the magic string and validates it
 */

Status decode_magic_string(FILE *fptr, char *magic_string, DecodeInfo *decInfo)
{
    fseek(fptr, 54, SEEK_SET);								//moving FILE pointer to 54th position from beginning
    int size = strlen(magic_string);

    for(int i = 0; i < size; i++)
    {
	fread(decInfo -> image_data, 8, 1, decInfo -> fptr_stego_image);		//reading 8 bytes from Stego image

	decode_byte_from_lsb(decInfo -> image_data, decInfo);				//decoding 1 byte

	decInfo -> magic_str[i] = decInfo -> one_byte;					//storing the decoded byte in magic_str
	decInfo -> magic_str[i+1] = '\0';						//adding null character at the end
    }
    if(strcmp(magic_string, decInfo -> magic_str) == 0)					//validating magic string
    {
	return e_success;
    }
    else
    {
	return e_failure;
    }
}



/*************************************************************************************************
 * FUNCTION DEFINITION: decode_extn_size()

 ----> this function decodes the extension size of the file to be decoded
 */

Status decode_extn_size(DecodeInfo *decInfo)
{
    decode_size_from_lsb(decInfo);				//function call

    decInfo -> extn_size = decInfo -> int_data;			//storing extension size in extn_size

    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: decode_secret_file_extn()

 ----> this function docodes the extenion of the file to be decoded and also checks if the
       extension matches with the user suggested file name.
 */

Status decode_secret_file_extn(DecodeInfo *decInfo)
{
    int size = decInfo -> extn_size;
    
    for(int i = 0; i < size; i++)
    {
	fread(decInfo -> image_data, 8, 1, decInfo -> fptr_stego_image);			//reading 8 bytes from Stego image

	decode_byte_from_lsb(decInfo -> image_data, decInfo);					//decoding 1 byte

	decInfo -> extn_decoded_file[i] = decInfo -> one_byte;					//storing the decoded byte in extn_decoded_file
	decInfo -> extn_decoded_file[i+1] = '\0';						//adding null character at the end

    }

    if( strcmp( strstr(decInfo -> decoded_file_fname, "."), decInfo -> extn_decoded_file ) == 0 )	//checking if extension matches with user suggested file name
    {
	return e_success;
    }
    else												//if extension does not matches, assigning default file name
    {
	decInfo -> decoded_file_fname = "decoded.txt";

	decInfo->fptr_decoded_file = fopen(decInfo->decoded_file_fname, "w");

	return e_success;
    }
}



/*************************************************************************************************
 * FUNCTION DEFINITION: decode_secret_file_size()

 ----> this fuction decodes the size of the file to be decoded
 */

Status decode_secret_file_size(DecodeInfo *decInfo)
{
    decode_size_from_lsb(decInfo);						//function call

    decInfo -> size_decoded_file = decInfo -> int_data;				//storing size of the file in size_decoded_file

    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: decode_secret_file_data()

 ----> this function decodes the secret data and stores inside the decoded file
 */

Status decode_secret_file_data(DecodeInfo *decInfo)
{
    decode_data_from_image(decInfo -> size_decoded_file, decInfo);		//function call

    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: do_decoding()

 ----> this function decodes the data
 */

Status do_decoding(DecodeInfo *decInfo)
{
    if (get_files(decInfo) == e_success)
    {
	printf("Open file is a success\n");
	if(decode_magic_string(decInfo -> fptr_stego_image, MAGIC_STRING, decInfo) == e_success)
	{
	    printf("Decoded magic string successfully\n");

	    if(decode_extn_size(decInfo) == e_success)
	    {
		printf("Decoded extension size successfully\n");

		if(decode_secret_file_extn(decInfo) == e_success)
		{
		    printf("Decoded secret file extension successfully\n");

		    if(decode_secret_file_size(decInfo) == e_success)
		    {
			printf("Decoded secret file size successfully\n");

			if(decode_secret_file_data(decInfo) == e_success)
			{
			    printf("Decoded secret file data\n");
			}
			else
			{
			    printf("Failed to encode secret data\n");
			    return e_failure;

			}


		    }
		    else
		    {
			printf("Failed to decode secret file size\n");
			return e_failure;
		    }
		}
		else
		{
		    printf("Failed to decode secret file extension\n");
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
	    printf("Failed to decode magic string\n");
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

 * FUNCTION DEFINITION: decode_data_from_image()

 ----> this is a generic function to decode character data
 */

Status decode_data_from_image(int size, DecodeInfo *decInfo)
{
    for(int i = 0; i < size; i++)							//loop till no. of character times
    {
	fread(decInfo -> image_data, 8, 1, decInfo -> fptr_stego_image);		//reading 8 bytes from stego bmp file and storing it to image_data

	decode_byte_from_lsb(decInfo -> image_data, decInfo);				//function call

	decInfo -> decoded_byte = &(decInfo -> one_byte);				//storing address of to one_byte

	fwrite(decInfo -> decoded_byte, 1, 1, decInfo -> fptr_decoded_file);		//storing 1 bytes of decoded data into decoded file
    }
    return e_success;
}



/*************************************************************************************************
 * FUNCTION DEFINITION: decode_byte_from_lsb()

 ----> this function decodes 1 byte of secret data from 8 bytes of stego image data from the LSB
 */

Status decode_byte_from_lsb(char *image_buffer, DecodeInfo *decInfo)
{
    char data = 0x00;
    for( int i = 0; i < 8; i++)
    {
	data = data << 1;
	data = data | image_buffer[i] & 0x01;			//logic to decode
    }

    decInfo -> one_byte = data;					//storing 1 byte of decoded character data to one_byte
}



/*************************************************************************************************
 * FUNCTION DEFINITION: decode_size_from_lsb()

 ----> this is a generic function to decode integer data
 ----> it decodes 4 byte of secret data from 32 bytes of stego image data into the LSB
 */

Status decode_size_from_lsb(DecodeInfo *decInfo)
{
    char str[32];										//declaring char array

    int int_data = 0x00;

    fread(str, 32, 1, decInfo -> fptr_stego_image);						//reading 32 bytes from stego bmp file and storing to str

    for(int i = 0; i < 32; i++)
    {
	int_data = int_data << 1;
	int_data = int_data | str[i] & 0x01;							//logic to decode
    }

    decInfo -> int_data = int_data;								//storing 4 bytes of decoded integer data into int_data
}
