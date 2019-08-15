#ifndef __MIKAN_RUN__
#define __MIKAN_RUN__

#define RUN (0xFF)

#include "MknLib.H"

typedef struct {
	BYTE Mnam[8];
	BYTE Mveri, Mverf;
	BYTE Anam[12];
	BYTE Averi, Averf;
	BYTE Onam[4];
	BYTE Overi, Overf;
	BYTE Minfo[33];   /* Reservation */
	BYTE RLXVER;
} MKX_HEAD;

const BYTE hstr[8] = {'!', 'M', 'i', 'k', 'a', 'n', '!', '\x1a'};
const BYTE RLX = 1;

int rhead(FILE *fp, MKX_HEAD *fh)
{
	fread(fh, 1, sizeof(MKX_HEAD), fp);
	if (memcmp(fh->Mnam, hstr, 8) == 0 && fh->RLXVER == RLX) {
		return 0;
	}
	return 1;
}

int whead(FILE *fp, MKX_HEAD fh)
{
	fwrite(&fh, 1, sizeof(MKX_HEAD), fp);
	return 0;
}

void mkxenc(FILE *dfp, FILE *cfp)
{
	int d, p, l = 0;
	while ((d = fgetc(dfp)) != EOF) {
		if (!l) {
			p = d;
			l++;
		} else {
			if (p == d) {
				l++;
				if (l == 255) {
					fputc(RUN, cfp);
					fputc(p, cfp);
					fputc(l, cfp);
					l ^= l;
				}
			} else {
				if (l > 3 || p == RUN) {
					fputc(RUN, cfp);
					fputc(p, cfp);
					fputc(l, cfp);
				} else {
					while (l > 0) {
						fputc(p, cfp);
						l--;
					}
				}
				p = d;
				l = 1;
			}
		}
	}
	if (l) {
		if (l > 3 || p == RUN) {
			fputc(RUN, cfp);
			fputc(p, cfp);
			fputc(l, cfp);
		} else {
			while (l > 0) {
				fputc(p, cfp);
				l--;
			}
		}
	}
	return;
}

void mkxdec(FILE *cfp, FILE *dfp)
{
	int d, l;
	while ((d = fgetc(cfp)) != EOF) {
		if (d == RUN) {
			d = getc(cfp);
			l = getc(cfp);
			while (l > 0) {
				putc(d, dfp);
				l--;
			}
		} else {
			putc(d, dfp);
		}
	}
	return;
}

char *exen2mkxn(const char *exefile, char *mkxfile)
{
	char *p;
	strcpy(mkxfile, exefile);
	p = strchr(mkxfile, '.');
	strcpy(p, ".MKX");
	return mkxfile;
}

int defhead(const char *exefile, MKX_HEAD *fh)
{
	FILE *fp = fopen("MkxInfo.Mki", "rt");
	BYTE tmp[33];
	if (fp == NULL) {
		return (-1);
	}
	memcpy(fh->Mnam, hstr, 8);
	fscanf(fp, "%d\n%d\n", &tmp[0], &tmp[1]);
	fh->Mveri = tmp[0];
	fh->Mverf = tmp[1];
	strcpy(fh->Anam, exefile);
	printf("\nAveri? > ");
	scanf("%d", &tmp[0]);
	printf("\nAverf? > ");
	scanf("%d", &tmp[1]);
	fh->Averi = tmp[0];
	fh->Averf = tmp[1];
	strcpy(fh->Onam, "DOS");
	getdosver(&tmp[0], &tmp[1]);
	fh->Overi = tmp[0];
	fh->Overf = tmp[1];
	memset(fh->Minfo, 0, 33);
	fh->RLXVER = RLX;
	fclose(fp);
	return 0;
}

SMOSYS int mkxcrt(const char *exefile)
{
	FILE *fp, *fq;
	MKX_HEAD fh;
	char mkx[13];
	
	/* File read error */
	if ((fp = fopen(exefile, "rb")) == NULL) {
		fprintf(stderr, "%s : Cannot open.", exefile);
		return (-1);
	}
	
	/* file header formater */
	if (defhead(exefile, &fh) != 0) {
		fclose(fp);
		fprintf(stderr, "Header define error");
		return (-1);
	}
	
	/* make mkx filename */
	exen2mkxn(exefile, mkx);
	if ((fq = fopen(mkx, "wb")) == NULL) {
		fprintf(stderr, "Mkx file : Cannot write");
		return (-1);
	}
	
	/* File header write */
	whead(fq, fh);
	
	/* File commpress */
	mkxenc(fp, fq);
	
	fclose(fp);
	fclose(fq);
	return 0;
}

