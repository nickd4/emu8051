#!/bin/sh

# see https://github.com/HEYAHONG/emu8051
#sudo apt-get install build-essential automake autoconf libgtk2.0-dev libreadline-dev zlib*-dev pkg-config

./autogen.sh
./configure --prefix=$HOME/.local
make
make install
