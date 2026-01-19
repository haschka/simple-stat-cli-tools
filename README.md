# simple-stat-cli-tools
Provides Mean / Stddev / Histrogram / Random Sampling 
and more from the cli

compile with:
```
gcc -O2 -march=native histogram.c -o histogram -lm 
gcc -O2 -march=native mean.c -o mean -lm 
gcc -O2 -march=native stddev.c -o stddev -lm 
gcc -O2 -march=native median.c -o median -lm 
gcc -O2 -march=native minimum.c -o minimum -lm 
gcc -O2 -march=native maximum.c -o maximum -lm 
gcc -O2 -march=native linearregression.c -o linearregression -lm
gcc -O2 -march=native correlate.c -o correlate -lm 
gcc -O2 -march=native random_sample.c -o random_sample -lm 
```
use like:
```
echo "13 43 13 34 31 22 30" | ./histgroam 3
```
to get a histogram of three bins for the values sent.
```
echo "13 43 13 34 31 22 30" | ./mean
```
to get the mean of the numbers.
```
echo "13 43 13 34 31 22 30" | ./median
```
to obtain the median of the numbers.
```
echo "13 43 13 34 31 22 30" | ./stddev
```
to obtain the standard deviation of the numbers.
```
echo "13 43 13 34 31 22 30" | ./minimum
```
to obtain the minimum of the numbers.
```
echo "13 43 13 34 31 22 30" | ./maximum
```
to obtain the maximum of the numbers.
```
echo "1. 3. 0.5 1.5 5. 8." | ./correlate
```
to obtain the pearson correlation between the vectors:
`1. 0.5 5.` and `3. 1.5 8`.
```
echo "1. 3. 0.5 1.5 5. 8." | ./cossimilarity
```
to obtain the cosine similarity between the vectors:
`1. 0.5 5.` and `3. 1.5 8`.
```
echo "1. 0.5 2. 0.9 3. 1.2" | ./linearregression
```
to obtain the linear regression through the points 
`(1., 0.5)`, `(2.,0.9)` and `(3., 1.2)`

```
echo "مرحبا Bonjour GutenTag Buongiorno" | ./randomsample 42 2
```
to obtain two random greetings from the four provided, 
under the given seed 42.

You can yield numbers/objects to the tools that are separated by newlines,
tabs or spaces. 
Gentoo users might install the tools with the provided ebuild: 
`stattools-1.ebuild`

