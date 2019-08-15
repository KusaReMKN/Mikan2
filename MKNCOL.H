#ifndef __MIKAN_COLOR__
#define __MIKAN_COLOR__

#include "MknDef.H"

BYTE nb, nf;
BYTE Titlebc, Titlefc;
BYTE Winbc, Winfc;
BYTE Sttsbc, Sttsfc;
BYTE BGbc, BGfc;
BYTE Shdwbc, Shdwfc;

SMOSYS int bcol(BYTE bc)
{
	return (nb = bc, printf("\x1b[4%um", bc & 7));
}

SMOSYS int fcol(BYTE fc)
{
	return (nf = fc, printf("\x1b[3%u%sm", fc & 7, fc & 8 ? ";1": ""));
}

SMOSYS int dcol(void)
{
	return printf("\x1b[0m");
}

SMOSYS int setcol(BYTE bc, BYTE fc)
{
	return dcol() + bcol(bc) + fcol(fc);
}

SMOSYS col_t rcol(void)
{
	col_t col;
	col.bc = nb;
	col.fc = nf;
	return col;
}

#endif
