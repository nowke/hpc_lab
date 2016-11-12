# MPI Routines
> Program to implement MPI Send, Receive routines

### Compile

Use the script `compile`
```
$ ./compile
```

or compile manually
```
$ mpicc -o mpi_routines.o mpi_routines.c
```

### Run
> Example Run with `num_processes=4`

```
$ mpirun -np 4 mpi_routines.o
nowke-air.local
nowke-air.local
nowke-air.local
nowke-air.local

Hello World in process with rank 1 from Process with rank 0

Hello World in process with rank 2 from Process with rank 0

Hello World in process with rank 3 from Process with rank 0
```

### MPI Quick Overview
> Source: [https://computing.llnl.gov/tutorials/mpi/](https://computing.llnl.gov/tutorials/mpi/)

`MPI` (Message Passing Interface) is a specification for the developers and users of message passing libraries. By itself, it is NOT a library - but rather the specification of what such a library should be.

MPI primarily addresses the message-passing parallel programming model: data is moved from the address space of one process to that of another process through cooperative operations on each process.

#### General MPI Program Structure
![https://computing.llnl.gov/tutorials/mpi/images/prog_structure.gif](mpi)

#### Header File
Required for all programs that make MPI library calls.

`#include "mpi.h"`

#### Format of MPI calls

Programs must not declare variables or functions with names beginning with the prefix `MPI_`

Format: `rc = MPI_Xxxxx(parameter, ... )`

Example: `rc = MPI_Bsend(&buf,count,type,dest,tag,comm)`

Error code: Returned as `rc`. `MPI_SUCCESS` if successful

#### Communicators and Groups
* MPI uses objects called **communicators** and groups to define which collection of processes may communicate with each other.
* Most MPI routines require you to specify a communicator as an argument.
* Most cases, we use `MPI_COMM_WORLD` whenever a communicator is required - it is the predefined communicator that includes all of your MPI processes.

#### Rank
* Within a communicator, every process has its own unique, integer identifier assigned by the system when the process initializes. A rank is sometimes also called a **"task ID"**. Ranks are contiguous and begin at zero.
* Used by the programmer to specify the source and destination of messages. Often used conditionally by the application to control program execution (if `rank=0` do this / if `rank=1` do that).

### Basic Routines
#### 1. MPI_Init
Initializes the MPI execution environment. This function must be called in every MPI program, must be called before any other MPI functions and must be called only once in an MPI program. For C programs, `MPI_Init` may be used to pass the command line arguments to all processes, although this is not required by the standard and is implementation dependent.

```
MPI_Init(&argc, &argv)
```

#### 2. MPI_Comm_size
Returns the total number of MPI processes in the specified communicator, such as `MPI_COMM_WORLD`. If the communicator is `MPI_COMM_WORLD`, then it represents the number of MPI tasks available to your application.

```
MPI_Comm_size(comm, &size)
```

#### 3. MPI_Comm_rank
Returns the rank of the calling MPI process within the specified communicator. Initially, each process will be assigned a unique integer rank between 0 and number of tasks - 1 within the communicator `MPI_COMM_WORLD`. This rank is often referred to as a task ID. If a process becomes associated with other communicators, it will have a unique rank within each of these as well.

```
MPI_Comm_rank(comm, &rank)
```

#### 4. MPI_Get_processor_name
Returns the processor name. Also returns the length of the name. The buffer for **"name"** must be at least `MPI_MAX_PROCESSOR_NAME` characters in size. What is returned into **"name"** is implementation dependent - may not be the same as the output of the **"hostname"** or **"host"** shell commands.

```
MPI_Get_processor_name(&name, &resultlength)
```

#### 5. MPI_Finalize
Terminates the MPI execution environment. This function should be the last MPI routine called in every MPI program - no other MPI routines may be called after it.

```
MPI_Finalize()
```

### Point to Point Communication Routines

Blocking sends:	`MPI_Send(buffer,count,type,dest,tag,comm)`

Non-blocking sends `MPI_Isend(buffer,count,type,dest,tag,comm,request)`

Blocking receive	`MPI_Recv(buffer,count,type,source,tag,comm,status)`

Non-blocking receive	`MPI_Irecv(buffer,count,type,source,tag,comm,request)`
