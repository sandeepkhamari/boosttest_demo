# commands to install Boost
sudo apt update
sudo apt intsall libboost-all-dev

# find boost libraries in the following location 
# /usr/lib/x86_64-linux-gnu/libboost_*

# list of libraries available:
# 1.libboost_prg_exec_monitor.a
# 2.libboost_test_exec_monitor.a
# 3.libboost_unit_test_framework.so.1.83.0
# 4.libboost_prg_exec_monitor.so
# 5.libboost_unit_test_framework.a
# 6.libboost_prg_exec_monitor.so.1.83.0
# 7.libboost_unit_test_framework.so

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
