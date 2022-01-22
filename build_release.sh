mkdir -p build/release_archive
(cd build/release_archive && mkdir sdsl-c)

shopt -s extglob
shopt -s dotglob
cp -r !(build) build/release_archive/sdsl-c/

cd build/release_archive

(cd sdsl-c && git clean -fdx && git submodule update --init --recursive --depth=1)
(cd sdsl-c/external/sdsl-lite && git clean -fdx)

(cd sdsl-c && rm -rf .git)
7z a -tzip sdsl-c-template.zip sdsl-c

rm -rf sdsl-c