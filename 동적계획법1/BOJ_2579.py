N = int(input())
date = []
maxValue = 0
date.append(0)
dp = [[0 for _ in range(3)] for __ in range(302)]

for i in range(N):
    num = int(input())
    date.append(num)
dp[1][1] = date[1]
for i in range(2, N+1):
    dp[i][2] = dp[i - 1][1] + date[i]
    dp[i][1] = max(dp[i - 2][2], dp[i - 2][1]) + date[i]
print(max(dp[N][1],dp[N][2]))



'''
for _ in range(N):
    num = int(input())
    date.append(num)
'''
