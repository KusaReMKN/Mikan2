#include "MknLib.H"

SMOWIN int nokeyerror(void);

SMOWIN int main(void)
{
	int c;
	int cpos;
	int xp, yp;
BEGIN_SMOWIN;
	xp = 23;
	yp = 8;
	cpos = 1;
	setcol(Shdwbc, Shdwfc);
	mkage(23, 7, 38, 8); 
	curpos(21, 6);
	setcol(Titlebc, Titlefc);
	printf("        Mikan スタートメニュー        ");
	curpos(21, 7);
	setcol(Winbc, Winfc);
	printf("                                      ");
	curpos(21, 8);
	printf("  Mikan バージョン表\示                ");
	curpos(21, 9);
	printf("  Mikan 現在時刻表\示                  ");
	curpos(21, 10);
	printf("  Mikan 表\示色設定                    ");
	curpos(21, 11);
	printf("  ChaOS for Mikan System              ");
	curpos(21, 12);
	printf("  Mikan 終了                          ");
	curpos(21, 13);
	printf("                                      ");
rep:
	sttsber("起動するアプリケーションを選択してください...");
	while (1) {
		curpos(xp, yp);
		curattr(!0);
		c = getch();
		curattr(0);
		switch (c) {
		case '\r':
			switch (cpos) {
			case 1: /* Ver */
				mkxrun("MknVer.Mkx");
				goto repos;
			case 2:	/* Clock */
				mkxrun("MknClk.Mkx");
				goto repos;
			case 3:	/* Color */
				mkxrun("MknCst.Mkx");
				goto repos;
			case 5:	/* Quit */
				goto endp;
			case 4: /* ChaOS */
				mkxrun("MknKos.Mkx");
				goto repos;
			}
			break;
		case 0x48:	/* Up */
			if (cpos != 1) {
				cpos--;
				yp--;
			}
			break;
		case 0x50: /* Down */
			if (cpos != 5) {
				cpos++;
				yp++;
			}
		}
	}
repos:
	reset();
	goto rep;
endp:
END_SMOWIN;
	return 0;
}
