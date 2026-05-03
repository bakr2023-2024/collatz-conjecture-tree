# Collatz Conjecture Tree

## What is the Collatz Conjecture?

Take any positive integer. If it's even, divide it by 2. If it's odd, multiply it by 3 and add 1. Repeat. The conjecture states that no matter what number you start with, you will always eventually reach 1. Simple to state, yet unproven for nearly a century.

## Visualization

This program uses **Edmund Harriss's visualization method** ([video](https://www.youtube.com/watch?v=LqKpkdRRLZw)) to draw all Collatz sequences from 2 up to N as a tree:

- Start at a fixed point, facing up
- For each step in the sequence, if the next value is double the current value (i.e. the step was a division by 2), rotate right by `2θ`; otherwise rotate left by `θ`
- Draw a line segment in the current direction

Sequences that share a common path from the root naturally overlap, forming the trunk and branches of the tree.

## Build

Requires [raylib](https://www.raylib.com/) to be installed.

```bash
make main
```

## Usage

```bash
./main [branches] [background] [color] [length] [thickness]
```

All arguments are optional and positional:

| Argument | Description | Default |
|----------|-------------|---------|
| `branches` | How many Collatz sequences to draw (from 2 to N) | `2500` |
| `background` | Background color as hex (e.g. `0x000000`) | Black |
| `color` | Branch color as hex (e.g. `0xFFFFFF`) | White |
| `length` | Length of each line segment | `7.0` |
| `thickness` | Line thickness | `1.0` |

## Examples

```bash
# Default
./main

# 5000 branches, white on black
./main 5000

# Teal branches on dark background
./main 2500 0x0a0a0a 0x4DB8C8

# Thin long branches
./main 2500 0x000000 0xFFFFFF 12.0 0.5
```
