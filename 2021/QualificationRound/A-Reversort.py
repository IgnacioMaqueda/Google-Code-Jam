def reversort_cost(N, L):
    res = 0
    for i in range(N - 1):
        j = L.index(min(L[i:N]))
        L[i:j + 1] = L[i:j + 1][::-1]
        res += j - i + 1
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        L = [int(l) for l in input().split()]
        print(f"Case #{t + 1}: {reversort_cost(N, L)}")
