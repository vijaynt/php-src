/*
   +----------------------------------------------------------------------+
   | PHP Version 4                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2003 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.0 of the PHP license,       |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_0.txt.                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Harald Radi <h.radi@nme.at>                                  |
   +----------------------------------------------------------------------+
 */

#ifndef COM_H
#define COM_H

#include "../handler.h"
#include "../php_rpc.h"

#ifndef PHP_COM_DONT_DECLARE_RPC_HANDLER
RPC_DECLARE_HANDLER(com);
#endif

ZEND_MINIT_FUNCTION(com);
ZEND_MSHUTDOWN_FUNCTION(com);
ZEND_MINFO_FUNCTION(com);

ZEND_FUNCTION(com_addref);
ZEND_FUNCTION(com_release);
ZEND_FUNCTION(com_isenum);
ZEND_FUNCTION(com_next);
ZEND_FUNCTION(com_all);
ZEND_FUNCTION(com_reset);
ZEND_FUNCTION(com_skip);
ZEND_FUNCTION(com_event_sink);
ZEND_FUNCTION(com_message_pump);
ZEND_FUNCTION(com_load_typelib);
ZEND_FUNCTION(com_print_typeinfo);

#endif