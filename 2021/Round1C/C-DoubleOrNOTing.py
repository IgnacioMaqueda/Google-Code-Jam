def not_op(S):
    if S == 0:
        return 1
    i = 1
    x = S
    while x > 0:
        x = x >> 1
        i *= 2
    return i - 1 - S


def two_op(S):
    return S * 2


def min_ops(S, E):
    res = 0
    elements = [S]
    while res < 20:
        new_elements = []
        for s in elements:
            if s == E:
                return res
            new_elements.append(not_op(s))
            new_elements.append(two_op(s))
        elements = new_elements
        res += 1
    return "IMPOSSIBLE"


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        S, E = [int(x, 2) for x in input().split()]
        print(f"Case #{t + 1}: {min_ops(S, E)}")
