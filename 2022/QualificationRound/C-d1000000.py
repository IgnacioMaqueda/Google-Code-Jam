def maximum_straight(N, S):
    current = 1
    i = 0
    while i < N:
        while i < N and S[i] < current:
            i += 1
        if i < N:
            i += 1
            current += 1
    return current - 1


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        S = [int(x) for x in input().split()]
        S.sort()
        print(f'Case #{t + 1}: {maximum_straight(N, S)}')
