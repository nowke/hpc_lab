# Sieve of Eratosthenes - Cache

> Program for Cache Unfriendly Sieve of Eratosthenes and Cache Friendly Sieve of Eratosthenes for enumerating prime numbers upto N

### Compile

Use the script `compile`
```
$ ./compile
```

or compile manually
```
$ g++ -fopenmp cache_friendly.cpp -o cache_friendly.o
```

### Run
Example Run: `N = 10^8`

```
$ ./cache_friendly.o 100000000

Cache Unfriendly Sieve -> Time: 2282.56ms
Cache Friendly Sieve -> Time: 763.042ms
```

### Run Summary
> Result depends on machine

<table>
  <tr>
    <th></th>
    <th colspan="2"><center>Time Taken (ms)</center></th>
  </tr>
  <tr>
    <th>Input Size</th>
    <th><center>Cache Unfriendly Sieve</center></th>
    <th><center>Cache Friendly Sieve</center></th>
  </tr>

  <tr align="right">
    <td>10<sup>6</sup></td>
    <td>13.07</td>
    <td>8.2</td>
  </tr>

  <tr align="right">
    <td>10<sup>7</sup></td>
    <td>179.78</td>
    <td>68.9</td>
  </tr>

  <tr align="right">
    <td>10<sup>8</sup></td>
    <td>2218.48</td>
    <td>737.60</td>
  </tr>

  <tr align="right">
    <td>10<sup>9</sup></td>
    <td>26693.70</td>
    <td>7939.83</td>
  </tr>

</table>

### Reference
* Sieve of Eratosthenes - [GeeksforGeeks](http://www.geeksforgeeks.org/sieve-of-eratosthenes/)
* Segmented Sieve (Cache Friendly) - [GeeksforGeeks](http://www.geeksforgeeks.org/segmented-sieve/)
