#include "MknLib.H"

int main(void)
{
	char setupdir[256];
	char cmdlin[256];
	setbuf(stdout, NULL);
	puts("�����Z�b�g�A�b�v Version 1. 10.\n");
	puts("�������C���X�g�[������f�B���N�g������͂��Ă��������B");
	printf(">");
	fgets(setupdir, 256, stdin);
	*(strchr(setupdir, '\n')) = '\0';
	puts("�������C���X�g�[�����Ă��܂�...");
	printf("�f�B���N�g�����m�F��...\n");
	sprintf(cmdlin, "MKDIR %s > NUL", setupdir);
	system(cmdlin);
	printf("�����B\n�t�@�C�����R�s�[��...\n");
	printf("Mikan System\r");
	sprintf(cmdlin, "COPY MIKAN.EXE %s > NUL", setupdir);
	system(cmdlin);
	printf("Mikan Application Programs\r");
	sprintf(cmdlin, "COPY *.MKX %s > NUL", setupdir);
	system(cmdlin);
	printf("Mikan Configuration Files\r");
	sprintf(cmdlin, "COPY *.MKI %s > NUL", setupdir);
	system(cmdlin);
	printf("Mikan Logo File\r");
	sprintf(cmdlin, "COPY *.PIX %s > NUL", setupdir);
	system(cmdlin);
	printf("Read Me\r");
	sprintf(cmdlin, "COPY MKNSMO.TXT %s > NUL", setupdir);
	system(cmdlin);
	printf("�����B\n");
	puts("�Z�b�g�A�b�v�͊������܂����B");
	puts("�����̃f�B���N�g����");
	puts(setupdir);
	puts("�ł��B");
	chdir(setupdir);
	return 0;
}