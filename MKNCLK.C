#include "MknLib.H"

SMOWIN int main(void)
{
	time_t *tp, *tq;
	char tstr[256];
	int c = 0;
	time(tp);
	strcpy(tstr, ctime(tp));
	*(strchr(tstr, '\n')) = '\0';
BEGIN_SMOWIN;
	setcol(Shdwbc, Shdwfc);
	mkage(51, 16, 28, 7);
	setcol(Titlebc, Titlefc);
	curpos(49, 15);
	printf("          Œ»ÝŽž          ");
	setcol(Winbc, Winfc);
	curpos(49, 16);
	printf("                            ");
	curpos(49, 17);
	printf("  %24s  ", tstr);
	curpos(49, 18);
	printf("____________________________");
	curpos(49, 19);
	printf("                            ");
	curpos(49, 20);
	printf("          [> OK <]          ");
	curpos(49, 21);
	printf("                            ");
	sttsber("[Enter] ‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢...");
rewait:
	curpos(62, 20);
	curattr(!0);
	do {
		if (!kbhit()) {
			time(tq);
			if (*tp != *tq) {
				*tp = *tq;
				strcpy(tstr, ctime(tp));
				*(strchr(tstr, '\n')) = '\0';
				curattr(0);
				curpos(49, 17);
				printf("  %24s  ", tstr);
				goto rewait;
			}
		}
		else {
			c = getch();
		}
	} while (c != '\r');
	curattr(0);
END_SMOWIN;
	return 0;
}
