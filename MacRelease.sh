cmake -G Ninja -S . -B Build -D CMAKE_BUILD_TYPE=Release -D lacia_game=Lacia -D lacia_mac=on -Wdev\
 -Werror=dev -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ -D CMAKE_LINKER=lld -D \
CMAKE_C_FLAGS="-isysroot `xcrun -sdk macosx --show-sdk-path`" -D \
CMAKE_CXX_FLAGS="-isysroot `xcrun -sdk macosx --show-sdk-path`"
ninja -C Build
open Build/Lacia.app