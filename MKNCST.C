#include "MknLib.H"

int ewrite(void);
col_t input(char *);
BYTE c2x(char);

SMOWIN int main(int argc, char *argv[])
{
	FILE *fp = fopen("VerInfo.Mki", "rt+");
	FILE *tp = tmpfile();
	char buf[256];
	int cpos;
	int xp, yp;
	col_t col;
	clock_t a;
	cpos = 0;
	xp = 10;
	yp = 11;
	if (fp == NULL) {
	BEGIN_SMOWIN;
		setcol(Shdwbc, Shdwfc);
		mkage(4, 3, 32, 9);
		curpos(2, 2);
		setcol(Titlebc, Titlefc);
		printf("       表\示色設定  エラー       ");
		setcol(Winbc, Winfc);
		curpos(2, 3);
		printf("                                ");
		curpos(2, 4);
		printf("  ファイル : ColInfo.Mki        ");
		curpos(2, 5);
		printf("  エラーナンバー : 1 (ENOENT)   ");
		curpos(2, 6);
		printf("  詳細 :                        ");
		curpos(2, 7);
		printf("  No such file or directory     ");
		curpos(2, 8);
		printf("                                ");
		curpos(2, 9);
		printf("            [> OK <]            ");
		curpos(2, 10);
		printf("                                ");
		sttsber("[Enter] を押してください...");
		curpos(17, 9);
		curattr(!0);
		while (getch() != '\r');
		curattr(0);
	END_SMOWIN;
		return -1;
	}
	fclose(fp);
BEGIN_SMOWIN;
	setcol(Shdwbc, Shdwfc);
	mkage(4, 3, 32, 11);
	curpos(2, 2);
	setcol(Titlebc, Titlefc);
	printf("           表\示色設定           ");
rep:
	curpos(2, 3);
	setcol(Winbc, Winfc);
	printf("                                ");
	curpos(2, 4);
	printf("  ウィンドウタイトル    :   %01x%01x  ", Titlebc, Titlefc);
	curpos(2, 5);
	printf("  ウィンドウ            :   %01x%01x  ", Winbc, Winfc);
	curpos(2, 6);
	printf("  ステータスバー        :   %01x%01x  ", Sttsbc, Sttsfc);
	curpos(2, 7);
	printf("  システム背景          :   %01x%01x  ", BGbc, BGfc);
	curpos(2, 8);
	printf("  ウィンドウの影        :   %01x%01x  ", Shdwbc, Shdwfc);
	curpos(2, 9);
	printf("________________________________");
	curpos(2, 10);
	printf("                                ");
	curpos(2, 11);
	printf("     [> OK <]  [> Cancel <]     ");
	curpos(2, 12);
	printf("                                ");
	sttsber("上下矢印キーでメニューを選択、[Enter] で変更できます...");
	while (1) {
		curattr(!0);
		curpos(xp, yp);
		switch (getch()) {
		case '\r':
			switch (cpos) {
			case 0:	/* OK */
				goto oend;
			case (-1):	/* Cancel */
				goto cend;
			case 1:	/* Title Col. */
				col = input("ウィンドウタイトル");
				if (col.bc != ((BYTE) (-1))) { Titlebc = col.bc; }
				if (col.fc != ((BYTE) (-1))) { Titlefc = col.fc; }
				goto rep;
			case 2:	/* Window Col. */
				col = input("ウィンドウ");
				if (col.bc != ((BYTE) (-1))) { Winbc = col.bc; }
				if (col.fc != ((BYTE) (-1))) { Winfc = col.fc; }
				goto rep;
			case 3: /* Status Col. */
				col = input("ステータスバー");
				if (col.bc != ((BYTE) (-1))) { Sttsbc = col.bc; }
				if (col.fc != ((BYTE) (-1))) { Sttsfc = col.fc; }
				goto rep;
			case 4:	/* BackGr. Col. */
				col = input("システム背景");
				if (col.bc != ((BYTE) (-1))) { BGbc = col.bc; }
				if (col.fc != ((BYTE) (-1))) { BGfc = col.fc; }
				goto rep;
			case 5:	/* Shadow Col. */
				col = input("ウィンドウの影");
				if (col.bc != ((BYTE) (-1))) { Shdwbc = col.bc; }
				if (col.bc != ((BYTE) (-1))) { Shdwfc = col.fc; }
				goto rep;
			}
		case 0x48:	/* Up */
			if (cpos != 1 && cpos != ((BYTE) (-1)) && cpos != 0) {
				cpos--;
				yp--;
			}
			else if (cpos == (-1) || cpos == 0) {
				cpos = 5;
				xp = 4;
				yp = 8;
			}
			break;
		case 0x50:	/* Down */
			if (cpos != 5 && cpos != (-1) && cpos != 0) {
				cpos++;
				yp++;
			}
			else if (cpos == 5) {
				cpos = 0;
				xp = 10;
				yp = 11;
			}
			break;
		case 0x4d:	/* Right */
			if (cpos == 0) {
				cpos = (-1);
				xp = 20;
			}
			break;
		case 0x4b:	/* Left */
			if (cpos == (-1)) {
				cpos = 0;
				xp = 10;
			}
		} /* switch - getch() */
		curattr(0);
	} /* while - 1 */
oend:
	curattr(0);
	dcol();
	curpos(1, 1);
	if ((fp = fopen("ColInfo.Mki", "wt")) == NULL) {
		ewrite();
		goto cend;
	}
	fprintf(fp, "%d\n%d\n", Titlebc, Titlefc);
	fprintf(fp, "%d\n%d\n", Winbc, Winfc);
	fprintf(fp, "%d\n%d\n", Sttsbc, Sttsfc);
	fprintf(fp, "%d\n%d\n", BGbc, BGfc);
	fprintf(fp, "%d\n%d\n", Shdwbc, Shdwfc);
	fclose(fp);
	setcol(Shdwbc, Shdwfc);
	mkage(28, 10, 28, 5);
	setcol(Titlebc, Titlefc);
	curpos(26, 9);
	a = clock();
	printf("     表\示色設定    警告     ");
	curpos(26, 10);
	setcol(Winbc, Winfc);
	printf("                            ");
	curpos(26, 11);
	printf("   設定を有効にするために   ");
	curpos(26, 12);
	printf(" Mikan を再起動してください ");
	curpos(26, 13);
	printf("                            ");
	curattr(0);
	while (clock() - a < 2000);
cend:
END_SMOWIN;
	return 0;
} /* main */

