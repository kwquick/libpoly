/*
 * dyadic_rational.h
 *
 *  Created on: Jan 22, 2014
 *      Author: dejan
 */

#pragma once

#include "poly.h"

#include <stdio.h>
#include <gmp.h>

#include "integer.h"

/**
 * Fraction of the form a/2^n, with n non-negative. The fraction is reduced, i.e.
 * if n is positive a is not divisible by 2.
 */
typedef struct {
  lp_integer_t a;
  unsigned long n;
} lp_dyadic_rational_t;

/**
 * Construct rational 0/1.
 */
void lp_dyadic_rational_construct(lp_dyadic_rational_t* q);

/**
 * Construct rational a*2^n.
 */
void lp_dyadic_rational_construct_from_int(lp_dyadic_rational_t* q, long a, unsigned long n);

/**
 * Construct rational a/1.
 */
void lp_dyadic_rational_construct_from_integer(lp_dyadic_rational_t* q, const lp_integer_t* a);


/**
 * Construct the dyadic representation of x.
 */
void lp_dyadic_rational_construct_from_double(lp_dyadic_rational_t* q, double x);

/**
 * Construct a copy.
 */
void lp_dyadic_rational_construct_copy(lp_dyadic_rational_t* q, const lp_dyadic_rational_t* from);

/**
 * Assign the given value.
 */
void lp_dyadic_rational_assign(lp_dyadic_rational_t* q, const lp_dyadic_rational_t* from);

/**
 * Assign the rational a given a*2^n
 */
void lp_dyadic_rational_assign_int(lp_dyadic_rational_t* q, long a, unsigned long n);

/**
 * Deallocates the number.
 */
void lp_dyadic_rational_destruct(lp_dyadic_rational_t* q);

/**
 * Prints the number to the given stream.
 */
int lp_dyadic_rational_print(const lp_dyadic_rational_t* c, FILE* out);

/**
 * Returns the string representation of the number.
 */
char* lp_dyadic_rational_to_string(const lp_dyadic_rational_t* q);

/**
 * Return the double representation of the rational.
 */
double lp_dyadic_rational_to_double(const lp_dyadic_rational_t* q);

/**
 * Returns the sign of the rational.
 */
int lp_dyadic_rational_sgn(const lp_dyadic_rational_t* q);

/**
 * Compare the two numbers.
 */
int lp_dyadic_rational_cmp(const lp_dyadic_rational_t* q1, const lp_dyadic_rational_t* q2);

/**
 * Swap two numbers.
 */
void lp_dyadic_rational_swap(lp_dyadic_rational_t* q1, lp_dyadic_rational_t* q2);

/**
 * Compute sum = a + b.
 */
void lp_dyadic_rational_add(lp_dyadic_rational_t* sum, const lp_dyadic_rational_t* a, const lp_dyadic_rational_t* b);

/**
 * Compute sum = a + b.
 */
void lp_dyadic_rational_add_integer(lp_dyadic_rational_t* sum, const lp_dyadic_rational_t* a, const lp_integer_t* b);

/**
 * Compute sub = a - b.
 */
void lp_dyadic_rational_sub(lp_dyadic_rational_t* sub, const lp_dyadic_rational_t* a, const lp_dyadic_rational_t* b);

/**
 * Compute neg = -a.
 */
void lp_dyadic_rational_neg(lp_dyadic_rational_t* neg, const lp_dyadic_rational_t* a);

/**
 * Compute product = a * b.
 */
void lp_dyadic_rational_mul(lp_dyadic_rational_t* mul, const lp_dyadic_rational_t* a, const lp_dyadic_rational_t* b);

/**
 * Compute product = a*2^n
 */
void lp_dyadic_rational_mul_2exp(lp_dyadic_rational_t* mul, const lp_dyadic_rational_t* a, unsigned long n);

/**
 * Compute power = a^n in the given ring.
 */
void lp_dyadic_rational_pow(lp_dyadic_rational_t* pow, const lp_dyadic_rational_t* a, unsigned long n);

/**
 * Compute div = a/2^n
 */
void lp_dyadic_rational_div_2exp(lp_dyadic_rational_t* div, const lp_dyadic_rational_t* a, unsigned long n);

