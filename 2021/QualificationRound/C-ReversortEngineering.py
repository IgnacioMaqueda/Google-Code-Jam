def is_possible(N, C):
    return N - 1 <= C <= (N * (N + 1)) / 2 - 1


def obtain_costs(N, C):
    res = [1 for _ in range(N - 1)]
    C -= N - 1
    i = 0
    while C > 0:
        extra = min(N - 1 - i, C)
        res[i] += extra
        C -= extra
        i += 1
    return res


def obtain_positions(N, costs):
    res = [*range(1, N + 1)]
    for i in range(N - 1):
        res[i:i + costs[i]] = res[i:i + costs[i]][::-1]
    return res


def obtain_list(N, positions):
    res = [0 for _ in range(N)]
    for i in range(N):
        res[positions[i] - 1] = i + 1
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N, C = [int(x) for x in input().split()]
        if is_possible(N, C):
            costs = obtain_costs(N, C)
            positions = obtain_positions(N, costs)
            print(f"Case #{t + 1}: ", end='')
            print(*obtain_list(N, positions))
        else:
            print(f"Case #{t + 1}: IMPOSSIBLE")
