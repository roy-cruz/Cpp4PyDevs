# PURSUE C++ Workshop 
This repository holds all of the material & links which will be used in the PURSUE C++ tutorial. The main source of information which will be used will be the lecture notes included in this repo. These were developed using an assortment of excelent learning material, namely:

* [Learn C++](https://www.learncpp.com/)
* [HSF Basic Moden C++ Tutorial](https://hsf-training.github.io/hsf-training-cpp-webpage/) (Note: Unfinished)
* [C++ Language Tutorial](https://cplusplus.com/doc/tutorial/)
* [HSF C++ Course](https://github.com/hsf-training/cpluspluscourse)

The notes provided here are meant to serve as a guide and as a quick reference.

# Set-up

## CMSLPC Cluster

Add the following to your `~/.ssh/config` file

```cpp
Host cmslpc-*.fnal.gov
    StrictHostKeyChecking no
    UserKnownHostsFile /dev/null
```

and log into the LPC cluster. Once there, run the following commands

```cpp
mkdir nobackup/PURSUE-CPP
cd nobackup/PURSUE-CPP
cmsrel CMSSW_12_4_19
cd CMSSW_12_4_19/src/
cmsenv
git clone git@github.com:roy-cruz/PURSUE-cpp.git
cd PURSUE-cpp
```

To test that everything is working, compile and run `helloworld.cpp`.

```cpp
cd examples
g++ helloworld.cpp -o helloworld
./helloworld
```

If you get the following output, you are ready to go!

```cpp
Hello World 0
Hello World 1
Hello World 2
```

