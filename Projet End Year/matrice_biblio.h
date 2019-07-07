/*[
 * Copyright 1986 - 1993, 1998, 2004   Thomas Williams, Colin Kelley
 *
 * Permission to use, copy, and distribute this software and its
 * documentation for any purpose with or without fee is hereby granted,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 *
 * Permission to modify the software is granted, but not the right to
 * distribute the complete modified source code.  Modifications are to
 * be distributed as patches to the released version.  Permission to
 * distribute binaries produced by compiling modified sources is granted,
 * provided you
 *   1. distribute the corresponding source modifications from the
 *    released version in the form of a patch file along with the binaries,
 *   2. add special version identification to distinguish your version
 *    in addition to the base release version number,
 *   3. provide your name and address as the primary contact for the
 *    support of your modified version, and
 *   4. retain our contact information in regard to use of the base
 *    software.
 * Permission to distribute the released version of the source code along
 * with corresponding source modifications in the form of a patch file is
 * granted with same provisions 2 through 4 for binary distributions.
 *
 * This software is provided "as is" without express or implied warranty
 * to the extent permitted by applicable law.
]*/

/*
 * AUTHORS
 *
 * KALIPE Kossi Mathias
 *
 */


#include <stdlib.h>
#define NB_columns_MAX 100
#define NB_rows_MAX 100

void getArray(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
void addArray(float array1[NB_rows_MAX][NB_columns_MAX], float array2[NB_rows_MAX][NB_columns_MAX], float array3[NB_rows_MAX][NB_columns_MAX] ,int rows, int columns);
void displayArray(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
void factorizeArray(float array[NB_rows_MAX][NB_columns_MAX], float new_array[NB_rows_MAX][NB_columns_MAX], int rows, int columns, int index);
float determinant(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
void multiplyArray(float array1[NB_rows_MAX][NB_columns_MAX], float array2[NB_rows_MAX][NB_columns_MAX], float array3[NB_rows_MAX][NB_columns_MAX] ,int rows1, int columns1, int rows2, int columns2);
int zeroFinder(float current_array[NB_rows_MAX][NB_columns_MAX], int current_row, int rows);
void linearRow(float array[NB_rows_MAX][NB_columns_MAX], int pivot, int current_row, int current_column, int columns);
void gradeArray(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
int arrangeArray(float array[NB_rows_MAX][NB_columns_MAX], int current_row, int rows, int current_column, int columns);
float trace(float array[NB_rows_MAX][NB_columns_MAX], int rows);
int rang(float array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
void transpose(float array[NB_rows_MAX][NB_columns_MAX], float t_array[NB_rows_MAX][NB_columns_MAX], int rows, int columns);
int zeroOnLine(float array[NB_rows_MAX][NB_columns_MAX], int current_row, int columns);


