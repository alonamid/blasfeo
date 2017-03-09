/**************************************************************************************************
*                                                                                                 *
* This file is part of BLASFEO.                                                                   *
*                                                                                                 *
* BLASFEO -- BLAS For Embedded Optimization.                                                      *
* Copyright (C) 2016-2017 by Gianluca Frison.                                                     *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* HPMPC is free software; you can redistribute it and/or                                          *
* modify it under the terms of the GNU Lesser General Public                                      *
* License as published by the Free Software Foundation; either                                    *
* version 2.1 of the License, or (at your option) any later version.                              *
*                                                                                                 *
* HPMPC is distributed in the hope that it will be useful,                                        *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                                  *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                                            *
* See the GNU Lesser General Public License for more details.                                     *
*                                                                                                 *
* You should have received a copy of the GNU Lesser General Public                                *
* License along with HPMPC; if not, write to the Free Software                                    *
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA                  *
*                                                                                                 *
* Author: Gianluca Frison, giaf (at) dtu.dk                                                       *
*                          gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

#if defined(LA_BLAS)
#if defined(REF_BLAS_OPENBLAS)
#include <f77blas.h>
#elif defined(REF_BLAS_BLIS)
#elif defined(REF_BLAS_NETLIB)
#include "d_blas.h"
#elif defined(REF_BLAS_MKL)
#include <mkl_blas.h>
#endif
#endif

#include "../include/blasfeo_common.h"
#include "../include/blasfeo_d_kernel.h"



#if defined(LA_REFERENCE)



void daxpy_libstr(int m, double alpha, struct d_strvec *sx, int xi, struct d_strvec *sy, int yi, struct d_strvec *sz, int zi)
	{
	int ii;
	double *x = sx->pa + xi;
	double *y = sy->pa + yi;
	double *z = sz->pa + zi;
	for(ii=0; ii<m; ii++)
		z[ii] = y[ii] + alpha*x[ii];
	return;
	}



// multiply two vectors and compute dot product
double dvecmuldot_libstr(int m, struct d_strvec *sx, int xi, struct d_strvec *sy, int yi, struct d_strvec *sz, int zi)
	{
	double *x = sx->pa + xi;
	double *y = sy->pa + yi;
	double *z = sz->pa + zi;
	int ii;
	double dot = 0.0;
	ii = 0;
	for(; ii<m-3; ii+=4)
		{
		z[ii+0] = x[ii+0] * y[ii+0];
		z[ii+1] = x[ii+1] * y[ii+1];
		z[ii+2] = x[ii+2] * y[ii+2];
		z[ii+3] = x[ii+3] * y[ii+3];
		dot += z[ii+0] + z[ii+1] + z[ii+2] + z[ii+3];
		}
	for(; ii<m; ii++)
		{
		z[ii+0] = x[ii+0] * y[ii+0];
		dot += z[ii+0];
		}
	return dot;
	}



// compute dot product of two vectors
double ddot_libstr(int m, struct d_strvec *sx, int xi, struct d_strvec *sy, int yi)
	{
	double *x = sx->pa + xi;
	double *y = sy->pa + yi;
	int ii;
	double dot = 0.0;
	ii = 0;
	for(; ii<m-3; ii+=4)
		{
		dot += x[ii+0] * y[ii+0];
		dot += x[ii+1] * y[ii+1];
		dot += x[ii+2] * y[ii+2];
		dot += x[ii+3] * y[ii+3];
		}
	for(; ii<m; ii++)
		{
		dot += x[ii+0] * y[ii+0];
		}
	return dot;
	}



#elif defined(LA_BLAS)



void daxpy_libstr(int m, double alpha, struct d_strvec *sx, int xi, struct d_strvec *sy, int yi, struct d_strvec *sz, int zi)
	{
	int i1 = 1;
	double *x = sx->pa + xi;
	double *y = sy->pa + yi;
	double *z = sz->pa + zi;
	if(y!=z)
#if defined(REF_BLAS_MKL)
		dcopy(&m, y, &i1, z, &i1);
#else
		dcopy_(&m, y, &i1, z, &i1);
#endif
#if defined(REF_BLAS_MKL)
	daxpy(&m, &alpha, x, &i1, z, &i1);
#else
	daxpy_(&m, &alpha, x, &i1, z, &i1);
#endif
	return;
	}



// multiply two vectors and compute dot product
double dvecmuldot_libstr(int m, struct d_strvec *sx, int xi, struct d_strvec *sy, int yi, struct d_strvec *sz, int zi)
	{
	double *x = sx->pa + xi;
	double *y = sy->pa + yi;
	double *z = sz->pa + zi;
	int ii;
	double dot = 0.0;
	ii = 0;
	for(; ii<m; ii++)
		{
		z[ii+0] = x[ii+0] * y[ii+0];
		dot += z[ii+0];
		}
	return dot;
	}



// compute dot product of two vectors
double ddot_libstr(int m, struct d_strvec *sx, int xi, struct d_strvec *sy, int yi)
	{
	double *x = sx->pa + xi;
	double *y = sy->pa + yi;
	int ii;
	double dot = 0.0;
	ii = 0;
	for(; ii<m-3; ii+=4)
		{
		dot += x[ii+0] * y[ii+0];
		dot += x[ii+1] * y[ii+1];
		dot += x[ii+2] * y[ii+2];
		dot += x[ii+3] * y[ii+3];
		}
	for(; ii<m; ii++)
		{
		dot += x[ii+0] * y[ii+0];
		}
	return dot;
	}



#else

#error : wrong LA choice

#endif
