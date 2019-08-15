#include "MknLib.H"

SMOWIN int main(void)
{
	FILE *fp = fopen("VerInfo.Mki", "rt");
	char mknver[128], smover[128], writer[128];
	char winver[128], clkver[128], verver[128];
	char cstver[128];
	int c, om;
	BYTE a, b;
	if (fp == NULL) {
	BEGIN_SMOWIN;
		setcol(Shdwbc, Shdwfc);
		mkage(4, 3, 32, 9);
		curpos(2, 2);
		setcol(Titlebc, Titlefc);
		printf("     バージョン情報 - エラー    ");
		setcol(Winbc, Winfc);
		curpos(2, 3);
		printf("                                ");
		curpos(2, 4);
		printf("  ファイル : VerInfo.Mki        ");
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
	fgets(mknver, 128, fp);
	fgets(smover, 128, fp);
	fgets(writer, 128, fp);
	fgets(winver, 128, fp);
	fgets(clkver, 128, fp);
	fgets(verver, 128, fp);
	fgets(cstver, 128, fp);
	fclose(fp);
	*(strchr(mknver, '\n')) = '\0';
	*(strchr(smover, '\n')) = '\0';
	*(strchr(writer, '\n')) = '\0';
	*(strchr(winver, '\n')) = '\0';
	*(strchr(clkver, '\n')) = '\0';
	*(strchr(verver, '\n')) = '\0';
	*(strchr(cstver, '\n')) = '\0';
BEGIN_SMOWIN;
	setcol(Shdwbc, Shdwfc);
	mkage(4, 3, 32, 10);
	curpos(2, 2);
	setcol(Titlebc, Titlefc);
	printf("         バージョン情報         ");
	curpos(2, 3);
	setcol(Winbc, Winfc);
	printf("                                ");
cho:
	curpos(2, 4);
	printf("  %-28s  ", mknver);
	curpos(2, 5);
	printf("  %-28s  ", smover);
	curpos(2, 6);
	printf("  %-28s  ", writer);
	curpos(2, 7);
	getdosver(&a, &b);
	printf("  Dos バージョン : %2u.%2u        ", a, b);
	curpos(2, 8);
	printf("________________________________");
	curpos(2, 9);
	printf("                                ");
	curpos(2, 10);
	printf("     [> OK <]    [> 詳細 <]     ");
	curpos(2, 11);
	printf("                                ");
	sttsber("横矢印キーで選択し、 [Enter] を押してください...");
	om = 0;
	curpos(10, 10);
	curattr(!0);
	while ((c = getch()) != '\r') {
		if (c == 0x4b || c == 0x4d) {
			om = !om;
			if (om) {
				curpos(22, 10);
			}
			else {
				curpos(10, 10);
			}
		}
	}
	curattr(0);
	if (om) {
		curpos(2, 4);
		printf("  %-28s  ", winver);
		curpos(2, 5);
		printf("  %-28s  ", clkver);
		curpos(2, 6);
		printf("  %-28s  ", verver);
		curpos(2, 7);
		printf("  %-28s  ", cstver);
		curpos(2, 10);
		printf("           [> 戻る <]           ");
		sttsber("[Enter] を押してください...");
		curpos(16, 10);
		curattr(!0);
		while (getch() != '\r');
		curattr(0);
		goto cho;
	}
END_SMOWIN;
	return 0;
}
