#ifndef __MIKAN_SCREEN__
#define __MIKAN_SCREEN__

#include "MknDef.H"

SMOSYS int clscr(void)
{
	return printf("\x1b[2J");
}

SMOSYS int cls(BYTE n)
{
	return printf("\x1b[%uJ", n);
}

SMOSYS int prscr(BYTE bc)
{
	return printf("\x1b[4%um\x1b[2J", bc & 7);
}

SMOSYS int cllin(BYTE n)
{
	return printf("\x1b[%uK", n);
}

WORD tmpscr[8][1920];
BYTE scrnum = 0;

SMOSYS int svscr(void)
{
	BYTE x, y;
	if (scrnum == 7) {
		return (-1);
	}
	for (y = 0; y < 24; y++) {
		for (x = 0; x < 80; x++) {
			tmpscr[scrnum][(y * 80) + x] = retchr(x + 1, y + 1);
		}
	}
	scrnum++;
	return 0;
}

SMOSYS int ldscr(void)
{
	BYTE x, y;
	if (scrnum == 0) {
		return (-1);
	}
	scrnum--;
	dcol();
	curpos(1, 1);
	for (y = 0; y < 24; y++) {
		for (x = 0; x < 80; x++) {
			setchr(x + 1, y + 1, tmpscr[scrnum][(y * 80) + x]);
		}
	}
	return 0;
}

#endif
