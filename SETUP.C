#include "MknLib.H"

int main(void)
{
	char setupdir[256];
	char cmdlin[256];
	setbuf(stdout, NULL);
	puts("蜜柑セットアップ Version 1. 10.\n");
	puts("蜜柑をインストールするディレクトリを入力してください。");
	printf(">");
	fgets(setupdir, 256, stdin);
	*(strchr(setupdir, '\n')) = '\0';
	puts("蜜柑をインストールしています...");
	printf("ディレクトリを確認中...\n");
	sprintf(cmdlin, "MKDIR %s > NUL", setupdir);
	system(cmdlin);
	printf("完了。\nファイルをコピー中...\n");
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
	printf("完了。\n");
	puts("セットアップは完了しました。");
	puts("蜜柑のディレクトリは");
	puts(setupdir);
	puts("です。");
	chdir(setupdir);
	return 0;
}
