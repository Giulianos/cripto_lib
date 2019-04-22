#!/bin/bash
./clear.sh
./compile.sh
cd build/target/test
echo -e ''
TESTS_SUITES=`find . -name '*_test'`
for SUITE in $TESTS_SUITES
do
  echo -e "Running $SUITE"
  $SUITE
done