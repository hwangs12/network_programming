/*
 * A dynamical polynomial is a monic polynomial f(x) with integer coefficients such that f(x) divides f(x^2 - 2).
 * For example, f(x) = x^2 - x - 2 is a dynamical polynomial because f(x^2 - 2) = x^4 - 5x^2 + 4 = (x^2 + x - 2)f(x).
 * Let S(n) be the number of dynamical polynomials of degree n.
 * For example, S(2) = 6 as there are six dynamical polynomials of degree 2:
 * x^2 - 4x + 4, x^2 - x - 2, x^2 - 4, x^2 - 1, x^2 + x - 1, x^2 + 2x + 1
 * Also, S(5) = 58 and S(20) = 122087.
 * Find S(10000).
 * Give your answer modulo 9982444353.
 */