SMOWIN int nofile(void)
{
BEGIN_SMOWIN;
	setcol(Shdwbc, Shdwfc);
	mkage(21, 8, 42, 11);
	setcol(Titlebc, Titlefc);
	curpos(19, 7);
	printf("  Mikan System - Mikan Application Error  ");
	setcol(Winbc, Winfc);
	curpos(19, 8);
	printf("                                          ");
	curpos(19, 9);
	printf("  �������s�`���t�@�C���A�Ⴕ����          ");
	curpos(19, 10);
	printf("  �ϊ������t�@�C���ɃA�N�Z�X�ł��܂���    ");
	curpos(19, 11);
	printf("                                          ");
	curpos(19, 12);
	printf("  �ϊ���Ƃ��s���܂���ł����B            ");
	curpos(19, 13);
	printf("  �A�v���P�[�V�����̎��s���~���܂��B    ");
	curpos(19, 14);
	printf("                                          ");
	curpos(19, 15);
	printf("                                          ");
	curpos(19, 16);
	printf("                                [> OK <]  ");
	curpos(19, 17);
	printf("                                          ");
	sttsber("[Enter] �������Ă�������...");
	curpos(54, 16);
	curattr(!0);
	while (getch() != '\r');
	curattr(0);
END_SMOWIN;
	return 0;
}

SMOWIN int diffver_more(void)
{
BEGIN_SMOWIN;
	setcol(Shdwbc, Shdwfc);
	mkage(21, 8, 42, 11);
	setcol(Titlebc, Titlefc);
	curpos(19, 7);
	printf("  Mikan System - Mikan Application Error  ");
	setcol(Winbc, Winfc);
	curpos(19, 8);
	printf("                                          ");
	curpos(19, 9);
	printf("  ���� Mikan Application �����s����ƁA   ");
	curpos(19, 10);
	printf("  �T�|�[�g����Ă��Ȃ� Mikan �̋@�\\��     ");
	curpos(19, 11);
	printf("  �Ăяo������AMikan �̼��т��s�����    ");
	curpos(19, 12);
	printf("  �Ȃ�A�\\���E��~���鋰�ꂪ����܂��B    ");
	curpos(19, 13);
	printf("  ���� Mikan Application ��M���ł��Ȃ�   ");
	curpos(19, 14);
	printf("  �ꍇ�͎��s���Ȃ��ł��������B            ");
	curpos(19, 15);
	printf("                                          ");
	curpos(19, 16);
	printf("                                [> OK <]  ");
	curpos(19, 17);
	printf("                                          ");
	sttsber("[Enter] �������Ă�������...");
	curpos(54, 16);
	curattr(!0);
	while (getch() != '\r');
	curattr(0);
END_SMOWIN;
	return 0;
}

SMOWIN int diffver_stop(void)
{
BEGIN_SMOWIN;
	setcol(Shdwbc, Shdwfc);
	mkage(21, 8, 42, 11);
	setcol(Titlebc, Titlefc);
	curpos(19, 7);
	printf("  Mikan System - Mikan Application Error  ");
	setcol(Winbc, Winfc);
	curpos(19, 8);
	printf("                                          ");
	curpos(19, 9);
	printf("  Mikan Application �̎��s���~���܂���  ");
	curpos(19, 10);
	printf("                                          ");
	curpos(19, 11);
	printf("                                          ");
	curpos(19, 12);
	printf("                                          ");
	curpos(19, 13);
	printf("                                          ");
	curpos(19, 14);
	printf("                                          ");
	curpos(19, 15);
	printf("                                          ");
	curpos(19, 16);
	printf("                                [> OK <]  ");
	curpos(19, 17);
	printf("                                          ");
	sttsber("[Enter] �������Ă�������...");
	curpos(54, 16);
	curattr(!0);
	while (getch() != '\r');
	curattr(0);
END_SMOWIN;
	return 0;
}

