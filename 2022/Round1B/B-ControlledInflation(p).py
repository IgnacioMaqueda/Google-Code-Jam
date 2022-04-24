import sys

sys.setrecursionlimit(1500)


def minimum_buttons_dp(N, P, X, current, i, mem, j):
    if i == N:
        return 0
    if mem[i][j] < 0:
        min_i = min(X[i])
        max_i = max(X[i])
        dif_to_max = max_i - current
        dif_to_min = current - min_i
        if min_i >= current:
            mem[i][j] = dif_to_max + minimum_buttons_dp(N, P, X, max_i, i + 1, mem, 0)
        elif max_i <= current:
            mem[i][j] = dif_to_min + minimum_buttons_dp(N, P, X, min_i, i + 1, mem, 1)
        else:
            mem[i][j] = min(
                2 * dif_to_min + dif_to_max + minimum_buttons_dp(N, P, X, max_i, i + 1, mem, 0),
                2 * dif_to_max + dif_to_min + minimum_buttons_dp(N, P, X, min_i, i + 1, mem, 1))
    return mem[i][j]


def minimum_buttons(N, P, X):
    mem = []
    for _ in range(N):
        mem.append([-1, -1])
    return minimum_buttons_dp(N, P, X, 0, 0, mem, 0)


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N, P = [int(x) for x in input().split()]
        X = []
        for i in range(N):
            Xi = [int(x) for x in input().split()]
            X.append(Xi)
        print(f"Case #{t + 1}: {minimum_buttons(N, P, X)}")
