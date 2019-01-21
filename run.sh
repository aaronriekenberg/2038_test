#!/bin/sh -x

case $(uname) in
  OpenBSD)
    cd openbsd
    ;;
  Linux)
    cd linux
    ;;
  Darwin)
    cd macos
    ;;
  *)
    echo 'unknown OS'
    exit 1
    ;;
esac

cc test.c
./a.out
