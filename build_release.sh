mkdir sdsl-c

shopt -s extglob
shopt -s dotglob
cp -r !(sdsl-c) sdsl-c/

(cd sdsl-c && git clean -fdx && git submodule update --init --recursive --depth=1)
(cd sdsl-c/external/sdsl-lite && git clean -fdx)
7z a -tzip sdsl-c-template.zip sdsl-c

rm -rf sdsl-c