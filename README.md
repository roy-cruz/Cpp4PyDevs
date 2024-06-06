# PURSUE C++ Workshop 
This repository holds all of the lecture notes, material & links which will be used in the PURSUE C++ tutorial. In addition, this repository builds a Jupyter Book which we will be going through during the session. The material here was developed using an assortment of excelent learning material, namely:

* [Learn C++](https://www.learncpp.com/)
* [HSF Basic Moden C++ Tutorial](https://hsf-training.github.io/hsf-training-cpp-webpage/) (Note: Unfinished)
* [C++ Language Tutorial](https://cplusplus.com/doc/tutorial/)
* [HSF C++ Course](https://github.com/hsf-training/cpluspluscourse)

Given the short duration of the session, the material hosted here is meant to serve the additional purpose of being a reference. If, during your internship, you encounter C++, you can always check here and the links provided.

# Set-up

## CMSLPC Cluster

First, connect to the LPC cluster by running the following command.

```bash
ssh -L <fermi_user>@cmslpc-el9.fnal.gov
```
Next, run the following command to setup a directory where you will work in.

```bash
mkdir ~/nobackup/PURSUE-scikithep
cd ~/nobackup/PURSUE-scikithep
```

We will be using `CMSSW_14_1_0_pre3` which includes a C++ compiler. Run the following commands to set this up.

```cpp
cmsrel CMSSW_14_1_0_pre3
cd CMSSW_14_1_0_pre3/src/
cmsenv
```

Finally, clone this repository to get all of the source code shown in the examples in the Jupyter Book by running the following.

```cpp
git clone git@github.com:roy-cruz/PURSUE-cpp.git
cd PURSUE-cpp
```

To test that everything is working, compile and run `helloworld.cpp`.

```cpp
cd examples_cpp
g++ helloworld.cpp -o helloworld
./helloworld
```

If you get the following output, you are ready to go!

```cpp
Hello World 0
Hello World 1
Hello World 2
```