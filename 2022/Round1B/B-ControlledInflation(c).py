def minimum_buttons_dp(N, P, X, current, i, mem_min, mem_max, is_min):
    if i == N:
        return 0
    if is_min:
        if mem_min[i] < 0:
            min_i = min(X[i])
            max_i = max(X[i])
            if min_i >= current:
                mem_min[i] = max_i - current + minimum_buttons_dp(N, P, X, max_i, i + 1, mem_min, mem_max, False)
            elif max_i <= current:
                mem_min[i] = current - min_i + minimum_buttons_dp(N, P, X, min_i, i + 1, mem_min, mem_max, True)
            else:
                dif_to_max = max_i - current
                dif_to_min = current - min_i
                mem_min[i] = min(
                    2 * dif_to_min + dif_to_max + minimum_buttons_dp(N, P, X, max_i, i + 1, mem_min, mem_max, False),
                    2 * dif_to_max + dif_to_min + minimum_buttons_dp(N, P, X, min_i, i + 1, mem_min, mem_max, True))
        return mem_min[i]
    else:
        if mem_max[i] < 0:
            min_i = min(X[i])
            max_i = max(X[i])
            if min_i >= current:
                mem_max[i] = max_i - current + minimum_buttons_dp(N, P, X, max_i, i + 1, mem_min, mem_max, False)
            elif max_i <= current:
                mem_max[i] = current - min_i + minimum_buttons_dp(N, P, X, min_i, i + 1, mem_min, mem_max, True)
            else:
                dif_to_max = max_i - current
                dif_to_min = current - min_i
                mem_max[i] = min(
                    2 * dif_to_min + dif_to_max + minimum_buttons_dp(N, P, X, max_i, i + 1, mem_min, mem_max, False),
                    2 * dif_to_max + dif_to_min + minimum_buttons_dp(N, P, X, min_i, i + 1, mem_min, mem_max, True))
        return mem_max[i]


def minimum_buttons(N, P, X):
    mem_max = [-1] * N
    mem_min = [-1] * N
    return minimum_buttons_dp(N, P, X, 0, 0, mem_min, mem_max, True)


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N, P = [int(x) for x in input().split()]
        X = []
        for i in range(N):
            Xi = [int(x) for x in input().split()]
            X.append(Xi)
        print(f"Case #{t + 1}: {minimum_buttons(N, P, X)}")
