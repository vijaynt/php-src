--TEST--
SCCP 026: Elimination of dead code due to conflicting type checks
--INI--
opcache.enable=1
opcache.enable_cli=1
opcache.optimization_level=-1
opcache.opt_debug_level=0x20000
opcache.preload=
--SKIPIF--
<?php require_once('skipif.inc'); ?>
--FILE--
<?php
function test($var) {
    if (!is_string($var) || (is_object($var) && !method_exists($var, '__toString'))) {
        return;
    }

    var_dump($username);
}
?>
--EXPECTF--
$_main: ; (lines=1, args=0, vars=0, tmps=0)
    ; (after optimizer)
    ; %s:1-10
L0 (10):    RETURN int(1)

test: ; (lines=9, args=1, vars=2, tmps=1)
    ; (after optimizer)
    ; %s:2-8
L0 (2):     CV0($var) = RECV 1
L1 (3):     T2 = TYPE_CHECK (string) CV0($var)
L2 (3):     JMPZ T2 L4
L3 (3):     JMP L5
L4 (4):     RETURN null
L5 (7):     INIT_FCALL 1 %d string("var_dump")
L6 (7):     SEND_VAR CV1($username) 1
L7 (7):     DO_ICALL
L8 (8):     RETURN null
