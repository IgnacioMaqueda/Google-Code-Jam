def maximum_probability(N, K, P):
    P.sort()
    lowest_gap = P[0] - 1
    highest_gap = K - P[N - 1]
    middle_gap = 0
    second_middle_gap = 0
    for i in range(1, N):
        current_gap = P[i] - P[i - 1] - 1
        if current_gap >= middle_gap:
            second_middle_gap = middle_gap
            middle_gap = current_gap
    gaps = [lowest_gap, (middle_gap + 1) // 2, (second_middle_gap + 1) // 2, highest_gap]
    gaps.sort()
    return (max(gaps[2] + gaps[3], middle_gap)) / K


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N, K = [int(x) for x in input().split()]
        P = [int(x) for x in input().split()]
        print(f"Case #{t + 1}: {maximum_probability(N, K, P)}")
