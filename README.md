# commands to install Boost
sudo apt update
sudo apt intsall libboost-all-dev

# command to install only the testing framework
sudo apt install libboost-test-dev

# create the project

# create a build directory in the top-level dir.
mkdir -p build

# Go to build directory
cd build

# build the project
cmake -S.. -B.
cmake --build .

# running test cases.
ctest --verbose
