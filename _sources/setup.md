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
