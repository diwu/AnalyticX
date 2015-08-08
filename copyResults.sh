#!/bin/bash

# A simple script to copy all of necessary files to Add-To-Your-Own-Project folder
# This will prevent mistake and error from manual copying files after done with making changes to the project and ready to ship or making commit.
#
# It will search the file path via `find .` in AnalyticX folder and use the first result (tested and ensured that it has only 1 result) as a path to grab the file and copy it to Add-To-Your-Own-Project folder
#
# Author @haxpor
#

# findPathOfFileName <file>
# ex:   findPathOfFileName AppDelegate.cpp
#       findPathOfFileName AnalyticX.cpp
# Return absoluate path of specified file.
#
function findPathOfFileName {
    path=`find "$(pwd)" | grep "$1"`
    echo "$path"
}

# copyFileToTargetFolder <file> <targetFolder>
# ex:   copyFileToTargetFolder /your/path/AnalyticX.cpp /your/path/path2/
#       copyFileToTargetFolder /your/path/AnalyticX.cpp /your/path/path2/AnalyticX.cpp
# It copies by preserve the file permission and attributes via 'cp -a'
#
function copyFileToTargetFolder {
    cp -fa "$1" "$2" 
}

# working directory is based on project directory
WORK_DIR="AnalyticX"
# target directory to copy files to is based on *working directory*
TARGET_DIR="../Add-To-Your-Own-Project"
# TODO: Define more files to copy into target directory here ...
RESULT_FILES_TO_COPY=("AnalyticX.cpp" 
              "AnalyticX.h" 
              "AnalyticX.mm" 
              "AnalyticXMacros.h" 
              "AnalyticXStringUtil.h" 
              "AnalyticXStringUtil.mm" 
              "AnalyticXStringUtilAndroid.cpp" 
              "AnalyticXStringUtilAndroid.h" 
              "Flurry.h" 
              "libFlurry.a" 
              "FlurryAgent.jar")

# go to our working directory started from xcode project directory
cd $WORK_DIR

# loop through all files in RESULT_FILES
for file in "${RESULT_FILES_TO_COPY[@]}"
do
    filePath=`findPathOfFileName "$file"`
    copyFileToTargetFolder "$filePath" "$TARGET_DIR"
    echo "Done copying '$file' to '$TARGET_DIR'"
done

