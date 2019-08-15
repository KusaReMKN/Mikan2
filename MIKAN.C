#include "MknLib.H"

SMOPUIM int main(void)
{
BEGIN_SMOPUIM;
	/* ステータスバーにメッセージ表示 */
	sttsber("Mikan を起動しています...");
	/* シェル呼び出し */
	mkxrun("MknWin.Mkx");
END_SMOPUIM;
	return 0;
}
