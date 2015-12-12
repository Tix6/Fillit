# Fillit

## Description
School's project about tetris game algorithm
### input
One file of a list of tetriminos, one new line between each.
Each tetriminos blocks must be in contact with at least one another block on one of his sides, in order to be considered valid.

Example : 
```
$ cat -e valid_sample.fillit
...#$
...#$
...#$
...#$
$
....$
....$
....$
####$
$
.###$
...#$
....$
....$
$
....$
..##$
.##.$
....$
$>
```
### output
The smallest square filled by these tetriminos on the stdout.
Each tetriminos is replaced by a letter. Beginning by A.

Example :
```
$> cat sample.fillit | cat -e
...#$
...#$
...#$
...#$
$
....$
....$
....$
####$
$
.###$
...#$
....$
....$
$
....$
..##$
.##.$
....$
$
....$
.##.$
.##.$
....$
$
....$
....$
##..$
.##.$
$
##..$
.#..$
.#..$
....$
$
....$
###.$
.#..$
....$
$> ./fillit sample.fillit | cat -e
ABBBB.$
ACCCEE$
AFFCEE$
A.FFGG$
HHHDDG$
.HDD.G$
$>
```

## Constraints
### Authorized functions
exit, open, close, write, read, malloc, free.
### Timeout
Few minutes
### Input max.
26 tetriminos.

