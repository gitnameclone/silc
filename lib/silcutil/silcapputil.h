/*

  silcapputil.h 

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2002 Pekka Riikonen

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; version 2 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

*/

/****h* silcutil/SILC Application Utilities
 *
 * DESCRIPTION
 *
 * This interface provides utility functions for applications'
 * convenience.  It provides functions that may be used for example by
 * command line applications but also other applications may find some
 * routines helpful.  None of these routines are mandatory in any other
 * SILC routines or libraries, and are purely provided for convenience.
 * These routines for example provide simple public key and private key
 * pair generation, public key and private key file saving and loading
 * for application, and other similar routines.
 *
 ***/

#ifndef SILCAPPUTIL_H
#define SILCAPPUTIL_H

/****f* silcutil/SilcAppUtil/silc_create_key_pair
 *
 * SYNOPSIS
 *
 *    bool silc_create_key_pair(const char *pkcs_name,
 *                              SilcUInt32 key_len_bits,
 *                              const char *pub_filename,
 *                              const char *prv_filename,
 *                              const char *pub_identifier,
 *                              SilcPKCS *return_pkcs,
 *                              SilcPublicKey *return_public_key,
 *                              SilcPrivateKey *return_private_key,
 *                              bool interactive);
 *
 * DESCRIPTION
 *
 *    This routine can be used to generate new public key and private key
 *    pair.  The `pkcs_name' is the name of public key algorithm, or if
 *    NULL it defaults to "rsa".  The `key_len_bits' is the key length
 *    in bits and if zero (0) it defaults to 2048 bits.  The `pub_filename'
 *    and `prv_filename' is the public key and private key filenames.
 *    The `pub_identifier' is the public key identifier (for example:
 *    "UN=foobar, HN=hostname"), or if NULL the routine generates it
 *    automatically.
 *
 *    The routine returns FALSE if error occurs during key generation.
 *    Function returns TRUE when success and returns the created SilcPKCS
 *    object, which can be used to perform public key cryptography into
 *    `return_pkcs' pointer, created public key into `return_public_key',
 *    and created private key into `return_private_key' pointer.
 *
 *    If the `interactive' is TRUE then this asks the user (by blocking
 *    the process for input) some questions about key generation (like
 *    public key algorithm, key length, filenames, etc).  If all
 *    arguments are provided to this function already then `interactive'
 *    has no effect.
 *
 * NOTES
 *
 *    Before calling this function the application must have initialized
 *    the crypto library by registering the public key algorithms with
 *    silc_pkcs_register_default function.
 *
 ***/
bool silc_create_key_pair(const char *pkcs_name,
			  SilcUInt32 key_len_bits,
			  const char *pub_filename,
			  const char *prv_filename,
			  const char *pub_identifier,
			  SilcPKCS *return_pkcs,
			  SilcPublicKey *return_public_key,
			  SilcPrivateKey *return_private_key,
			  bool interactive);

/****f* silcutil/SilcAppUtil/silc_load_key_pair
 *
 * SYNOPSIS
 *
 *    bool silc_load_key_pair(const char *pub_filename,
 *                            const char *prv_filename,
 *                            SilcPKCS *return_pkcs,
 *                            SilcPublicKey *return_public_key,
 *                            SilcPrivateKey *return_private_key);
 *
 * DESCRIPTION
 *
 *    This routine can be used to load the public key and private key
 *    from files.  This retuns FALSE it either of the key could not be
 *    loaded.  This function returns TRUE on success and returns the
 *    public key into `return_public_key' pointer, private key into
 *    `return_private_key' pointer and the SilcPKCS object to the
 *    `return_pkcs'.  The SilcPKCS can be used to perform public key
 *    cryptographic operations.
 *
 ***/
bool silc_load_key_pair(const char *pub_filename,
			const char *prv_filename,
			SilcPKCS *return_pkcs,
			SilcPublicKey *return_public_key,
			SilcPrivateKey *return_private_key);

/****f* silcutil/SilcAppUtil/silc_show_public_key
 *
 * SYNOPSIS
 *
 *    bool silc_show_public_key(const char *pub_filename);
 *
 * DESCRIPTION
 *
 *    This routine can be used to dump the contents of the public key
 *    in the public key file `pub_filename'.  This dumps the public key
 *    into human readable form into stdout.  Returns FALSE on error.
 *
 ***/
bool silc_show_public_key(const char *pub_filename);

#endif /* SILCAPPUTIL_H */