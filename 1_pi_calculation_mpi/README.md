# PI Calculation - MPI

### Compile

Use the script `compile`
```
$ ./compile
```

or compile manually
```
$ mpicc -o pi_calculation.o pi_calculation.c
```

### Run
Example run with `num_processes = 4` &  `iterations = 100000`

```
$ mpirun -np 4 pi_calculation.o 100000

Actual PI: 3.141592653883721
Calculated PI: 3.134920000000000
```
