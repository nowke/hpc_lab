# Multitasking
> Program to demonstrate how **multitasking** works by implementing two separate tasks, one to generate ***Prime Table*** and other to generate ***Sine Table*** for a given `upper_bound`

### Compile

Use the script `compile`
```
$ ./compile
```

or compile manually
```
$ g++ -fopenmp multitask.cpp -o multitask.o -lm
```

### Run
Example run for **Sequential Execution of tasks** - `upper_bound = 10000`, `num_threads = 1`

```
$ ./multitask.o 10000 1

Largest Prime: 104729
Largest Sine: 6365.56
Total Time: 3134.7ms
Task 1 Time: 2116.79ms
Task 2 Time: 1017.75ms
```

Example run for **Parallel Execution of sections** - `upper_bound = 10000`, `num_threads = 2`

```
$ ./multitask.o 10000 2

Largest Prime: 104729
Largest Sine: 6365.56
Total Time: 2262.35ms
Task 1 Time: 2261.94ms
Task 2 Time: 941.463ms
```

### Run Summary
> Result depends on machine


<table>
  <tr>
    <th></th>
    <th colspan="6"><center>Time Taken (s)</center></th>
  </tr>
  <tr>
    <th rowspan="2">Input Size</th>
    <th colspan="3"><center>Sequential (num_threads=1)</center></th>
    <th colspan="3"><center>Section(num_threads=2)</center></th>
  </tr>
  <tr align="right">
    <td>Total</td>
    <td>Task 1</td>
    <td>Task 2</td>
    <td>Total</td>
    <td>Task 1</td>
    <td>Task 2</td>
  </tr>
  <tr align="right">
    <td>15000</td>
    <td>14.29</td>
    <td>10.11</td>
    <td>4.18</td>
    <td>10.95</td>
    <td>10.95</td>
    <td>4.63</td>
  </tr>
  <tr align="right">
    <td>20000</td>
    <td>12.88</td>
    <td>9.31</td>
    <td>3.56</td>
    <td>9.59</td>
    <td>9.59</td>
    <td>3.51</td>
  </tr>
  <tr align="right">
    <td>25000</td>
    <td>34.57</td>
    <td>23.08</td>
    <td>11.49</td>
    <td>31.48</td>
    <td>31.48</td>
    <td>13.18</td>
  </tr>
  <tr align="right">
    <td>30000</td>
    <td>36.57</td>
    <td>22.17</td>
    <td>14.40</td>
    <td>42.42</td>
    <td>42.42</td>
    <td>15.78</td>
  </tr>
</table>
