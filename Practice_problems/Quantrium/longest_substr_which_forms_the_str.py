def MathChallenge(s):
    n = len(s)
    for i in range(1, n//2 +1):
        if n % i == 0:
            substr = s[:i]
            if substr * (n // i) == s:
                return substr
    return -1
