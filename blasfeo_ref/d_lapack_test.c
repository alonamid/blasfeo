/**************************************************************************************************
*                                                                                                 *
* This file is part of BLASFEO.                                                                   *
*                                                                                                 *
* BLASFEO -- BLAS for embedded optimization.                                                      *
* Copyright (C) 2019 by Gianluca Frison.                                                          *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* The 2-Clause BSD License                                                                        *
*                                                                                                 *
* Redistribution and use in source and binary forms, with or without                              *
* modification, are permitted provided that the following conditions are met:                     *
*                                                                                                 *
* 1. Redistributions of source code must retain the above copyright notice, this                  *
*    list of conditions and the following disclaimer.                                             *
* 2. Redistributions in binary form must reproduce the above copyright notice,                    *
*    this list of conditions and the following disclaimer in the documentation                    *
*    and/or other materials provided with the distribution.                                       *
*                                                                                                 *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND                 *
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED                   *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE                          *
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR                 *
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES                  *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;                    *
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND                     *
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT                      *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS                   *
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                    *
*                                                                                                 *
* Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <blasfeo_common.h>



#define MF_COLMAJ



#define XMATEL_A(X, Y) pA[(X)+lda*(Y)]
#define XMATEL_B(X, Y) pB[(X)+ldb*(Y)]
#define XMATEL_C(X, Y) pC[(X)+ldc*(Y)]
#define XMATEL_D(X, Y) pD[(X)+ldd*(Y)]
#define XMATEL_L(X, Y) pL[(X)+ldl*(Y)]



#define REAL double
#define XMAT blasfeo_dmat_ref
#define XMATEL MATEL_REF
#define XVEC blasfeo_dvec_ref
#define XVECEL VECEL_REF



#define GELQF_PD_DA blasfeo_dgelqf_pd_da_ref
#define GELQF_PD_LA blasfeo_dgelqf_pd_la_ref
#define ORGLQ_WORK_SIZE blasfeo_dorglq_worksize_ref
#define ORGLQ blasfeo_dorglq_ref
#define GELQF_PD_LLA blasfeo_dgelqf_pd_lla_ref
#define GELQF_PD blasfeo_dgelqf_pd_ref
#define GELQF blasfeo_dgelqf_ref
#define GELQF_WORK_SIZE blasfeo_dgelqf_worksize_ref
#define GEQRF blasfeo_dgeqrf_ref
#define GEQRF_WORK_SIZE blasfeo_dgeqrf_worksize_ref
//#define GETF2_NOPIVOT dgetf2_nopivot_ref
#define GETRF_NOPIVOT blasfeo_dgetrf_nopivot_ref
#define GETRF_ROWPIVOT blasfeo_dgetrf_rowpivot_ref
#define POTRF_L blasfeo_dpotrf_l_ref
#define POTRF_L_MN blasfeo_dpotrf_l_mn_ref
#define PSTRF_L dpstrf_l_libstr_ref
#define SYRK_POTRF_LN blasfeo_dsyrk_dpotrf_ln_ref
#define SYRK_POTRF_LN_MN blasfeo_dsyrk_dpotrf_ln_mn_ref

// TESTING_MODE
#include "x_lapack_ref.c"
