#ifndef CZTTEST_H
#define CZTTEST_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fft_czt.h"

#undef PI
#define PI	3.1415926535897932384626433832795	/* 円周率(π) */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif
#undef N
#define N 20	/* テスト用データのサンプリング数 */

void plot_graph(int Num, REAL *tmp);
int main(void);

#endif
