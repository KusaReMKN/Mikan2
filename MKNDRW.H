#ifndef __MIKAN_WINDOWING__
#define __MIKAN_WINDOWING__

SMOWIN SMOSYS int mkage(BYTE x, BYTE y, BYTE xp, BYTE yp)
{
	int i, j;
	for (j = y; j < y + yp; j++) {
		curpos(x, j);
		for (i ^= i; i < xp; i++) {
			putchar('\x14');
		}
	}
	return 0;
}

SMOSYS int sttsber(char *s)
{
	int i;
	col_t cols = rcol();
	curpos(1, 24);
	setcol(Sttsbc, Sttsfc);
	for (i ^= i; i < 80; i++) {
		putchar(' ');
	}
	curpos(2, 24);
	printf(s);
	setcol(cols.bc, cols.fc);
	return 0;
}

SMOWIN int msgbox(const char *msg, const char *title)
{
	BYTE xlen = ((strlen(msg) < strlen(title)) ? strlen(title) : strlen(msg));
	BYTE ylen = 6;
	BYTE xpos = ((80 - xlen) / 2);
	BYTE ypos = ((25 - ylen) / 2);
	char fmt[32], lfmt[32];
	const char *str[] = { NULL, "", NULL, "", "[> OK <]", "", NULL };
	int i;
	str[0] = title;
	str[2] = msg;
	sprintf(fmt, " %%-%us ", xlen);
	sprintf(lfmt, " %%%us ", xlen);
BEGIN_SMOWIN;
	setcol(Shdwbc, Shdwfc);
	mkage(xpos + 2, ypos + 1, xlen + 2, ylen);
	for (i ^= i; i < 6; i++) {
		if (i == 0) {
			setcol(Titlebc, Titlefc);
		}
		else {
			setcol(Winbc, Winfc);
		}
		curpos(xpos, ypos + i);
		printf(((i == 4) ? lfmt : fmt), str[i]);
	}
	curpos(xpos + xlen - 4, ypos + 4);
	curattr(!0);
	while (getch() != '\r');
	curattr(0);
END_SMOWIN;
	return 0;
}

#endif
