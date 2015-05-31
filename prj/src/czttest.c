#include "czttest.h"

int main(void)
{
	static REAL r1[N], i1[N], r2[N], i2[N], r3[N], i3[N];
	czt_struct cztd;
	int i;

	for (i = 0; i < N; i++) {
		// r1[i] = r2[i] = 6 * sin(2*PI * i/N);

		// r1[i] = r2[i] = 6 * cos(1*PI * i/N);

		r1[i] = r2[i] = 9 * cos(2*2*PI * i/N) +
		                4 * sin(6*2*PI * i/N);

		i1[i] = i2[i] = 0;
	}

	if (czt_init(&cztd, N, N) != 0) return EXIT_FAILURE;

	/* 順変換 */
	czt(&cztd, 0, r2, i2);

	for (i = 0; i < N; i++) {
		r3[i] = r2[i];
		i3[i] = i2[i];
	}

	/* 逆変換 */
	czt(&cztd, 1, r3, i3);

	czt_end(&cztd);

	printf("\n");
	printf("     |  サンプリングデータ   |  フーリエ変換         |  フーリエ逆変換\n");
	printf("-----+-----------------------+-----------------------+-----------------------\n");
	for (i = 0; i < N; i++) {
		printf("%4d | %10.5f %10.5f | %10.5f %10.5f | %10.5f %10.5f\n",
		                            i+1, r1[i],i1[i], r2[i],i2[i], r3[i],i3[i]);
	}
	printf("-----+-----------------------+-----------------------+-----------------------\n");
	printf("\n");

	printf("        サンプリング波形\n");
	plot_graph(N, r1);
	printf("\n");

	printf("        フーリエスペクトル(Re Axis)\n");
	plot_graph(N, r2);
	printf("\n");

	printf("        フーリエスペクトル(Im Axis)\n");
	plot_graph(N, i2);
	printf("\n");

	return EXIT_SUCCESS;
}

//______________________________________________________________________________
void plot_graph(int Num, REAL *tmp)
{
	#define CENTRAL_POS 20
	int i,j;
	for(i=0;i<Num;i++){
		printf("%4d", i+1);
		if((int)(tmp[i]+0.5)>0){ //プラス
			for(j=0;j<CENTRAL_POS -2;j++){ printf(" "); }
			printf("+ ");
			for(j=0;j<(int)(tmp[i]+0.5);j++){ printf("■"); }
		}else if((int)(tmp[i]-0.5)<0){ // マイナス
			for(j=0;j<CENTRAL_POS+(int)(tmp[i]-0.5);j++){ printf(" "); }
			for(j=0;j<-(int)(tmp[i]-0.5);j++){ printf("■"); }
			printf(" -");
		}
		printf("\n");
	}
}
