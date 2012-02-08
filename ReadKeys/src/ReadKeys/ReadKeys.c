/*
 * ReadKeys.c
 *
 *  Created on: 08/02/2012
 *      Author: Akida Tai Sakurano
 */

#include "ReadKeys.h"

int ReadKeys(int RawKeys)
{
	static int key_count[MAXbit-1] = { 0,0,0,0,0,0,0,0 };

	int loop_counter;

	for (loop_counter=0; loop_counter<MAXbit; loop_counter++)
	{
		if( RawKeys & (1 << loop_counter))
		{
			key_count[ loop_counter ] = key_count[ loop_counter ]+1;
		}
		else
		{
			key_count[ loop_counter ] = 0;
		}
	}

	for (loop_counter=0; loop_counter<MAXbit; loop_counter++)
	{
		if (key_count[ loop_counter ] > 5)
		{
			key_count[ loop_counter ] = 0;
			return loop_counter;
		}
	}
	return NO_EVENT;
}
