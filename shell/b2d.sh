#!/bin/sh
#vim: set sw=4 ts=4 et:
help()
{
    cat<<HELP
    b2d--convert binary to decimal
    USAGE:b2d [-h] binarynum
    OPTIONS:-h help text
    EXAMPLE:b2d 111010
    will return 58
HELP
      exit 0
}

error()
{
    echo "$1"
    exit 1
}

#

