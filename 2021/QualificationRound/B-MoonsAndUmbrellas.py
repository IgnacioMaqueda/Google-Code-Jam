def minimum_cost(X, Y, S):
    res = 0
    current = S[0]
    for c in S:
        if current == 'C' and c == 'J':
            current = c
            res += X
        elif current == 'J' and c == 'C':
            current = c
            res += Y
        elif current == '?':
            current = c
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        X, Y, S = input().split()
        X = int(X)
        Y = int(Y)
        print(f"Case #{t + 1}: {minimum_cost(X, Y, S)}")
