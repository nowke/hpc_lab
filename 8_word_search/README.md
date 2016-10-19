# Word Search

> Parallel program for Word search in a file

### Compile

Use the script `compile`
```
$ ./compile
```

or compile manually
```
$ g++ -fopenmp search.cpp -o search.o
```

### Run
Example Run `filesize: 4.8M`, `num_threads=8`

```
$ ./search.o words4.txt 16

the: 211680
around: 84672
graphics: 84672
from: 84672
by: 42336
be: 127009
any: 127008
mount: 84672
hello: 84672
word: 84672

Time: 804.414ms
```

### Run Summary
> Result depends on machine

<table>
  <tr>
    <th></th>
    <th colspan="4"><center>Time Taken (ms)</center></th>
  </tr>
  <tr>
    <th rowspan="2">Input File Size</th>
    <th colspan="4"><center>No.of Threads</center></th>
  </tr>
  <tr align="right">
    <td>1</td>
    <td>2</td>
    <td>4</td>
    <td>8</td>
  </tr>
  <tr align="right">
    <td>310K</td>
    <td>90.73</td>
    <td>74.43</td>
    <td>79.61</td>
    <td>71.02</td>
  </tr>
  <tr align="right">
    <td>930K</td>
    <td>229.01</td>
    <td>192.69</td>
    <td>158.16</td>
    <td>177.99</td>
  </tr>
  <tr align="right">
    <td>1.5M</td>
    <td>380.11</td>
    <td>288.96</td>
    <td>283.81</td>
    <td>368.11</td>
  </tr>
  <tr align="right">
    <td>4.8M</td>
    <td>2184.11</td>
    <td>936.14</td>
    <td>879.24</td>
    <td>825.35</td>
  </tr>
</table>
