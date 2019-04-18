#!/bin/bash
./compile.sh
TESTS_SUITES=`find build/target/test -name '*_test'`
for SUITE in $TESTS_SUITES
do
  echo "Running $SUITE"
  $SUITE
done