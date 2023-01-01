# cppPractice
practice modern cpp with CMake

you need to create a build folder and use the following command inside of it:

```rm -rf * && cmake .. -DBUILD_TESTS=true && make -j```


GTest install
```
cd ~
git clone https://github.com/google/googletest.git
cd googletest
mkdir build && cd build
cmake .. -DBUILD_SHARED_LIBS=ON -DINSTALL_GTEST=ON -DCMAKE_INSTALL_PREFIX:PATH=/usr
make -j8
sudo make install
sudo ldconfig
```
