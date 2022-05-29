# Download and build boost libraries
wget https://boostorg.jfrog.io/artifactory/main/release/1.79.0/source/boost_1_79_0.tar.gz
tar -xf boost_1_79_0.tar.gz
rm boost_1_79_0.tar.gz
cd boost_1_79_0
./bootstrap.sh --prefix=../boost_lib/
./b2 install
