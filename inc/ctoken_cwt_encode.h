/*
 * ctoken_cwt_encode.h
 *
 * Copyright (c) 2020 Laurence Lundblade.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * See BSD-3-Clause license in README.md
 *
 * Created by Laurence Lundblade on 1/31/20.
 */

#ifndef cwt_encode_h
#define cwt_encode_h

#include "ctoken_encode.h"
#include "ctoken_cwt_labels.h"


// TODO: Make prototypes of these and document them


static inline void ctoken_encode_cwt_issuer(struct ctoken_encode_ctx *me,
                                            struct q_useful_buf_c issuer)
{
    ctoken_encode_add_tstr(me, CTOKEN_CWT_LABEL_ISSUER, issuer);
}

static inline void ctoken_encode_cwt_subject(struct ctoken_encode_ctx *me,
                                             struct q_useful_buf_c subject)
{
    ctoken_encode_add_tstr(me, CTOKEN_CWT_LABEL_SUBJECT, subject);
}

static inline void ctoken_encode_cwt_audience(struct ctoken_encode_ctx *me,
                                              struct q_useful_buf_c audience)
{
    ctoken_encode_add_tstr(me, CTOKEN_CWT_LABEL_AUDIENCE, audience);
}


static inline void ctoken_encode_cwt_expiration(struct ctoken_encode_ctx *me,
                                                int64_t expiration)
{
    // TAG by time? No... TODO:
    ctoken_encode_add_integer(me, CTOKEN_CWT_LABEL_EXPIRATION, expiration);
}

static inline void ctoken_encode_cwt_not_before(struct ctoken_encode_ctx *me,
                                               int64_t not_before)
{
    // Per RFC 8239 (CWT) this can be a float. That is not handled
    // here. TODO: figure out if the standard should allow floats
    // or not.
    ctoken_encode_add_integer(me, CTOKEN_CWT_LABEL_NOT_BEFORE, not_before);
}


static inline void ctoken_encode_cwt_iat(struct ctoken_encode_ctx *me,
                                         int64_t iat)
{
    ctoken_encode_add_integer(me, CTOKEN_CWT_LABEL_IAT, iat);
}


static inline void ctoken_encode_cwt_cti(struct ctoken_encode_ctx *me,
                                         struct q_useful_buf_c cti)
{
    ctoken_encode_add_bstr(me, CTOKEN_CWT_LABEL_CTI, cti);
}



#endif /* cwt_encode_h */
