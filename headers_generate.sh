#!/bin/bash
BIN_SRC_FOLDER=bin/classes
cd $BIN_SRC_FOLDER
PACKAGE=com/simplexsolutionsinc/coresignkernelwrapper
FOLDER=$1
for file in $(find $PACKAGE/$FOLDER -name "*.class");
do
CLASS=${file##*/}
CLASS=${CLASS%.*}
FULLPATH=com.simplexsolutionsinc.coresignkernelwrapper.$FOLDER.$CLASS
javah  -jni $FULLPATH
done

