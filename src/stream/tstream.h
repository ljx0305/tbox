/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2012, ruki All rights reserved.
 *
 * @author		ruki
 * @file		tstream.h
 * @ingroup 	stream
 *
 */
#ifndef TB_STREAM_TSTREAM_H
#define TB_STREAM_TSTREAM_H

/* ///////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"
#include "gstream.h"
#include "astream.h"

/* ///////////////////////////////////////////////////////////////////////
 * types
 */

/*! the tstream save func type
 *
 * @param size 		the saved size currently, finished if size == -1
 * @param rate 		the current rate, bytes/s and will be total rate if size == -1
 * @param priv 		the func private data
 *
 * @return 			tb_true: ok and continue it if need, tb_false: break it
 */
typedef tb_bool_t 	(*tb_tstream_save_func_t)(tb_long_t size, tb_size_t rate, tb_pointer_t priv);

/* ///////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! save to astream from gstream, block transfer
 *
 * @param istream 	the istream, open it first if have been not opened
 * @param ostream 	the ostream, open it first if have been not opened
 * @param rate 		the trasfer rate and no limit if 0, bytes/s
 * @param func 		the save func and be optional
 * @param priv 		the func private data
 *
 * @return 			the saved size, failed: -1
 */
tb_hong_t 			tb_tstream_save_ga(tb_gstream_t* istream, tb_astream_t* ostream, tb_size_t rate, tb_tstream_save_func_t func, tb_pointer_t priv);

/*! save to gstream from gstream, block transfer
 *
 * @param istream 	the istream, open it first if have been not opened
 * @param ostream 	the ostream, open it first if have been not opened
 * @param rate 		the trasfer rate and no limit if 0, bytes/s
 * @param func 		the save func and be optional
 * @param priv 		the func private data
 *
 * @return 			the saved size, failed: -1
 */
tb_hong_t 			tb_tstream_save_gg(tb_gstream_t* istream, tb_gstream_t* ostream, tb_size_t rate, tb_tstream_save_func_t func, tb_pointer_t priv);

/*! save to url from url, block transfer
 *
 * @param iurl 		the input url
 * @param ourl 		the output url
 * @param rate 		the trasfer rate and no limit if 0, bytes/s
 * @param func 		the save func and be optional
 * @param priv 		the func private data
 *
 * @return 			the saved size, failed: -1
 */
tb_hong_t 			tb_tstream_save_uu(tb_char_t const* iurl, tb_char_t const* ourl, tb_size_t rate, tb_tstream_save_func_t func, tb_pointer_t priv);

/*! init transfer stream from astrean to astream, async transfer
 *
 * @param istream 	the istream, open it first if have been not opened
 * @param ostream 	the ostream, open it first if have been not opened
 * @param func 		the save func and be not optional
 * @param priv 		the func private data
 *
 * @return 			the saved size, failed: -1
 */
tb_handle_t 		tb_tstream_init_aa(tb_astream_t* istream, tb_astream_t* ostream, tb_tstream_save_func_t func, tb_pointer_t priv);

/*! init transfer stream from astrean to gstream, async transfer
 *
 * @param istream 	the istream, open it first if have been not opened
 * @param ostream 	the ostream, open it first if have been not opened
 * @param func 		the save func and be not optional
 * @param priv 		the func private data
 *
 * @return 			the saved size, failed: -1
 */
tb_handle_t 		tb_tstream_init_ag(tb_astream_t* istream, tb_gstream_t* ostream, tb_tstream_save_func_t func, tb_pointer_t priv);

/*! init transfer stream from url to url, async transfer
 *
 * @param iurl 		the input url
 * @param ourl 		the output url
 * @param func 		the save func and be not optional
 * @param priv 		the func private data
 *
 * @return 			the saved size, failed: -1
 */
tb_handle_t 		tb_tstream_init_uu(tb_char_t const* iurl, tb_char_t const* ourl, tb_tstream_save_func_t func, tb_pointer_t priv);

/*! start transfer stream 
 *
 * @param tstream 	the tstream
 *
 * @return 			tb_true or tb_false
 */
tb_bool_t 			tb_tstream_start(tb_handle_t tstream);

/*! pause transfer stream 
 *
 * @param tstream 	the tstream
 */
tb_void_t 			tb_tstream_pause(tb_handle_t tstream);

/*! limit transfer rate  
 *
 * @param tstream 	the tstream
 * @param rate 		the trasfer rate and no limit if 0, bytes/s
 */
tb_void_t 			tb_tstream_limit(tb_handle_t tstream, tb_size_t rate);

/*! stop transfer stream 
 *
 * @param tstream 	the tstream
 */
tb_void_t 			tb_tstream_stop(tb_handle_t tstream);

/*! exit transfer stream 
 *
 * @param tstream 	the tstream
 */
tb_void_t 			tb_tstream_exit(tb_handle_t tstream);

#endif
