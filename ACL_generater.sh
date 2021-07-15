# rm util/ACL.hpp
# git clone https://github.com/atcoder/ac-library
# echo -n -e "#pragma once\n#include<atcoder/all>" >tmp.cpp
# echo $CPLUS_INCLUDE_PATH >tmp2.txt
# export CPLUS_INCLUDE_PATH="/vscode/code/cpplib/ac-library"
# python3 ac-library/expander.py tmp.cpp
# grep -v '^\s*$' combined.cpp > util/ACL.hpp
# export CPLUS_INCLUDE_PATH=`tmp2.txt`
# rm -rf tmp.cpp combined.cpp ac-library tmp2.txt

rm ac-library
git clone https://github.com/atcoder/ac-library.git