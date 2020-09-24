#!/bin/bash

testSize=10000;

for ((i=0; i < $testSize; i++));
do
  ./537ps -p $i
  returnVal=$?

  if [ $returnVal -eq  1 ];then
    echo "error"
    exit 1
  fi

done

for ((i=0; i < $testSize; i++));
do
  ./537ps -p $i -U-
  returnVal=$?

  if [ $returnVal -eq  1 ];then
    echo "error"
    exit 1
  fi

done

for ((i=0; i < $testSize; i++));
do
  ./537ps -p $i -c-
  returnVal=$?

  if [ $returnVal -eq  1 ];then
    echo "error"
    exit 1
  fi

done

for ((i=0; i < $testSize; i++));
do
  ./537ps -p $i -U- -c-
  returnVal=$?

  if [ $returnVal -eq  1 ];then
    echo "error"
    exit 1
  fi

done

for ((i=0; i < $testSize; i++));
do
  ./537ps -p $i -s
  returnVal=$?

  if [ $returnVal -eq  1 ];then
    echo "error"
    exit 1
  fi

done

for ((i=0; i < $testSize; i++));
do
  ./537ps -p $i -S
  returnVal=$?

  if [ $returnVal -eq  1 ];then
    echo "error"
    exit 1
  fi

done

for ((i=0; i < $testSize; i++));
do
  ./537ps -p $i -s -S
  returnVal=$?

  if [ $returnVal -eq  1 ];then
    echo "error"
    exit 1
  fi

done

for ((i=0; i < $testSize; i++));
do
  ./537ps -p $i -s -S -v
  returnVal=$?

  if [ $returnVal -eq  1 ];then
    echo "error"
    exit 1
  fi
done