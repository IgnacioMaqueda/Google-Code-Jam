def sum_of_powers(E):
    res = 0
    for e in E:
        res += e * e
    return res


def make_squary(N, K, E):
    sum_elements = sum(E)
    power_elements = sum_of_powers(E)
    if K == 1:
        numerator = power_elements - sum_elements * sum_elements
        denominator = 2 * sum_elements
        if denominator == 0:
            if numerator == 0:
                return 0
            else:
                return "IMPOSSIBLE"
        if numerator % denominator == 0:
            return numerator // denominator
        else:
            return "IMPOSSIBLE"



if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N, K = [int(x) for x in input().split()]
        E = [int(x) for x in input().split()]
        print(f"Case #{t + 1}: {make_squary(N, K, E)}")
