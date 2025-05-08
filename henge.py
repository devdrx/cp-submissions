import sys

def process_sum(numbers, index, total):
    if index == len(numbers):
        return total
    y = numbers[index]
    if y <= 0:
        return process_sum(numbers, index + 1, total + y ** 4)
    else:
        return process_sum(numbers, index + 1, total)

def process_case(lines, i, N):
    if i == N:
        return
    try:
        X = int(lines[2 * i + 1])
        numbers = tuple(map(int, lines[2 * i + 2].strip().split()))
        if len(numbers) != X:
            print("-1")
        else:
            result = process_sum(numbers, 0, 0)
            print(str(result))
    except:
        print("-1")
    process_case(lines, i + 1, N)

def main():
    lines = sys.stdin.read().splitlines()
    try:
        N = int(lines[0])
        process_case(lines, 0, N)
    except:
        pass

if __name__ == "__main__":
    main()
