#ifndef __MIKAN_CURSOR__
#define __MIKAN_CURSOR__

#include "MknDef.H"

SMOSYS int curpos(BYTE x, BYTE y)
{
	return printf("\x1b[%u;%uH", y, x);
}

SMOSYS int curattr(FLAG8 n)
{
	return printf("\x1b[>5%c", n ? 'l' : 'h');
}

SMOSYS int cursave(void)
{
	return printf("\x1b[s");
}

SMOSYS int currepl(void)
{
	return printf("\x1b[u");
}

SMOSYS int curgoto(BYTE to, BYTE col)
{
	return printf("\x1b[%u%c", col, to);
}

#endif
