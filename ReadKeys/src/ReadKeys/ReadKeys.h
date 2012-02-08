/*
 * ReadKeys.h
 *
 *  Created on: 08/02/2012
 *      Author: Akida Tai Sakurano
 */

#ifndef READKEYS_H_
#define READKEYS_H_

enum bitNumbers { KEY0bit, KEY1bit, KEY2bit, KEY3bit, KEY4bit, KEY5bit, KEY6bit, KEY7bit, MAXbit };
enum events { KEY0_EVENT, KEY1_EVENT, KEY2_EVENT, KEY3_EVENT, KEY4_EVENT,NO_EVENT};

int ReadKeys(int RawKeys);

#endif /* READKEYS_H_ */
