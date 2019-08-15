#include "mknlib.h"

SMOWIN int main(void)
{
BEGIN_SMOWIN;
	msgbox("ChaOS は全画面表\示を使用します。", "ChaOS for Mikan System");
	dcol();
	clscr();
	puts("\n\n終了して Mikan に戻るには、Exit と入力し [Enter] キーを押してください。\n");
	curattr(!0);
	cursize(CUR_BER);
	system("COMMAND.COM");
	cursize(CUR_BLOCK);
	curattr(0);
END_SMOWIN;
	return 0;
}
