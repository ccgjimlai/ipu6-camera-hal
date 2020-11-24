/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2016 - 2017 Intel Corporation.
 * All Rights Reserved.
 *
 * The source code contained or described herein and all documents
 * related to the source code ("Material") are owned by Intel Corporation
 * or licensors. Title to the Material remains with Intel
 * Corporation or its licensors. The Material contains trade
 * secrets and proprietary and confidential information of Intel or its
 * licensors. The Material is protected by worldwide copyright
 * and trade secret laws and treaty provisions. No part of the Material may
 * be used, copied, reproduced, modified, published, uploaded, posted,
 * transmitted, distributed, or disclosed in any way without Intel's prior
 * express written permission.
 *
 * No License under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or
 * delivery of the Materials, either expressly, by implication, inducement,
 * estoppel or otherwise. Any license under such intellectual property rights
 * must be express and approved by Intel in writing.
 */

#ifndef __VIED_NCI_DMA_TRACE_H
#define __VIED_NCI_DMA_TRACE_H

#include "ia_css_trace.h"

/* Not using 0 to identify wrong configuration being passed from the .mk file outside.
 * Log levels not in the range below will cause a "No NCI_DMA_TRACE_CONFIG Tracing level defined"
 */
#define NCI_DMA_TRACE_LOG_LEVEL_OFF 1
#define NCI_DMA_TRACE_LOG_LEVEL_NORMAL 2
#define NCI_DMA_TRACE_LOG_LEVEL_DEBUG 3

#define NCI_DMA_TRACE_CONFIG_DEFAULT NCI_DMA_TRACE_LOG_LEVEL_OFF

#if !defined(NCI_DMA_TRACE_CONFIG)
#	define NCI_DMA_TRACE_CONFIG NCI_DMA_TRACE_CONFIG_DEFAULT
#endif

/* NCI_DMA Module tracing backend is mapped to TUNIT tracing for target platforms */
#ifdef __HIVECC
#	ifndef HRT_CSIM
#		define NCI_DMA_TRACE_METHOD IA_CSS_TRACE_METHOD_TRACE
#	else
#		define NCI_DMA_TRACE_METHOD IA_CSS_TRACE_METHOD_NATIVE
#	endif
#else
#	define NCI_DMA_TRACE_METHOD IA_CSS_TRACE_METHOD_NATIVE
#endif

#if (defined(NCI_DMA_TRACE_CONFIG))
	/* Module specific trace setting */
#	if NCI_DMA_TRACE_CONFIG == NCI_DMA_TRACE_LOG_LEVEL_OFF
		/* NCI_DMA_TRACE_LOG_LEVEL_OFF */
#		define NCI_DMA_TRACE_LEVEL_ASSERT	IA_CSS_TRACE_LEVEL_DISABLED
#		define NCI_DMA_TRACE_LEVEL_ERROR	IA_CSS_TRACE_LEVEL_DISABLED
#		define NCI_DMA_TRACE_LEVEL_WARNING	IA_CSS_TRACE_LEVEL_DISABLED
#		define NCI_DMA_TRACE_LEVEL_INFO		IA_CSS_TRACE_LEVEL_DISABLED
#		define NCI_DMA_TRACE_LEVEL_DEBUG	IA_CSS_TRACE_LEVEL_DISABLED
#		define NCI_DMA_TRACE_LEVEL_VERBOSE	IA_CSS_TRACE_LEVEL_DISABLED
#	elif NCI_DMA_TRACE_CONFIG == NCI_DMA_TRACE_LOG_LEVEL_NORMAL
		/* NCI_DMA_TRACE_LOG_LEVEL_NORMAL */
#		define NCI_DMA_TRACE_LEVEL_ASSERT	IA_CSS_TRACE_LEVEL_DISABLED
#		define NCI_DMA_TRACE_LEVEL_ERROR	IA_CSS_TRACE_LEVEL_ENABLED
#		define NCI_DMA_TRACE_LEVEL_WARNING	IA_CSS_TRACE_LEVEL_DISABLED
#		define NCI_DMA_TRACE_LEVEL_INFO		IA_CSS_TRACE_LEVEL_ENABLED
#		define NCI_DMA_TRACE_LEVEL_DEBUG	IA_CSS_TRACE_LEVEL_DISABLED
#		define NCI_DMA_TRACE_LEVEL_VERBOSE	IA_CSS_TRACE_LEVEL_DISABLED
#	elif NCI_DMA_TRACE_CONFIG == NCI_DMA_TRACE_LOG_LEVEL_DEBUG
		/* NCI_DMA_TRACE_LOG_LEVEL_DEBUG */
#		define NCI_DMA_TRACE_LEVEL_ASSERT	IA_CSS_TRACE_LEVEL_ENABLED
#		define NCI_DMA_TRACE_LEVEL_ERROR	IA_CSS_TRACE_LEVEL_ENABLED
#		define NCI_DMA_TRACE_LEVEL_WARNING	IA_CSS_TRACE_LEVEL_ENABLED
#		define NCI_DMA_TRACE_LEVEL_INFO		IA_CSS_TRACE_LEVEL_ENABLED
#		define NCI_DMA_TRACE_LEVEL_DEBUG	IA_CSS_TRACE_LEVEL_ENABLED
#		define NCI_DMA_TRACE_LEVEL_VERBOSE	IA_CSS_TRACE_LEVEL_ENABLED
#	else
#		error "No NCI_DMA_TRACE_CONFIG Tracing level defined"
#	endif
#else
#	error "NCI_DMA_TRACE_CONFIG not defined"
#endif

#endif /* __VIED_NCI_DMA_TRACE_H */
