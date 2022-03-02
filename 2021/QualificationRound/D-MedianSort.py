if __name__ == '__main__':
    T, N, Q = [int(x) for x in input().split()]
    for t in range(T):
        solution = [1, 2]
        xi = 3
        while xi <= N:
            i = 0
            while len(solution) < xi:
                print(solution[i], solution[i + 1], xi)
                L = int(input())
                if L == xi:
                    solution.insert(i + 1, xi)
                elif L == solution[i]:
                    solution.insert(i, xi)
                elif i + 2 == len(solution):
                    solution.append(xi)
                i += 1
            xi += 1
        print(*solution)
        answer = int(input())
