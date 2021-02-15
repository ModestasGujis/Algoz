#!/bin/bash

cd ..

path=main$(python3-config --extension-suffix)
make
mv $path tests/$path
cd tests
