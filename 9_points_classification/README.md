# Points Classification
> Parallel program for Points Classification

### Compile

Use the script `compile`
```
$ ./compile
```

or compile manually
```
$ g++ -fopenmp points_classification.cpp -o points_classification.o -lm
```

### Run
Example run for `num_points = 10^5` & `num_threads = 4`

```
$ ./points_classification.o 100000 4
Time Taken: 7.21407ms
```

### Run Summary
> Result depends on machine

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
    <td>10.79</td>
    <td>7.49</td>
    <td>6.71</td>
    <td>8.21</td>
  </tr>
  <tr align="right">
    <td>10<sup>6</sup></td>
    <td>92.91</td>
    <td>72.93</td>
    <td>63.32</td>
    <td>60.85</td>
  </tr>
  <tr align="right">
    <td>10<sup>7</sup></td>
    <td>1003.43</td>
    <td>729.13</td>
    <td>587.77</td>
    <td>600.76</td>
  </tr>
  <tr align="right">
    <td>10<sup>8</sup></td>
    <td>10108</td>
    <td>7312</td>
    <td>6110</td>
    <td>6528</td>
  </tr>
</table>
