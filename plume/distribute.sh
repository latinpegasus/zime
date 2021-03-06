#!/bin/bash
if [ $# != 1 ]
    then
    echo "version number not provided."
    exit -1
fi
ver=$1
target=plume-${ver}
if [ -e $target ]
    then
    echo "error: $target already exists."
    exit -1
fi
svn export . temp || exit -1
cd temp
ant build || exit -1
mkdir war/data
cp data/make-json.py war/data/
mkdir war/script
java -jar ~/opt/compiler.jar --js script/jquery-1.3.2.min.js --js script/jquery.json-2.2.min.js --js_output_file war/script/jquery.js --compilation_level WHITESPACE_ONLY
java -jar ~/opt/compiler.jar --js script/zimecore.js --js script/zimeimpl.js --js_output_file war/script/zime.js
cp LICENSE.txt README.txt war/
rm -R war/WEB-INF
mv war $target
zip -r ../$target.zip $target
cd ..
rm -R temp
echo "done."
