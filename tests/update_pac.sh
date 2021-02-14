#!/bin/bash

cd ..
make
mv main.cpython-35m-x86_64-linux-gnu.so tests/main.cpython-35m-x86_64-linux-gnu.so
cd tests
