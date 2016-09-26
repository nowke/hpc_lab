# PI Calculation

### Compile

Use the script `compile`
```
$ ./compile
```

or compile manually
```
$ gcc -fopenmp pi_calculation.c -o pi_calculation.o
```

### Run
Example Run: With `intervals = 10^7` & `num_threads = 4`

```
$ ./pi_calculation 10000000 4

Actual PI: 3.141592653883721
Calculated PI: 3.141592253589669
Error: 0.000000400294052
Time taken: 25.794029 ms
```

### Run Summary
> Result depends on machine

<table>
  <tr>
    <th></th>
    <th colspan="4"><center>Time Taken (ms)</center></th>
  </tr>
  <tr>
    <th rowspan="2">Intervals</th>
    <th colspan="4"><center>No.of Threads</center></th>
  </tr>
  <tr>
    <td>1</td>
    <td>2</td>
    <td>4</td>
    <td>8</td>
  </tr>
  <tr>
    <td>10^7</td>
    <td>47.28</td>
    <td>21.46</td>
    <td>18.74</td>
    <td>19.19</td>
  </tr>
  <tr>
    <td>10^8</td>
    <td>383.92</td>
    <td>186.95</td>
    <td>176.68</td>
    <td>177.93</td>
  </tr>
  <tr>
    <td>10^9</td>
    <td>3739</td>
    <td>1898</td>
    <td>1751</td>
    <td>1772</td>
  </tr>
</table>
