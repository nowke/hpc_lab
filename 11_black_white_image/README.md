# Black & White Image

> Program to convert a color image to black and white image to demonstrate performance of different `Scheduling` techniques

### Scheduling Techniques in `OpenMP`

Source: [OpenMP Loop Scheduling - Intel](https://software.intel.com/en-us/articles/openmp-loop-scheduling)

| Kind    | Description |
| ------- | ----------- |
| static  | Divide the loop into equal-sized chunks or as equal as possible in the case where the number of loop iterations is not evenly divisible by the number of threads multiplied by the chunk size. By default, chunk size is `loop_count/number_of_threads`. Set chunk to 1 to interleave the iterations. |
| dynamic | Use the internal work queue to give a chunk-sized block of loop iterations to each thread. When a thread is finished, it retrieves the next block of loop iterations from the top of the work queue. By default, the `chunk size` is 1. Be careful when using this scheduling type because of the extra overhead involved. |
| guided  | Similar to dynamic scheduling, but the chunk size starts off large and decreases to better handle load imbalance between iterations. The optional chunk parameter specifies them minimum size chunk to use. By default the chunk size is approximately `loop_count/number_of_threads`. |
| auto    | When schedule (auto) is specified, the decision regarding scheduling is delegated to the compiler. The programmer gives the compiler the freedom to choose any possible mapping of iterations to threads in the team. |
| runtime | Uses the `OMP_SCHEDULE` environment variable to specify which one of the three loop-scheduling types should be used. `OMP_SCHEDULE` is a string formatted exactly the same as would appear on the parallel construct. |

### Compile

Use the script `compile`
```
$ ./compile
```

Or Compile Manually
```
$ gcc -fopenmp black_white.c -o black_white.o -lgd
$ gcc -fopenmp black_white_static.c -o black_white_static.o -lgd
$ gcc -fopenmp black_white_dynamic.c -o black_white_dynamic.o -lgd
$ gcc -fopenmp black_white_guided.c -o black_white_guided.o -lgd
```

### Run

Example run for `Default Scheduling` - `black_white.c`

```
$ ./black_white.o image-640.png output-640.png

File Size: 640x480
Time Taken: 8.740ms
```

### Run Summary
> Result depends on machine

<table>
  <tr>
    <th></th>
    <th colspan="4"><center>Scheduling Techniques (Time in ms)</center></th>
  </tr>
  <tr>
    <th rowspan="2">Image Size</th>
  </tr>
  <tr align="right">
    <td>Default</td>
    <td>Static</td>
    <td>Dynamic</td>
    <td>Guided</td>
  </tr>
  <tr align="right">
    <td>640x480 (432K)</td>
    <td>8.764</td>
    <td>6.613</td>
    <td>7.911</td>
    <td>6.85</td>
  </tr>
  <tr align="right">
    <td>1024x728 (1.2M)</td>
    <td>22.386</td>
    <td>13.679</td>
    <td>20.911</td>
    <td>27.52</td>
  </tr>
  <tr align="right">
    <td>1600x1200 (2.5M)</td>
    <td>34.760</td>
    <td>37.86</td>
    <td>39.327</td>
    <td>33.641</td>
  </tr>
  <tr align="right">
    <td>2272x1704 (5.0M)</td>
    <td>67.136</td>
    <td>67.478</td>
    <td>70.351</td>
    <td>67.851</td>
  </tr>
</table>
