/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */
/*
 * Copyright (c) 2013 RackTop Systems.
 */
/*
 * Copyright 2017 Joyent, Inc.
 */

#if !defined(_CUSTR_H)
#define _CUSTR_H

#include <stdarg.h>

typedef struct custr custr_t;

/*
 * Allocate and free a "custr_t" dynamic string object.  Returns 0 on success
 * and -1 otherwise.
 */
extern int custr_alloc(custr_t **);
extern void custr_free(custr_t *);

/*
 * Allocate a "custr_t" dynamic string object that operates on a fixed external
 * buffer.
 */
extern int custr_alloc_buf(custr_t **, void *, size_t);

/*
 * Append a single character, or a NUL-terminated string of characters, to a
 * dynamic string.  Returns 0 on success and -1 otherwise.  The dynamic string
 * will be unmodified if the function returns -1.
 */
extern int custr_appendc(custr_t *, char);
extern int custr_append(custr_t *, const char *);

/*
 * Append a format string and arguments as though the contents were being parsed
 * through snprintf. Returns 0 on success and -1 otherwise.  The dynamic string
 * will be unmodified if the function returns -1.
 */
extern int custr_append_printf(custr_t *, const char *, ...);
extern int custr_append_vprintf(custr_t *, const char *, va_list);

/*
 * Determine the length in bytes, not including the NUL terminator, of the
 * dynamic string.
 */
extern size_t custr_len(custr_t *);

/*
 * Clear the contents of a dynamic string.  Does not free the underlying
 * memory.
 */
extern void custr_reset(custr_t *);

/*
 * Retrieve a const pointer to a NUL-terminated string version of the contents
 * of the dynamic string.  Storage for this string should not be freed, and
 * the pointer will be invalidated by any mutations to the dynamic string.
 */
extern const char *custr_cstr(custr_t *str);

#endif		/* _CUSTR_H */
