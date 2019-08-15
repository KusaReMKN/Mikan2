#ifndef __MIKAN_DEFINE__
#define __MIKAN_DEFINE__

#include <stdio.h>

/* ä÷êîëÆê´èCè¸éå */
#define SMOWIN
#define SMOSYS
#define SMOPUIM
#define SMOGRF

/* å^íËã` */
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
/*
typedef unsigned long long QWORD;
*/

typedef BYTE FLAG8;
typedef WORD FLAG16;
typedef DWORD FLAG32;
/*
typedef QWORD FLAG64;
*/

/* For MknCol.H */
typedef struct {
	BYTE bc, fc;
} col_t;

/* MknCur.H àÀë∂ */
#define CUR_UP 'A'
#define CUR_DOWN 'B'
#define CUR_RIGHT 'C'
#define CUR_LEFT 'D'

/* MknAsm.H cursize */
#define CUR_BLOCK ((BYTE) 0)
#define CUR_BER ((BYTE) 1)
#define CUR_NONE ((BYTE) 2)

#define KEY_UP (0x48)
#define KEY_DOWN (0x50)
#define KEY_RIGHT (0x4d)
#define KEY_LEFT (0x4b)

#endif
