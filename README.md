# Incremental Residue‑Class Prime Generator (C++)

## Overview
This repository contains a C++ implementation of an **incremental residue‑class method for generating prime numbers**, a technique that operates **without division, multiplication, or explicit modulo computations**.  
Instead, each natural number is represented through a residue‑class vector over all known primes, and all residues are incremented when transitioning from \(n\) to \(n+1\).

The method is:

- Fully incremental  
- State‑lean and indefinitely extensible  
- Extremely simple to implement  
- Suitable for streaming and embedded environments  
- Conceptually different from classical sieving techniques  

It is based on the paper:

**“Incremental Residue‑Class Method for Generating Prime Numbers” (2026)**  
by Ralf Sieg.

---

## Key Features
- Prime generation without modulo, division, or multiplication  
- Pure incremental update rule  
- One residue position per known prime  
- Simple and compact C++ implementation  
- Clear mathematical foundation  
- Includes complexity analysis and comparison with classical methods

---

## Documentation

The algorithm description is available in two languages:
- [English PDF](docs/Incremental%20Residue‑Class%20Method%20for%20Generating%20Prime%20Numbers.pdf)
- [German PDF](docs/Inkrementelles%20Restklassen%E2%80%91Verfahren%20zur%20Erzeugung%20von%20Primzahlen.pdf)

---

## Motivation
Classical prime sieves (e.g., the sieve of Eratosthenes) are extremely fast but **not incremental**.  
This project explores a fundamentally different approach: a **streaming‑friendly**, **state‑lean**, incremental method that updates only residue values.

This makes the algorithm ideal for:

- Embedded systems  
- Streaming pipelines  
- Educational demonstrations  
- Conceptual exploration of number systems  
- Low‑state computation scenarios  

---

## Algorithm Summary

### Residue‑Class Vector
For each known prime \(p\), the algorithm stores:



\[
n \bmod p
\]



When moving from \(n\) to \(n+1\):



\[
(n+1) \bmod p = (n \bmod p + 1) \bmod p
\]



Thus:

- All positions increment by 1  
- Overflow wraps to “0”  
- A number is **prime** if **no residue becomes “0”**  
- When a new prime is found, a new position is added (starting at “0”)

---

## Example Table

| Decimal | 2 | 3 | 5 | 7 | 11 |
|--------|---|---|---|---|----|
| 2 | 0 |   |   |   |   |
| 3 | 1 | 0 |   |   |   |
| 4 | 0 | 1 |   |   |   |
| 5 | 1 | 2 | 0 |   |   |
| 6 | 0 | 0 | 1 |   |   |
| 7 | 1 | 1 | 2 | 0 |   |
| 8 | 0 | 2 | 3 | 1 |   |
| 9 | 1 | 0 | 4 | 2 |   |
| 10 | 0 | 1 | 0 | 3 |   |
| 11 | 1 | 2 | 1 | 4 | 0 |

---

## Complexity

### Time Complexity


\[
T(N) = O\!\left(\frac{N^2}{\ln N}\right)
\]



### Space Complexity


\[
S(N) = O\!\left(\frac{N}{\ln N}\right)
\]



### Comparison

| Method | Time | Space | Notes |
|--------|------|--------|-------|
| Incremental residue‑class method | \(O(N^2 / \ln N)\) | \(O(N / \ln N)\) | Simple, incremental, no division |
| Sieve of Eratosthenes | \(O(N \log\log N)\) | \(O(N)\) | Very fast, not incremental |
| Trial division | \(O(N \sqrt{N})\) | \(O(1)\) | Very slow |
| Segmented sieve | \(O(N \log\log N)\) | \(O(N)\) | Memory‑optimized |

---

## Strengths
- No division, multiplication, or modulo  
- Fully incremental  
- Indefinitely extensible  
- Very simple implementation  
- Ideal for streaming and embedded systems  

---

## Weaknesses
- Asymptotically slower than modern sieves  
- Not competitive for very large ranges  

---

## Example Code

The C++ example demonstrating the algorithm can be found here:

- `src/p1.cpp`
- `include/Counter.h`
- `include/DecimalCounter.h`

p1.cpp contains main() function and illustrates how the algorithm can be applied.
The example is serves as a usage illustration. It uses a class 'CBase256Counter'
holding digits in base 256 system to save storage space and for better performance.

---

## License

- Documentation: **Creative Commons Attribution 4.0 International (CC BY 4.0)**  
  See: `docs/LICENSE-DOCUMENTATION`

- Example code: **MIT License**  
  See: `LICENSE`
