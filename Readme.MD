# Pwnbrew Persistence Utilties

This project has three persistence wrappers for the Pwnbrew Stager payload. 

JAR_Loader:  A standard Windows EXE or DLL.

Service: A standard Windows service EXE.

Process_Hollow: A DLL that hollows a target process and injects the JAR_Loader executable. This project also contains a watchdog process that monitors whether the child process is active and restarts it if it is killed. It currently utilizes the Print Monitor method of persistence in Windows.

**The projects expects the Java _Stager.jar_ to be in the root of the solution directory**