col_t input(char *str)
{
	int c, i;
	col_t col;
	char buf[4];
BEGIN_SMOWIN_HYBRID;
	setcol(Shdwbc, Shdwfc);
	mkage(7, 5, 24, 5);
	curpos(5, 4);
	setcol(Titlebc, Titlefc);
	printf(" 表\示色設定  コード入力 ");
	curpos(5, 5);
	setcol(Winbc, Winfc);
	printf("                        ");
	curpos(5, 6);
	printf(" %-22s ", str);
	curpos(5, 7);
	printf("          [  ]          ");
	curpos(5, 8);
	printf("                        ");
	sttsber("新しい色コードを入力してください。[Enter] は不要です。[Esc] で前に戻ります...");
	curpos(16, 7);
	curattr(!0);
	i = 0;
	while (i != 2) {
		c = getch();
		if (isxdigit(c)) {
			buf[i++] = (char) c;
			putchar(c);
		}
		else if (c == '\b') {
			if (i > 0) {
				i--; 
				printf("\b \b");
			}
		}
		else if (c == '\x1b') {
			col.bc = ((BYTE) (-1));
			col.fc = ((BYTE) (-1));
		END_SMOWIN;
			return col;
		}
	}
	buf[i] = '\0';
	col.bc = c2x(buf[0]);
	col.fc = c2x(buf[1]);
END_SMOWIN;
	return col;
}

int ewrite(void)
{
	clock_t a = clock();
BEGIN_SMOWIN;
	setcol(Shdwbc, Shdwfc);
	mkage(7, 5, 24, 4);
	curpos(5, 4);
	setcol(Titlebc, Titlefc);
	printf("   表\示色設定  エラー   ");
	curpos(5, 5);
	setcol(Winbc, Winfc);
	printf("                        ");
	curpos(5, 6);
	printf("  ファイル書込みエラー  ");
	curpos(5, 7);
	printf("                        ");
	while (clock() - a < 5000);
END_SMOWIN;
	return 0;
}

BYTE c2x(char c)
{
	const char buf[] = "0123456789ABCDEF";
	const char sml[] = "0123456789abcdef";
	int i;
	for (i ^= i; i < 16; i++) {
		if (buf[i] == c) return i;
		if (sml[i] == c) return i;
	}
	return ((BYTE) (-1));
}
