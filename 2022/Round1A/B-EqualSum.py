if __name__ == '__main__':
    limit = 1000000000
    max_power = 536870912
    T = int(input())
    for t in range(T):
        N = int(input())
        A = [x for x in range(limit - 99, limit + 1)]
        power = 1
        index = 0
        while power < limit:
            A[index] = power
            power *= 2
            index += 1
        print(*A)
        B = [int(x) for x in input().split()]
        total = sum(A) + sum(B)
        remaining = total // 2
        powers = A[:30]
        rest = [*B, *A[30:]]
        rest.sort()
        result = []
        index = len(rest) - 1
        while remaining >= max_power * 2:
            next_element = rest[index]
            result.append(next_element)
            remaining -= next_element
            index -= 1
        index = len(powers) - 1
        while remaining > 0:
            while powers[index] > remaining:
                index -= 1
            next_element = powers[index]
            result.append(next_element)
            remaining -= next_element
            index -= 1
        print(*result)
