from collections import deque
import sys
input = sys.stdin.read

def main():
    data = input().split()
    index = 0
    t = int(data[index])
    index += 1
    results = []

    for _ in range(t):
        q = int(data[index])
        index += 1

        arr = deque()
        rizz = 0
        reverse_flag = False

        for i in range(q):
            s = int(data[index])
            index += 1

            if s == 1:  # cyclic shift
                if not reverse_flag:
                    val = arr.pop()
                    arr.appendleft(val)
                else:
                    val = arr.popleft()
                    arr.append(val)

            elif s == 2:  # reverse
                reverse_flag = not reverse_flag

            elif s == 3:  # append
                k = int(data[index])
                index += 1
                if not reverse_flag:
                    arr.append(k)
                else:
                    arr.appendleft(k)

            # calculate rizziness
            if not reverse_flag:
                riz = sum((i + 1) * val for i, val in enumerate(arr))
            else:
                riz = sum((i + 1) * val for i, val in enumerate(reversed(arr)))
            results.append(str(riz))

    print("\n".join(results))

main()