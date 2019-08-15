#ifndef __MIKAN_SETUP__
#define __MIKAN_SETUP__

#include "MknLib.H"

#define BEGIN_SMOWIN begin_smowin()
#define BEGIN_SMOWIN_HYBRID begin_smowin_hybrid()
#define END_SMOWIN end_smowin()
#define BEGIN_SMOPUIM begin_smopuim()
#define END_SMOPUIM retdos()

/* in MknDrW.H */
SMOWIN SMOSYS int mkage(BYTE, BYTE, BYTE, BYTE);

SMOSYS int chkrun(void)
{
	FILE *fp = fopen("Running.mkn", "rb");
	if (fp != NULL) {
		puts("Mikan は既に実行されています。");
		puts("Mikan に戻るには EXIT と入力して [Enter] を押してください。");
		fclose(fp);
		return (-1);
	}
	if (fp = fopen("Running.mkn", "wb")) {
		putc(0, fp);
		fclose(fp);
	}
	else {
		puts("Mikan の起動情報を正しく報告できませんでした。");
		printf("何かキーを押すと続行します...");
		getch();
	}
	return 0;
}

SMOSYS int endrun(void)
{
	remove("Running.mkn");
	return 0;
}

SMOSYS int waitfor(clock_t c)
{
	clock_t a = clock();
	while (clock() - a < c);
	return 0;
}

SMOSYS int putlogo()
{
	mikan_logo();
	return 0;
}

SMOSYS int smo_set_read_color(FILE *fp)
{
	char buf[256];
	if (fp == NULL) {
		Titlebc = 3;
		Titlefc = 15;
		Winbc = 7;
		Winfc = 0;
		Sttsbc = 3;
		Sttsfc = 0;
		BGbc = 3;
		BGfc = 11;
		Shdwbc = 3;
		Shdwfc = 9;
		return 1;
	}
	fgets(buf, 256, fp);
	Titlebc = atoi(buf);
	fgets(buf, 256, fp);
	Titlefc = atoi(buf);
	fgets(buf, 256, fp);
	Winbc = atoi(buf);
	fgets(buf, 256, fp);
	Winfc = atoi(buf);
	fgets(buf, 256, fp);
	Sttsbc = atoi(buf);
	fgets(buf, 256, fp);
	Sttsfc = atoi(buf);
	fgets(buf, 256, fp);
	BGbc = atoi(buf);
	fgets(buf, 256, fp);
	BGfc = atoi(buf);
	fgets(buf, 256, fp);
	Shdwbc = atoi(buf);
	fgets(buf, 256, fp);
	Shdwfc = atoi(buf);
	return 0;
}

SMOSYS int begin_smowin(void)
{
	FILE *fp = fopen("ColInfo.Mki", "rt");
	svscr();
	setbuf(stdout, NULL);
	if (smo_set_read_color(fp)) {
		fclose(fp);
	}
	curattr(0);
	return 0;
}

SMOSYS int reset(void)
{
	return 0;
}

SMOSYS int dispver(void)
{
	FILE *fp = fopen("VerInfo.Mki", "rt");
	char buf[256];
	if (fp == NULL) {
		puts("Mikan\nCopr. (C) 2016 五十\嵐 宗介");
		return 0;
	}
	fgets(buf, 256, fp);
	printf(buf);
	fgets(buf, 256, fp);
	printf(buf);
	fgets(buf, 256, fp);
	printf(buf);
	fclose(fp);
	return 0;	
}

SMOSYS int retdos(void)
{
	dcol();
	clscr();
	ldscr();
	currepl();
	endrun();
	cls(0);
	cursize(CUR_BER);
	curattr(!0);
	return 0;
}

SMOSYS int begin_smopuim(void)
{
	int i;
	FILE *fp = fopen("ColInfo.Mki", "rt");
	setbuf(stdout, NULL);
	if (chkrun()) {
		exit(0);
	}
	dispver();
	curattr(0);
	cursave();
	svscr();
	putlogo();
	cursize(CUR_BLOCK);
	curattr(0);
	if (smo_set_read_color(fp)) {
		fclose(fp);
	}
	curpos(1, 1);
	setcol(BGbc, BGfc);
	mkage(1, 1, 80, 23);
	setcol(Sttsbc, Sttsbc);
	mkage(1, 24, 80, 1);
	return 0;
}

SMOSYS int begin_smowin_hybrid(void)
{
	setbuf(stdout, NULL);
	curattr(0);
	svscr();
	return 0;
}

SMOSYS int end_smowin(void)
{
	curattr(0);
	ldscr();
	return 0;
}

#endif
