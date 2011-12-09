#! /bin/sh
test "$(whoami)" != 'root' && (echo you are using a non-privileged account; exit 1)

VAR=2
test "$VAR" -gt 1 -a "$VAR" -lt 3
echo $?
test "$VAR" -gt 1 && test "$VAR" -lt 3
echo $?

