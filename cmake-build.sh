#!/usr/bin/env bash
set -euo pipefail

cmake .
intercept-build make
make clean
cd ..
