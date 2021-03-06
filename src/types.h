/*
 * Copyright (C) 2012-2013 Red Hat, Inc.
 *
 * Licensed under the GNU Lesser General Public License Version 2.1
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef HY_TYPES_H
#define HY_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _HyForm HyForm;
typedef struct _HyRepo * HyRepo;
typedef struct _HyGoal * HyGoal;
typedef struct _HyNevra * HyNevra;
typedef struct _HyPackage * HyPackage;
typedef struct _HyPackageDelta * HyPackageDelta;
typedef struct _HyPackageList * HyPackageList;
typedef struct _HyPackageListIter * HyPackageListIter;
typedef struct _HyPackageSet * HyPackageSet;
typedef struct _HyPossibilities * HyPossibilities;
typedef struct _HyQuery * HyQuery;
typedef struct _HyReldep * HyReldep;
typedef struct _HyReldepList * HyReldepList;
typedef struct _HySack * HySack;
typedef struct _HySelector * HySelector;
typedef char ** HyStringArray;
typedef char * HySubject;

typedef const unsigned char HyChecksum;

typedef int (*hy_solution_callback)(HyGoal goal, void *callback_data);

#define HY_SYSTEM_REPO_NAME "@System"
#define HY_CMDLINE_REPO_NAME "@commandline"
#define HY_EXT_FILENAMES "-filenames"
#define HY_EXT_UPDATEINFO "-updateinfo"
#define HY_EXT_PRESTO "-presto"

#define HY_CHKSUM_MD5		1
#define HY_CHKSUM_SHA1		2
#define HY_CHKSUM_SHA256	3

enum _hy_key_name_e {
    HY_PKG,
    HY_PKG_ALL,
    HY_PKG_ARCH,
    HY_PKG_CONFLICTS,
    HY_PKG_DESCRIPTION,
    HY_PKG_EPOCH,
    HY_PKG_EVR,
    HY_PKG_FILE,
    HY_PKG_NAME,
    HY_PKG_OBSOLETES,
    HY_PKG_PROVIDES,
    HY_PKG_RELEASE,
    HY_PKG_REPONAME,
    HY_PKG_REQUIRES,
    HY_PKG_SOURCERPM,
    HY_PKG_SUMMARY,
    HY_PKG_URL,
    HY_PKG_VERSION,
    HY_PKG_LOCATION
};

enum _hy_comparison_type_e {
    /* part 1: flags that mix with all types */
    HY_ICASE  = 1 << 0,
    HY_NOT    = 1 << 1,
    HY_COMPARISON_FLAG_MASK = HY_ICASE | HY_NOT,

    /* part 2: comparison types that mix with each other */
    HY_EQ	= (1 << 8),
    HY_LT	= (1 << 9),
    HY_GT	= (1 << 10),

    /* part 3: comparison types that only make sense for strings */
    HY_SUBSTR	= (1 << 11),
    HY_GLOB     = (1 << 12),

    /* part 4: frequently used combinations */
    HY_NEQ	= HY_EQ | HY_NOT,

    /* part 5: additional flags, not necessarily used for queries */
    HY_NAME_ONLY = (1 << 16),
};

#ifdef __cplusplus
}
#endif

#endif /* HY_TYPES_H */