SMOWIN int diffver_main(void)
{
	int cpos, xpos, ypos;
BEGIN_SMOWIN;
repl:
	curattr(0);
	cpos = 0;
	xpos = 30;
	ypos = 16;
	setcol(Shdwbc, Shdwfc);
	mkage(21, 8, 42, 11);
	setcol(Titlebc, Titlefc);
	curpos(19, 7);
	printf("  Mikan System - Mikan Application Error  ");
	setcol(Winbc, Winfc);
	curpos(19, 8);
	printf("                                          ");
	curpos(19, 9);
	printf("  ���� Mikan Application ���v�����Ă���   ");
	curpos(19, 10);
	printf("    Mikan Version �ƁA                    ");
	curpos(19, 11);
	printf("  ���݁AMikan �� System ���񍐂��Ă���    ");
	curpos(19, 12);
	printf("    Mikan Version ���قȂ�܂��B          ");
	curpos(19, 13);
	printf("  �Ⴕ���� System �� Mikan Version ��     ");
	curpos(19, 14);
	printf("    �������ǂݎ��܂���ł����B          ");
	curpos(19, 15);
	printf("                                          ");
	curpos(19, 16);
	printf("        [> ��~ <] [> ���s <] [> �ڍ� <]  ");
	curpos(19, 17);
	printf("                                          ");
	sttsber("�����L�[�őI���A[Enter] �������Ă�������...");
	while (1) {
		curpos(xpos, ypos);
		curattr(!0);
		switch (getch()) {
		case 0x4b:	/* left */
			if (cpos != 0) {
				cpos--;
				xpos -= 11;
			}
			break;
		case 0x4d:	/* right */
			if (cpos != 2) {
				cpos++;
				xpos += 11;
			}
			break;
		case '\r':	/* Enter */
			switch (cpos) {
			case 0:	/* stop */
				diffver_stop();
				goto cend;
			case 1:	/* run */
				goto eend;
			case 2: /* more */
				diffver_more();
				goto repl;
			}
		}
		curattr(0);
	}
cend:
	curattr(0);
END_SMOWIN;
	return 1;
eend:
	curattr(0);
END_SMOWIN;
	return 0;
}

SMOSYS int mkxrun(const char *mkxfile)
{
	FILE *fp, *fq, *mkifp = fopen("MkxInfo.Mki", "rt");
	MKX_HEAD fh;
	BYTE veri, verf;
	char cmdline[256];
	char *envp;
	char envstr[256], filedir[256];
	char cd[256];
	
	setbuf(stdout, NULL);
	
	/* File read error */
	sttsber("�t�@�C�����J���Ă��܂�...");
	if ((fp = fopen(mkxfile, "rb")) == NULL) {
		nofile();
		return (-1);
	}
	
	/* File type error */
	sttsber("�t�@�C����ǂݍ���ł��܂�...");
	if (rhead(fp, &fh) != 0) {
		return (-1);
	}
	
	/* �V�X�e���o�[�W�����I�[�v�� */
	if (mkifp == NULL) {
		if (diffver_main() == 0) {
			goto runpos;
		}
		return (-1);
	}
	
	/* �o�[�W�����ǂݎ�� */
	fscanf(mkifp, "%d\n%d\n", &veri, &verf);
	fclose(mkifp);

	/* �o�[�W������r */
	if (fh.Mveri != veri || fh.Mverf > verf) {
		if (diffver_main() == 0) {
			goto runpos;
		}
		return (-1);
	}
 
runpos:	

	/* File write error */
	sttsber("�t�@�C���ɏ������ޏ��������Ă��܂�...");
	dcol();
	curpos(1, 1);
	
	/* Dos <Temp> */
	envp = getenv("TEMP");
	if (envp == NULL) {
		envp = getenv("TMP");
	}
	if (envp) {
		sprintf(envstr, envp);
		if (envstr[strlen(envstr) - 1] != '\\') {
			sprintf(envstr, "%s\\", envstr);
		}
		sprintf(filedir, "%s%s", envstr, fh.Anam);
	}
	else {
		sprintf(filedir, fh.Anam);
	}
	
	if ((fq = fopen(filedir, "wb")) == NULL) {
		nofile();
		fclose(fp);
		return (-1);
	}
	
	/* File decompress */
	sttsber("�t�@�C������ǂ��Ă��܂�...");
	mkxdec(fp, fq);
	
	sttsber("�t�@�C������Ă��܂�...");
	fclose(fp);
	fclose(fq);
	sprintf(cmdline, "LOADHIGH %s", filedir);
	
	/* Running */
	sttsber("�R�}���h�����s���Ă��܂�...");
	getcwd(cd, 0);
	system(cmdline);
	chdir(cd);
	
	sttsber("�R�}���h���I�����Ă��܂�...");
	remove(filedir);
	return 0;
}

#endif