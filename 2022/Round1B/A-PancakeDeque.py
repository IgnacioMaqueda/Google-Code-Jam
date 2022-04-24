def paying_customers(N, D):
    res = 0
    i = 0
    j = N - 1
    current_max = 0
    while i <= j:
        if D[i] < D[j]:
            if D[i] >= current_max:
                res += 1
                current_max = D[i]
            i += 1
        else:
            if D[j] >= current_max:
                res += 1
                current_max = D[j]
            j -= 1
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        D = [int(x) for x in input().split()]
        print(f"Case #{t + 1}: {paying_customers(N, D)}")
