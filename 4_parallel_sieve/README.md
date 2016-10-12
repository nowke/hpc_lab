# Parallel Sieve

> Program for Cache Friendly Sieve of Eratosthenes and Cache Friendly Parallel Sieve of Eratosthenes for enumerating prime numbers upto N

### compile

Use the script `compile`
```
$ ./compile
```

or compile manually
```
$ g++ -fopenmp parallel_sieve.cpp -o parallel_sieve.o
```

### Run
Example Run: `N = 10^8` and `num_threads = 4`

```
$ ./parallel_sieve.o 100000000 4

Cache Friendly Sieve -> Time: 1085.37ms, Count = 5761455
Parallel Sieve -> Time: 419.285ms, Count = 5761455
```

### Run Summary
> Result depends on machine, `num_threads = 4`

<table>
  <tr>
    <th></th>
    <th colspan="2"><center>Time Taken (ms)</center></th>
  </tr>
  <tr>
    <th>Input Size</th>
    <th><center>Cache Friendly Sieve</center></th>
    <th><center>Parallel Sieve</center></th>
  </tr>

  <tr align="right">
    <td>10<sup>6</sup></td>
    <td>10.95</td>
    <td>4.44</td>
  </tr>

  <tr align="right">
    <td>10<sup>7</sup></td>
    <td>100.22</td>
    <td>42.603</td>
  </tr>

  <tr align="right">
    <td>10<sup>8</sup></td>
    <td>1105.14</td>
    <td>400.74</td>
  </tr>

  <tr align="right">
    <td>10<sup>9</sup></td>
    <td>10949.20</td>
    <td>4167.44</td>
  </tr>

</table>
