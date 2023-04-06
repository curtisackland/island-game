# Compile and run the game
cmake -DCMAKE_BUILD_TYPE=Debug -B ./build -S .
make -j$(nproc) -C ./build
./build/island-game
