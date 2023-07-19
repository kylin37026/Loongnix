#!/bin/sh

export LC_ALL=C LANG=C
export PATH=/opt/loongarch64-linux-gnu-2021-12-10-vector/bin:$PATH
make ARCH=loongarch CROSS_COMPILE=loongarch64-linux-gnu- -j4

