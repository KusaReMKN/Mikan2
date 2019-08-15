#ifndef __MIKAN_GRAPHIC__
#define __MIKAN_GRAPHIC__

struct Pixel {
	WORD Color;
	WORD X;
	WORD Y;
};

short orgX, orgY;

SMOSYS int waitfor(clock_t);

SMOGRF int text_logo(void)
{
	return 0;
}

SMOGRF int putblock(short x, short y, short bx, short by)
{
	int iy, jx;
	for (iy ^= iy; iy < by; iy++) {
		for (jx ^= jx; jx < bx; jx++) {
			_setpixel(orgX + x + jx, orgY + y + iy);
		}
	}
	return 0;
}

SMOGRF int mikan_logo(void)
{
	int i;
	struct Pixel pix;
	WORD k, j;
	FILE *fp;
	if (!_setvideomode(_MAXRESMODE)) {
		text_logo();
		goto end;
	}
	
#if 0
	_setcolor(6);
	
	for (i ^= i; i < 4; i++) {
		/* M */
		orgX = 100 - i;
		orgY = 36 - i;
		putblock(0, 0, 16, 56);
		putblock(16, 8, 8, 24);
		putblock(24, 16, 8, 24);
		putblock(32, 8, 8, 24);
		putblock(40, 0, 16, 56);
		/* I */
		orgX += 64;
		putblock(0, 0, 48, 8);
		putblock(16, 8, 16, 40);
		putblock(0, 48, 48, 8);
		/* K */
		orgX += 64;
		putblock(0, 0, 16, 56);
		putblock(16, 24, 16, 16);
		putblock(24, 16, 16, 8);
		putblock(32, 8, 16, 8);
		putblock(40, 0, 16, 8);
		putblock(24, 32, 16, 16);
		putblock(32, 40, 16, 16);
		putblock(48, 48, 8, 8);
		
		/* A */
		orgX += 64;
		putblock(0, 16, 16, 40);
		putblock(16, 0, 24, 8);
		putblock(8, 8, 16, 8);
		putblock(32, 8, 16, 8);
		putblock(40, 16, 16, 40);
		putblock(16, 32, 24, 8);
		
		/* N */
		orgX += 64;
		putblock(0, 0, 16, 56);
		putblock(16, 8, 8, 24);
		putblock(24, 16, 8, 24);
		putblock(32, 24, 8, 24);
		putblock(40, 0, 16, 56);
		
		/* [SP] */
		orgX += 64;
		
		/* 2 */
		orgX += 64;
		putblock(8, 0, 40, 8);
		putblock(0, 8, 16, 8);
		putblock(40, 8, 16, 16);
		putblock(32, 16, 8, 8);
		putblock(16, 24, 24, 16);
		putblock(8, 32, 8, 8);
		putblock(0, 40, 24, 16);
		putblock(24, 48, 32, 8);
		putblock(40, 24, 8, 8);
	}
	
	_setcolor(14);
	
	/* M */
	orgX = 96;
	orgY = 32;
	putblock(0, 0, 16, 56);
	putblock(16, 8, 8, 24);
	putblock(24, 16, 8, 24);
	putblock(32, 8, 8, 24);
	putblock(40, 0, 16, 56);
	/* I */
	orgX += 64;
	putblock(0, 0, 48, 8);
	putblock(16, 8, 16, 40);
	putblock(0, 48, 48, 8);
	/* K */
	orgX += 64;
	putblock(0, 0, 16, 56);
	putblock(16, 24, 16, 16);
	putblock(24, 16, 16, 8);
	putblock(32, 8, 16, 8);
	putblock(40, 0, 16, 8);
	putblock(24, 32, 16, 16);
	putblock(32, 40, 16, 16);
	putblock(48, 48, 8, 8);
	
	/* A */
	orgX += 64;
	putblock(0, 16, 16, 40);
	putblock(16, 0, 24, 8);
	putblock(8, 8, 16, 8);
	putblock(32, 8, 16, 8);
	putblock(40, 16, 16, 40);
	putblock(16, 32, 24, 8);
	
	/* N */
	orgX += 64;
	putblock(0, 0, 16, 56);
	putblock(16, 8, 8, 24);
	putblock(24, 16, 8, 24);
	putblock(32, 24, 8, 24);
	putblock(40, 0, 16, 56);
	
	/* [SP] */
	orgX += 64;
	
	/* 2 */
	orgX += 64;
	putblock(8, 0, 40, 8);
	putblock(0, 8, 16, 8);
	putblock(40, 8, 16, 16);
	putblock(32, 16, 8, 8);
	putblock(16, 24, 24, 16);
	putblock(8, 32, 8, 8);
	putblock(0, 40, 24, 16);
	putblock(24, 48, 32, 8);
	putblock(40, 24, 8, 8);
	
	/* [sp] */
	orgX = 256;
	orgY += 96;
	
	/* S */
	orgX += 16;
	putblock(2, 0, 8, 2);
	putblock(0, 2, 4, 4);
	putblock(8, 2, 4, 2);
	putblock(2, 6, 10, 2);
	putblock(10, 8, 4, 4);
	putblock(0, 10, 4, 2);
	putblock(2, 12, 10, 2);
	
	/* M */
	orgX += 16;
	putblock(0, 0, 4, 14);
	putblock(4, 2, 2, 6);
	putblock(6, 4, 2, 6);
	putblock(8, 2, 2, 6);
	putblock(10, 0, 4, 14);
	
	/* O */
	orgX += 16;
	putblock(2, 0, 10, 2);
	putblock(0, 2, 4, 10);
	putblock(10, 2, 4, 10);
	putblock(2, 12, 10, 2);
	
	/* P */
	orgX += 16;
	putblock(0, 0, 4, 14);
	putblock(0, 0, 12, 2);
	putblock(10, 2, 4, 6);
	putblock(0, 8, 12, 2);
	
	/* U */
	orgX += 16;
	putblock(0, 0, 4, 12);
	putblock(10, 0, 4, 12);
	putblock(2, 12, 10, 2);
	
	/* I */
	orgX += 16;
	putblock(0, 0, 12, 2);
	putblock(0, 12, 12, 2);
	putblock(4, 0, 4, 14);
	
	/* M */
	orgX += 16;
	putblock(0, 0, 4, 14);
	putblock(4, 2, 2, 6);
	putblock(6, 4, 2, 6);
	putblock(8, 2, 2, 6);
	putblock(10, 0, 4, 14);
	
	/* [SP] */
	orgX += 16;
	
	/* V */
	orgX += 16;
	putblock(0, 0, 4, 8);
	putblock(10, 0, 4, 8);
	putblock(2, 8, 4, 2);
	putblock(8, 8, 4, 2);
	putblock(4, 10, 6, 2);
	putblock(6, 12, 2, 2);
	
	/* E */
	orgX += 16;
	putblock(0, 0, 4, 14);
	putblock(0, 0, 14, 2);
	putblock(0, 6, 12 ,2);
	putblock(0, 12, 14, 2);
	
	/* R */
	orgX += 16;
	putblock(0, 0, 4, 14);
	putblock(0, 0, 12, 2);
	putblock(0, 8, 10, 2);
	putblock(6, 10, 6, 2);
	putblock(8, 12, 6, 2);
	putblock(10, 2, 4, 6);
	putblock(8, 6, 2, 2);
	
	/* S */
	orgX += 16;
	putblock(2, 0, 8, 2);
	putblock(0, 2, 4, 4);
	putblock(8, 2, 4, 2);
	putblock(2, 6, 10, 2);
	putblock(10, 8, 4, 4);
	putblock(0, 10, 4, 2);
	putblock(2, 12, 10, 2);
	
	/* I */
	orgX += 16;
	putblock(0, 0, 12, 2);
	putblock(0, 12, 12, 2);
	putblock(4, 0, 4, 14);
	
	/* O */
	orgX += 16;
	putblock(2, 0, 10, 2);
	putblock(0, 2, 4, 10);
	putblock(10, 2, 4, 10);
	putblock(2, 12, 10, 2);
	
	/* N */
	orgX += 16;
	putblock(0, 0, 4, 14);
	putblock(4, 2, 2, 6);
	putblock(6, 4, 2, 6);
	putblock(8, 6, 2, 6);
	putblock(10, 0, 4, 14);
	
	/* [SP] */
	orgX += 16;
	
	/* 4 */
	orgX += 16;
	putblock(8, 0, 4, 14);
	putblock(6, 0, 2, 4);
	putblock(4, 2, 2, 4);
	putblock(2, 4, 2, 2);
	putblock(0, 6, 4, 4);
	putblock(0, 8, 14, 2);
	
	/* . */
	orgX += 16;
	putblock(4, 10, 4, 4);
	
	/* 0 */
	orgX += 16;
	putblock(4, 0, 6, 2);
	putblock(2, 2, 2, 2);
	putblock(8, 2, 4, 2);
	putblock(0, 4, 4, 6);
	putblock(10, 4, 4, 6);
	putblock(2, 10, 4, 2);
	putblock(10, 10, 2, 2);
	putblock(4, 12, 6, 2);
	
	/* 0 */
	orgX += 16;
	putblock(4, 0, 6, 2);
	putblock(2, 2, 2, 2);
	putblock(8, 2, 4, 2);
	putblock(0, 4, 4, 6);
	putblock(10, 4, 4, 6);
	putblock(2, 10, 4, 2);
	putblock(10, 10, 2, 2);
	putblock(4, 12, 6, 2);
	
	/* . */
	orgX += 16;
	putblock(4, 10, 4, 4);
	
	/* C */
	orgY += 32;
	orgX -= 256;
	putblock(1, 0, 5, 1);
	putblock(0, 1, 2, 5);
	putblock(5, 1, 2, 1);
	putblock(5, 5, 2, 1);
	putblock(1, 6, 5, 1);
	
	/* O */
	orgX += 8;
	putblock(1, 0, 5, 1);
	putblock(0, 1, 2, 5);
	putblock(5, 1, 2, 5);
	putblock(1, 6, 5, 1);
	
	/* P */
	orgX += 8;
	putblock(0, 0, 2, 7);
	putblock(0, 0, 6, 1);
	putblock(0, 4, 6, 1);
	putblock(5, 1, 2, 3);
	
	/* Y */
	orgX += 8;
	putblock(0, 0, 2, 3);
	putblock(4, 0, 2, 3);
	putblock(1, 3, 4, 1);
	putblock(2, 4, 2, 3);
	
	/* R */
	orgX += 8;
	putblock(0, 0, 2, 7);
	putblock(0, 0, 6, 1);
	putblock(0, 4, 5, 1);
	putblock(4, 3, 1, 1);
	putblock(5, 1, 2, 3);
	putblock(3, 5, 3, 1);
	putblock(4, 6, 3, 1);
	
	/* I */
	orgX += 8;
	putblock(0, 0, 6, 1);
	putblock(2, 0, 2, 7);
	putblock(0, 6, 6, 1);
	
	/* G */
	orgX += 8;
	putblock(1, 0, 5, 1);
	putblock(5, 1, 2, 1);
	putblock(0, 1, 2, 5);
	putblock(4, 3, 1, 1);
	putblock(5, 3, 2, 3);
	putblock(1, 6, 5, 1);
	
	/* H */
	orgX += 8;
	putblock(0, 0, 2, 7);
	putblock(5, 0, 2, 7);
	putblock(0, 3, 7, 1);
	
	/* T */
	orgX += 8;
	putblock(0, 0, 6, 1);
	putblock(2, 0, 2, 7);
	
	/* [SP] */
	orgX += 8;
	
	/* (C) */
	orgX += 8;
	putblock(1, 0, 5, 1);
	putblock(0, 1, 1, 5);
	putblock(6, 1, 1, 5);
	putblock(1, 6, 5, 1);
	putblock(2, 2, 3, 1);
	putblock(2, 4, 3, 1);
	putblock(2, 3, 1, 1);
	
	/* [SP] */
	orgX += 8;
	
	/* 2 */
	orgX += 8;
	putblock(1, 0, 5, 1);
	putblock(0, 1, 2, 1);
	putblock(5, 1, 2, 2);
	putblock(4, 2, 2, 2);
	putblock(2, 3, 3, 2);
	putblock(1, 4, 1, 1);
	putblock(0, 5, 3, 2);
	putblock(0, 6, 7, 1);
	
	/* 0 */
	orgX += 8;
	putblock(2, 0, 3, 1);
	putblock(1, 1, 1, 1);
	putblock(4, 1, 2, 1);
	putblock(0, 2, 2, 3);
	putblock(5, 2, 2, 3);
	putblock(1, 5, 2, 1);
	putblock(5, 5, 1, 1);
	putblock(2, 6, 3, 1);
	
	/* 1 */
	orgX += 8;
	putblock(2, 0, 2, 7);
	putblock(1, 1, 1, 1);
	putblock(0, 6, 6, 1);
	
	/* 4 */
	orgX += 8;
	putblock(4, 0, 2, 7);
	putblock(3, 0, 1, 2);
	putblock(2, 1, 1, 2);
	putblock(1, 2, 1, 1);
	putblock(0, 3, 2, 2);
	putblock(0, 4, 7, 1);
	
	/* - */
	orgX += 8;
	putblock(1, 3, 5, 1);
	
	/* 2 */
	orgX += 8;
	putblock(1, 0, 5, 1);
	putblock(0, 1, 2, 1);
	putblock(5, 1, 2, 2);
	putblock(4, 2, 2, 2);
	putblock(2, 3, 3, 2);
	putblock(1, 4, 1, 1);
	putblock(0, 5, 3, 2);
	putblock(0, 6, 7, 1);
	
	/* 0 */
	orgX += 8;
	putblock(2, 0, 3, 1);
	putblock(1, 1, 1, 1);
	putblock(4, 1, 2, 1);
	putblock(0, 2, 2, 3);
	putblock(5, 2, 2, 3);
	putblock(1, 5, 2, 1);
	putblock(5, 5, 1, 1);
	putblock(2, 6, 3, 1);
	
	/* 1 */
	orgX += 8;
	putblock(2, 0, 2, 7);
	putblock(1, 1, 1, 1);
	putblock(0, 6, 6, 1);
	
	/* 6 */
	orgX += 8;
	putblock(2, 0, 4, 1);
	putblock(1, 1, 2, 1);
	putblock(0, 2, 2, 4);
	putblock(0, 3, 6, 1);
	putblock(1, 6, 5, 1);
	putblock(5, 4, 2, 2);
	
	/* [SP] */
	orgX += 8;
	
	/* S */
	orgX += 8;
	putblock(1, 0, 4, 1);
	putblock(0, 1, 2, 2);
	putblock(4, 1, 2, 1);
	putblock(1, 3, 5, 1);
	putblock(5, 4, 2, 2);
	putblock(0, 5, 2, 1);
	putblock(1, 6, 5, 1);
	
	/* . */
	orgX += 8;
	putblock(2, 5, 2, 2);
	
	/* I */
	orgX += 8;
	putblock(0, 0, 6, 1);
	putblock(2, 0, 2, 7);
	putblock(0, 6, 6, 1);
	
	/* G */
	orgX += 8;
	putblock(1, 0, 5, 1);
	putblock(5, 1, 2, 1);
	putblock(0, 1, 2, 5);
	putblock(4, 3, 1, 1);
	putblock(5, 3, 2, 3);
	putblock(1, 6, 5, 1);
	
	/* A */
	orgX += 8;
	putblock(2, 0, 3, 1);
	putblock(1, 1, 2, 1);
	putblock(4, 1, 2, 1);
	putblock(0, 2, 2, 5);
	putblock(5, 2, 2, 5);
	putblock(0, 4, 7, 1);
	
	/* R */
	orgX += 8;
	putblock(0, 0, 2, 7);
	putblock(0, 0, 6, 1);
	putblock(0, 4, 5, 1);
	putblock(4, 3, 1, 1);
	putblock(5, 1, 2, 3);
	putblock(3, 5, 3, 1);
	putblock(4, 6, 3, 1);
	
	/* A */
	orgX += 8;
	putblock(2, 0, 3, 1);
	putblock(1, 1, 2, 1);
	putblock(4, 1, 2, 1);
	putblock(0, 2, 2, 5);
	putblock(5, 2, 2, 5);
	putblock(0, 4, 7, 1);
	
	/* S */
	orgX += 8;
	putblock(1, 0, 4, 1);
	putblock(0, 1, 2, 2);
	putblock(4, 1, 2, 1);
	putblock(1, 3, 5, 1);
	putblock(5, 4, 2, 2);
	putblock(0, 5, 2, 1);
	putblock(1, 6, 5, 1);
	
	/* H */
	orgX += 8;
	putblock(0, 0, 2, 7);
	putblock(5, 0, 2, 7);
	putblock(0, 3, 7, 1);
	
	/* I */
	orgX += 8;
	putblock(0, 0, 6, 1);
	putblock(2, 0, 2, 7);
	putblock(0, 6, 6, 1);
	
	/* . */
	orgX += 8;
	putblock(2, 5, 2, 2);
#endif
	
	if ((fp = fopen("Logo.Pix", "rb"))) {
		while (fread(&pix, 1, sizeof(pix), fp)) {
			_setcolor(pix.Color);
			_setpixel(pix.X, pix.Y);
		}
		fclose(fp);
	}
	
	waitfor(750);
	
/*	if ((fp = fopen("Logo.Pix", "wb"))) {
		for (j = 0; j < 480; j++) {
			for (i = 0; i < 640; i++) {
				if ((pix.Color = _getpixel(i, j))) {
					pix.X = i;
					pix.Y = j;
					fwrite(&pix, 1, sizeof(pix), fp);
				}
			}
		}
		fclose(fp);
	}
*/	
	_setvideomode(_DEFAULTMODE);
	end:
	return 0;
}

#endif
