/*


Name: Harsharaj Nath

Date of Submission: 07-08-22

Project Name:LSB Image Steganography

Description:

Steganography is the art of hiding the fact  that communication  is  taking  place, by  hiding  information  in  other  information. 
Many different carrier file formats can be used, but digital images are the most popular because of their frequency on the internet.
For hiding secret  information in images, there exists a large variety of steganography techniques some are more complex than others 
and all of them  have respective  strong  and weak points. Different applications may require  absolute  invisibility  of the secret 
information,while others require a large secret message to be hidden. This project is called LSB Steganography because we are hiding
the secret data in the Least Significant Bit (LSB) of the innocent source image.


Input CLAs:
		1. -e (for Encoding)
			2. Innocent image (BMP image file) 
			3. Secret file (TXT file)
			4. Stego image's name [Optional]
		
		1. -d (for Decoding)
			2. Stego image file
			3. Decode file's name [Optional]

Sample execution: -

Test Case 1:

./a.out -e beautiful.bmp secret.txt [stego.bmp]

Selected encoding
Read and validate encode arguments is a success
Started encoding
Open file is a success
width = 1024
height = 768
Check capacity is a success
Copied bmp header successfully
Encoded magic string successfully
Encoded extension size successfully
Encoded secret file extension successfully
Encoded secret file size successfully
Encoded secret file data
Copied remaining data
Encoding is successful

Test Case 2:

./a.out -d stego.bmp [decoded.txt]

Selected decoding
Read and validate decode arguments is a success
Started decoding
Open file is a success
Decoded magic string successfully
Decoded extension size successfully
Decoded secret file extension successfully
Decoded secret file size successfully
Decoded secret file data
Decoding is successful


Test Case 3:

./a.out

Please pass required CLAs

Test Case 4:

./a.out -s

Invalid option
Please pass
For Encoding: ./a.out -e beautiful.bmp secret.txt [stego.bmp]
For Decoding: ./a.out -d stego.bmp [decode.txt]

Test Case 5:

./a.out -e beautiful.bmp

please pass atleast 4 CLAs for encoding

Test Case 6:

./a.out -d

please pass atleast 3 CLAs for decoding


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
#include "encode.h"
#include "decode.h"
#include "types.h"
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc > 1)										//checking if more than 1 CLAs are passed
    {
	if (strcmp(argv[1], "-e") == 0)								//if encoding is selected
	{
	    if (argc < 4)									//atleast 4 CLAs should be passed
	    {
		printf("please pass atleast 4 CLAs for encoding\n");
		return -1;
	    }
	}
	else if (strcmp(argv[1], "-d") == 0)							//if decoding is selected
	{
	    if (argc < 3)									//atleast 3 CLAs should be passed
	    {
		printf("please pass atleast 3 CLAs for decoding\n");
		return -1;
	    }
	}
	else											//if any other option entered
	{
	    printf("Invalid option\nPlease pass\n");
	    printf("For Encoding: ./a.out -e beautiful.bmp secret.txt [stego.bmp]\n");
	    printf("For Decoding: ./a.out -d stego.bmp [decode.txt]\n");
	    return -1;
	}

    }
    else
    {
	printf("Please pass required CLAs\n");					//if no CLA is passed
	return -1;
    }


    if (check_operation_type(argv) == e_encode)					//checking if operation to be done is encoding
    {
	printf("Selected encoding\n");

	EncodeInfo encInfo;							//declaring variable of type struct _EncodeInfo [typedef as EncodeInfo] 

	if (read_and_validate_encode_args(argv, &encInfo) == e_success)		//checking if correct type of files are passed or not
	{
	    printf("Read and validate encode arguments is a success\n");
	    printf("Started encoding\n");

	    if(do_encoding(&encInfo) == e_success)				//perform the encoding
	    {
		printf("Encoding is successful\n");
	    }
	    else
	    {
		printf("Failed to encode\n");					//error message
		return -1;
	    }
	}
	else
	{
	    printf("Read and validate encode arguments is a failure\n");	//error message
	    return -1;
	}
    }
    else if (check_operation_type(argv) == e_decode)				//checking if operation to be done is decoding
    {
	printf("Selected decoding\n");

	DecodeInfo decInfo;

	if (read_and_validate_decode_args(argv, &decInfo) == e_success)		//checking if correct type of files are passed or not
	{
	    printf("Read and validate decode arguments is a success\n");
	    printf("Started decoding\n");

	    if(do_decoding(&decInfo) == e_success)				//perform the decoding
	    {
		printf("Decoding is successful\n");
	    }
	    else
	    {
		printf("Decoding failed\n");					//error message
		return -1;
	    }
	}
	else
	{
	    printf("Read and validate encode arguments is a failure\n");	//error message
	    return -1;
	}
    }

    return 0;
}

OperationType check_operation_type(char *argv[])				//function definition of check_operation_type()
{
    if (strcmp(argv[1], "-e") == 0)
	return e_encode;

    else if (strcmp(argv[1], "-d") == 0)
	return e_decode;

    else
	return e_unsupported;
}
