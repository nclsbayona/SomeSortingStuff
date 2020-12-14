def patienceSort(vector: list):
    i = 0
    vecStacks = list()
    inserted: bool
    size: int = len(vector)
    for num in (vector):
        inserted = False
        for stack in (vecStacks):
            if not inserted and stack[len(stack) - 1] >= num:
                stack.append(num)
                inserted = True
        if not inserted:
            vecStacks.append([num])

    def getLowestElement(vecStacks: list):

        lowest = 999999
        index = -1

        for i in range(len(vecStacks)):
            elemen = vecStacks[i][len(vecStacks[i]) - 1]
            if (elemen < lowest):
                index = i
                lowest = elemen

        vecStacks[index].pop()

        if len(vecStacks[index]) == 0:
            del vecStacks[index]

        return lowest

    vector.clear()

    for i in range(size):
        vector.append(getLowestElement(vecStacks))
    del i
    return vector


def main():
    unsorted = [89, 144, 55, 1, 13, 21, 2, 34, 0, 1, 8, 5, 3]
    print("Unsorted\n", unsorted)
    testCode = """unsorted = [89, 144, 55, 1, 13, 21, 2, 34, 0, 1, 8, 5, 3];patienceSort(unsorted)"""
    sorted = patienceSort(unsorted)
    timei = 0
    num = 250000
    print("\nSorted\n", sorted)
    for i in range(num):
        timei += timeit(setup="from __main__ import patienceSort",
                        stmt=testCode,
                        number=1)
    del i

    print("{:.6f}".format(timei/num))


if __name__ == "__main__":
    from timeit import timeit
    main()
