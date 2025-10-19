/*
 * Exercise 1: Taylor Series Approximation for Sine Function
 * Assignment 7 - IPFCE 2025
 * 
 * Implement the taylor_sine function that calculates the sine of x
 * using Taylor series approximation with n terms.
 * 
 * Taylor series for sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 */

#include "taylor_sine.h"

/* 
 * udregning af sin ved brug af Taylor series approximation
 * x: input af funktionen i radianer
 * n: nummer af terms i funktionen
 * Returns: approximation af sin(x)
 */
double taylor_sine(double x, int n) {
    double result = 0.0;
    double term = x; // First term is x
    int sign = 1; // starter positivt

    for (int i = 1; i <= n; i++) {
        result += sign * term; // tilføjer current term til result
        // udregner næste term i serien
        term = term * x * x / ((2 * i) * (2 * i + 1)); // x^(2i+1) / (2i+1)!
        sign = -sign; // skifter fortegn
    }

    return result;
}