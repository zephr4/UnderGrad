# Exercise 1: Implement Euclid's Algorithm for finding the greatest common divisor of two integers
def gcd(a, b):
    # Provide the correct implementation
	
	x = a
	y = b
	
	while (y != 0):
		rem = x % y 
		x = y 
		y = rem
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
	
	newExp = []
	
	for i in range(0, len(exp)):
		num = exp[i][0]
		letter = exp[i][1]
		
		for j in range(i + 1, len(exp)):
			if (exp[i][1] == exp[j][1]):
				num = num + exp[j][0]
				
		newTuple = (num, letter)
		
		n = i - 1
		Append = True
		while (n >= 0):
			if (exp[i][1] == exp[n][1]):
				Append = False
			n = n - 1
		if (Append == True):
			newExp.append(newTuple)
		
	return newExp
    
print groupLikeTerms([(5, "x"), (5, "y"), (-3, "x")])
# Expected output: [(2, 'x'), (5, 'y')]


    
# Exercise 3: We sometimes need to substitute expressions into other expressions. For example if we have the expression 2x + 5y, and we know that x = 3a - b, we can substitute the expression for x into the original expression, resulting in: 6a - 2b + 5y.

# Implement the substitution function below. It should take an expression (list of tuples), a term, and another expression. It should substitute the occurences of term in exp, with value. The result should be in its simplest form, i.e. like terms should be grouped together 

# For example: substitute([(2, 5), (-1, 9)], 5, [(1, 23), (-2, 9)]) results in [(-5, 9), (2, 23)]
def substitute(exp, term, value):
    # Provide the correct implementation
	
	newExp = []
	
	for i in range(0, len(exp)):
		x = exp[i][0]
		y = exp[i][1]
		
		if (y == term):
			for j in range(0, len(value)):
				result = x * value[j][0]
				newTuple = (result, value[j][1])
				newExp.append(newTuple)
		else:
			newTuple = (x, y)
			newExp.append(newTuple)
			
	return groupLikeTerms(newExp)
            
print substitute([(2, 5), (-1, 9)], 5, [(1, 23), (-2, 9)])
# Expected output: [(-5, 9), (2, 23)]



# Exercise 4: Using the functions you implemented above, implement the Extended Euclidean Algorithm, which returns the GCD of two integers a, and b, as a linear combination of a and b.

# For example: extended_euclid(101, 23) results in (1, [(22, 23), (-5, 101)]), where the GCD is 1 and it can be expressed as 22*23 - 5*101
def extended_euclid(a, b):
    # Provide the correct implementation
	
	n = a
	m = b
	x = 1
	x1 = 0 
	y = 0 
	y1 = 1

	while b != 0:
		q,a,b = a // b, b, a % b
		x,x1 = x1, x - q * x1
		y,y1 = y1, y - q * y1
		
	return a,[y, m], [x, n]

print extended_euclid(101, 23)
# Expected output: (1, [(22, 23), (-5, 101)])



# Exercise 5: Use the Extended Euclidean Algorithm to implement the function for multiplicative inverses. As you know, a multiplicative inverse n modulo m is guaranteed to exist if n and m are relatively prime. If they are not, your algorithm should return None (which is the null value of Python), otherwise, if n and m are relatively prime, you should return the inverse of n modulo m.
def inverse(n, m):
    # Provide the correct implementation
	
	gcd, x, y = extended_euclid_gcd(n,m)
	if (x < 0):
		x = x + m
	return x
	
def extended_euclid_gcd(n,m):
    a = 0; old_a = 1
    b = 1; old_b = 0
    r = m; old_r = n

    while r != 0:
        quotient = old_r/r

        old_r, r = r, old_r - quotient * r
        old_a, a = a, old_a - quotient * a
        old_b, b = b, old_b - quotient * b

    return [old_r, old_a, old_b]	
    
print inverse(23, 101)
# Expected output: 22
