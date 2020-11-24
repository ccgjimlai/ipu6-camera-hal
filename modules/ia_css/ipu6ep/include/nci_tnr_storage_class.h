/*
 * INTEL CONFIDENTIAL
 *
 * Copyright (C) 2017 - 2017 Intel Corporation.
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

#ifndef __NCI_TNR_STORAGE_CLASS_H
#define __NCI_TNR_STORAGE_CLASS_H

#include "storage_class.h"

#ifndef __INLINE_NCI_TNR__
#define NCI_TNR_STORAGE_CLASS_H STORAGE_CLASS_EXTERN
#define NCI_TNR_STORAGE_CLASS_C
#else	/* __INLINE_NCI_TNR__ */
#define NCI_TNR_STORAGE_CLASS_H STORAGE_CLASS_INLINE
#define NCI_TNR_STORAGE_CLASS_C STORAGE_CLASS_INLINE
#endif	/* __INLINE_NCI_TNR__ */

#endif /* __NCI_TNR_STORAGE_CLASS_H */
