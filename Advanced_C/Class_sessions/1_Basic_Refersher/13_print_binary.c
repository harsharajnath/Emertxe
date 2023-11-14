printf("Binary form of num is:\n");
for( int i = 0; i < 32; i++ )
{
	if ( num & (1<<(31 - i)) )
		printf("1");
	else
		printf("0");
}
printf("\n");
