# Exercise 1: Implement Euclid's Algorithm for finding the greatest common divisor of two integers
def gcd(a, b):
# Provide the correct implementation
    x = a
    y = b

    while (y != 0):
        r = x % y
        x = y
        y = r
    return x

print gcd(128, 60)
# Expected output: 4

# Exercise 2: Consider the following representation of mathematical expressions: a list of tuples, where each tuple has exactly 2 elements, a coefficient and a term. For example, the expression:
# 2x + 5y - 3z is represented as [(2, x), (5, y), (-3, z)]
# We sometimes need to simplify expressions by grouping together like terms. For example:
# 2x + 5y + 4x = 6x + 5y
# Implement the function groupLikeTerms, where the input exp is a mathematical expression represented as a list of tuples, and it should return a simplified mathematical expression represented as a list of tuples.
def groupLikeTerms(exp):
# Provide the correct implementation
    newList = []
    for i in range(0, len(exp)):
        newSum = exp[i][0]
        newLetter = exp[i][1]

        for j in range(i + 1, len(exp)):
            if(exp[i][1] == exp[j][1]):
                newSum += exp[j][0]

        tuple = (newSum, newLetter)

        k = i - 1
        doNotInclude = False
        while(k >= 0):
            if(exp[i][1] == exp[k][1]):
                doNotInclude = True
            k = k - 1
        if(doNotInclude == False):
             newList.append(tuple)
    return newList

print groupLikeTerms([(5, "x"), (5, "y"), (-3, "x")])
# Expected output: [(2, 'x'), (5, 'y')]

# Exercise 3: We sometimes need to substitute expressions into other expressions. For example if we have the expression 2x + 5y, and we know that x = 3a - b, we can substitute the expression for x into the original expression, resulting in: 6a - 2b + 5y.
# Implement the substitution function below. It should take an expression (list of tuples), a term, and another expression. It should substitute the occurences of term in exp, with value. The result should be in its simplest form, i.e. like terms should be grouped together
# For example: substitute([(2, 5), (-1, 9)], 5, [(1, 23), (-2, 9)]) results in [(-5, 9), (2, 23)]
def substitute(exp, term, value):
    # Provide the correct implementation
    newList = []

    for i in range(0, len(exp)):
        a = exp[i][0]
        b = exp[i][1]

        if(b == term):
            for j in range(0, len(value)):
                alpha = a * value[j][0]

                tuple = (alpha, value[j][1])
                newList.append(tuple)
        else:
            tuple = (a, b)
            newList.append(tuple)
    return(groupLikeTerms(newList))

print substitute([(2, 5), (-1, 9)], 5, [(1, 23), (-2, 9)])
# Expected output: [(-5, 9), (2, 23)]


# Exercise 4: Using the functions you implemented above, implement the Extended Euclidean Algorithm, which returns the GCD of two integers a, and b, as a linear combination of a and b.
# For example: extended_euclid(101, 23) results in (1, [(22, 23), (-5, 101)]), where the GCD is 1 and it can be expressed as 22*23 - 5*101
def extended_euclid(a, b):
# Provide the correct implementation
    acopy,bcopy = a , b
    x0,x1,y0,y1 = 1,0,0,1

    while b != 0:
        q,a,b = a // b, b, a % b
        x0,x1 = x1, x0 - q * x1
        y0,y1 = y1, y0 - q * y1
    return a,[y0,bcopy], [x0,acopy]

print extended_euclid(101, 23)

# Expected output: (1, [(22, 23), (-5, 101)])

# Exercise 5: Use the Extended Euclidean Algorithm to implement the function for multiplicative inverses. As you know, a multiplicative inverse n modulo m is guaranteed to exist if n and m are relatively prime. If they are not, your algorithm should return None (which is the null value of Python), otherwise, if n and m are relatively prime, you should return the inverse of n modulo m.
def inverse(n, m):
# Provide the correct implementation
    gcd,x,y = extended_euclid_gcd(n,m)
    if x < 0:
        x += m
    return x

def extended_euclid_gcd(a,b):
    s = 0; old_s = 1
    t = 1; old_t = 0
    r = b; old_r = a

    while r != 0:
        quotient = old_r/r

        old_r, r = r, old_r - quotient * r
        old_s, s = s, old_s - quotient * s
        old_t, t = t, old_t - quotient * t

    return [old_r, old_s, old_t]

print inverse(23, 101)

# Expected output: 22
