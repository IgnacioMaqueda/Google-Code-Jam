import numpy as np


def flavor(n, lps, freqs, ids):
    minimo = n
    indiceMinimo = -1
    for l in range(1, len(ids)):
        freqs[ids[l]] = freqs[ids[l]] + 1
        if lps[ids[l]] and freqs[ids[l]] < minimo:
            minimo = freqs[ids[l]]
            indiceMinimo = ids[l]
    if indiceMinimo > -1:
        lps[indiceMinimo] = 0
    return indiceMinimo


T = int(input())
for i in range(T):
    N = int(input())
    lollipops = np.ones(N)
    frecuencias = np.zeros(N)
    for j in range(N):
        IDs = [int(k) for k in input().split()]
        print(flavor(N, lollipops, frecuencias, IDs))
