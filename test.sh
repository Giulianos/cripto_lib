#!/bin/bash
./clear.sh
./compile.sh
TESTS_SUITES=`find build/target/test -name '*_test'`
for SUITE in $TESTS_SUITES
do
  echo -e "Running $SUITE"
  $SUITE
done