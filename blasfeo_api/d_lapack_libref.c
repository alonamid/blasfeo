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

#include "../include/blasfeo_common.h"
#include "../include/blasfeo_d_aux.h"

#define REAL double
#define STRMAT blasfeo_dmat_ref
#define STRVEC blasfeo_dvec_ref

#define GELQF_PD_DA_LIBSTR blasfeo_dgelqf_pd_da_ref
#define GELQF_PD_LA_LIBSTR blasfeo_dgelqf_pd_la_ref
#define GELQF_PD_LLA_LIBSTR blasfeo_dgelqf_pd_lla_ref
#define GELQF_PD_LIBSTR blasfeo_dgelqf_pd_ref
#define GELQF_LIBSTR blasfeo_dgelqf_ref
#define GELQF_WORK_SIZE_LIBSTR blasfeo_dgelqf_worksize_ref
#define GEQRF_LIBSTR blasfeo_dgeqrf_ref
#define GEQRF_WORK_SIZE_LIBSTR blasfeo_dgeqrf_worksize_ref
#define GETF2_NOPIVOT dgetf2_nopivot_ref
#define GETRF_NOPIVOT_LIBSTR blasfeo_dgetrf_nopivot_ref
#define GETRF_LIBSTR blasfeo_dgetrf_rowpivot_ref
#define POTRF_L_LIBSTR blasfeo_dpotrf_l_ref
#define POTRF_L_MN_LIBSTR blasfeo_dpotrf_l_mn_ref
#define PSTRF_L_LIBSTR dpstrf_l_libstr_ref
#define SYRK_POTRF_LN_LIBSTR blasfeo_dsyrk_dpotrf_ln_ref
#define SYRK_POTRF_LN_MN_LIBSTR blasfeo_dsyrk_dpotrf_ln_mn_ref

// TESTING_MODE
#include "x_lapack_lib.c"
