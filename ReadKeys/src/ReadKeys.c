/*
 ============================================================================
 Name        : ReadKeys.c
 Author      : Frederik Bjerg
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int ReadKeys(int RawKeys)
{
	return 0;
}

void testReadKeys(void)
{
	//Testing keys only
	if ( ReadKeys(0x01)!= 0 ) { printf(" failed on 1. call"); }
			else if ( ReadKeys(0x01)!= 0 ) { printf(" failed on 2. call"); }
			else if ( ReadKeys(0x01)!= 0 ) { printf(" failed on 3. call"); }
			else if ( ReadKeys(0x01)!= 0 ) { printf(" failed on 4. call"); }
			else if ( ReadKeys(0x01)!= 0 ) { printf(" failed on 5. call"); }
			else if ( ReadKeys(0x01)!= 1 ) { printf(" failed on 6. call"); }
			else printf("passed !");
}

int main(void)
{
	puts("Testing the readkeys function ...");
	testReadKeys();
	return 0;
}
