# Negative Image

> Program to find the negative of an image to demonstrate <br>
> *a) Use default data scope variables* <br>
> *b) Use Critical section to prove correctness using default data scope variables* <br><br>
> **Input**: Image in `png` format<br>
> **Output**: Negative of give Image

#### Note

Make sure `libgd2` is installed

For **Ubuntu**
```
$ sudo apt-get install libgd2-xpm-dev
```

For **macOS**, Use `homebrew`
```
$ brew install gd
```

### Compile

Use the script `compile`
```
$ ./compile
```

or compile manually
```
$ gcc -fopenmp negative.c -o negative.o -lgd
$ gcc -fopenmp negative_critical.c -o negative_critical.o -lgd
```

### Run

#### Default data scope

```
$ ./negative.o input.png output.png 4

File Size: 620x387
Time Taken: 5.664ms
```

**Input Image**

![input](input.png)

**Output Image**

![input](output.png)

#### Critical Section

```
$ ./negative_critical.o input.png output.png 4

File Size: 620x387
Time Taken: 10.682ms
```

### What's the difference in `Critical Section`?

`#pragma omp critical` scope is added to inner for loop

Let's get the `diff`

```diff
$ diff negative.c negative_critical.c

35,43c35,46
- 		for(y=0; y<height; y++) {
- 		    color = x + 0;
- 		    color = gdImageGetPixel(img, x, y);
- 		    red   = 255 - gdImageRed(img, color);
- 		    green = 255 - gdImageGreen(img, color);
- 		    blue  = 255 - gdImageBlue(img, color);
- 		    color = gdImageColorAllocate(img, red, green, blue);
- 		    gdImageSetPixel(img, x, y, color);
- 		}
---
+         #pragma omp critical
+         {
+     		for(y=0; y<height; y++) {
+     		    color = x + 0;
+     		    color = gdImageGetPixel(img, x, y);
+     		    red   = 255 - gdImageRed(img, color);
+     		    green = 255 - gdImageGreen(img, color);
+     		    blue  = 255 - gdImageBlue(img, color);
+     		    color = gdImageColorAllocate(img, red, green, blue);
+     		    gdImageSetPixel(img, x, y, color);
+     		}
+         }
```

### Run Summary
> Result depends on machine <br>
> * With `Data scope variables`, Parallelization produces correct output <br>
> * With `Critical Section`, Program produces correct output, but serializes the program as ***only one thread*** at a time can execute critical section code

<table>
  <tr>
    <th></th>
    <th colspan="2"><center>Time Taken (ms)</center></th>
  </tr>
  <tr>
    <th>No. of threads</th>
    <th><center>Data scope</center></th>
    <th><center>Critical Section</center></th>
  </tr>

  <tr align="right">
    <td>1</td>
    <td>11.539</td>
    <td>9.804</td>
  </tr>

  <tr align="right">
    <td>2</td>
    <td>5.932</td>
    <td>10.256</td>
  </tr>

  <tr align="right">
    <td>4</td>
    <td>5.863</td>
    <td>10.648</td>
  </tr>

  <tr align="right">
    <td>8</td>
    <td>6.422</td>
    <td>20.345</td>
  </tr>

</table>
