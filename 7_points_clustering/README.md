# Points Clustering
> Parallel program for Points Clustering

### Compile

Use the script `compile`
```
$ ./compile
```

or compile manually
```
$ g++ -fopenmp points_clustering.cpp -o points_clustering.o -lm
```

### Run
Example run for `num_points = 10^5` & `num_threads = 4`

```
$ ./points_clustering.o 100000 4
Time Taken: 487.706ms
```

### Run Summary
> Result depends on machine

> Tested in Amazon EC2 - `m4.xlarge`, `16GiB RAM`

<table>
  <tr>
    <th></th>
    <th colspan="4"><center>Time Taken (ms)</center></th>
  </tr>
  <tr>
    <th rowspan="2">No.of Points</th>
    <th colspan="4"><center>No.of Threads</center></th>
  </tr>
  <tr align="right">
    <td>1</td>
    <td>2</td>
    <td>4</td>
    <td>8</td>
  </tr>
  <tr align="right">
    <td>10<sup>5</sup></td>
    <td>4.52</td>
    <td>19.70</td>
    <td>29.24</td>
    <td>4.88</td>
  </tr>
  <tr align="right">
    <td>10<sup>6</sup></td>
    <td>45.36</td>
    <td>188.44</td>
    <td>174.36</td>
    <td>214.78</td>
  </tr>
  <tr align="right">
    <td>10<sup>7</sup></td>
    <td>455.75</td>
    <td>2124</td>
    <td>2151</td>
    <td>1898</td>
  </tr>
  <tr align="right">
    <td>10<sup>8</sup></td>
    <td>5090</td>
    <td>21092</td>
    <td>27428</td>
    <td>23404</td>
  </tr>
</table>

> As the number of threads is increased, program takes more time. This behavior is because, of the `Critical Section` inside the for loop. On removing the Critical section, program produces wrong output, as the operation present in the same, depends on previous iterations.
