#ifndef __MIKAN_ASSEMBLY__
#define __MIKAN_ASSEMBLY__

#pragma asm

SMOSYS int getdosver(BYTE *n, BYTE *f)
{
	BYTE a, b;
	__asm {
		MOV AX, 3000h;
		INT 21h;
		MOV a, AL;
		MOV b, AH;
	}
	*n = a;
	*f = b;
	return 0;
}

SMOSYS int cursize(BYTE curtype)
{
	WORD curnum;
	switch (curtype) {
	case CUR_BLOCK:
		curnum = 0x0007;
		break;
	case CUR_BER:
		curnum = 0x0607;
		break;
	case CUR_NONE:
		curnum = 0x2000;
		break;
	}
	__asm {
		mov ah, 01h;
		mov cx, curnum;
		int 10h;
	}
	return 0;
}

#undef putchar

SMOSYS int putchar(int __c)
{
	BYTE c = ((BYTE) __c);
	__asm {
		mov ah, 02h;
		mov dl, c;
		int 21h;
	}
	return c;
}

SMOSYS WORD retcur(void)
{
	WORD retw;
	__asm {
		mov ah, 03h;
		mov bh, 03h;
		int 10h;
		mov retw, dx;
	}
	return retw;
}

SMOSYS WORD setchr(BYTE xpos, BYTE ypos, WORD retw)
{
	WORD orgpos = retcur();
	BYTE chr = ((BYTE) (retw & 0xFF));
	BYTE att = ((BYTE) (retw >> 8));
	xpos--;
	ypos--;
	__asm {
		mov ah, 02h;
		mov bh, 03h;
		mov dh, ypos;
		mov dl, xpos;
		int 10h;
		mov ah, 09h
		mov al, chr;
		mov bh, 03h;
		mov bl, att;
		mov cx, 0001h;
		int 10h;
		mov ah, 02h;
		mov bh, 03h;
		mov dx, orgpos;
		int 10h;
	}
	return 0;
}

SMOSYS WORD retchr(BYTE xpos, BYTE ypos)
{
	WORD orgpos = retcur();
	WORD retw;
	xpos--;
	ypos--;
	__asm {
		mov ah, 02h;
		mov bh, 03h;
		mov dh, ypos;
		mov dl, xpos;
		int 10h;
		mov ah, 08h;
		mov bh, 03h;
		int 10h;
		mov retw, ax;
		mov ah, 02h;
		mov bh, 03h;
		mov dx, orgpos;
		int 10h;
	}
	return retw;
}

#endif
