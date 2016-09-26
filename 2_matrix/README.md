# Matrix Multiplication

### Compile

Use the script `compile`
```
$ ./compile
```

or compile manually
```
$ gcc -fopenmp matrix.c -o matrix.o
```

### Run
Example Run: `matrix_size = 250`, `num_threads = 4`

```
$ ./matrix.o 250 4
Time Taken: 62.172174 ms
```

### Run Summary
> Result depends on machine

<table>
  <tr>
    <th></th>
    <th colspan="4"><center>Time Taken (ms)</center></th>
  </tr>
  <tr>
    <th rowspan="2">Input Size</th>
    <th colspan="4"><center>No.of Threads</center></th>
  </tr>
  <tr align="right">
    <td>1</td>
    <td>2</td>
    <td>4</td>
    <td>8</td>
  </tr>
  <tr align="right">
    <td>250</td>
    <td>125</td>
    <td>68</td>
    <td>62</td>
    <td>61</td>
  </tr>
  <tr align="right">
    <td>500</td>
    <td>1397</td>
    <td>725</td>
    <td>662</td>
    <td>653</td>
  </tr>
  <tr align="right">
    <td>750</td>
    <td>5104</td>
    <td>2540</td>
    <td>2282</td>
    <td>2370</td>
  </tr>
  <tr align="right">
    <td>1000</td>
    <td>28795</td>
    <td>20368</td>
    <td>12607</td>
    <td>11905</td>
  </tr>
</table>
