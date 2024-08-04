def solve_specific(s, n):
    sum_digits = 0
    f = 0
    idx = -1

    for i in range(len(s)):
        sum_digits += int(s[i])
        if sum_digits >= n and f == 0:
            idx = i - 1
            f = 1
        else:
            continue

    if sum_digits <= n:
        print(0)
        return
    else:
        if idx == -1:
            ans = [1] + [0] * (len(s))
            # print(s)
            # print(int(''.join(map(str, ans))))
            print(int(''.join(map(str, ans))) - int(s))
        else:
            ans = []
            for i in range(len(s)):
                if i == idx:
                    ans.append(int(s[i]) + 1)
                elif i > idx:
                    ans.append(0)
                else:
                    ans.append(int(s[i]))
            if ans[idx] >= 10:
                while idx >= 0:
                    if ans[idx] == 9:
                        ans[idx] = 0
                    else:
                        ans[idx] += 1
                        break
                    idx -= 1
            print(int(''.join(map(str, ans))) - int(s))

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    T = int(data[0])
    index = 1
    for _ in range(T):
        s = data[index]
        n = int(data[index + 1])
        index += 2
        solve_specific(s, n)

if __name__ == "__main__":
    main()
