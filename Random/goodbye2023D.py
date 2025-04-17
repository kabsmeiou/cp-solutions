t = int(input())
for _ in range(t):
  n = int(input())
  # get array of size n
  arr = list(map(int, input().split()))
  prefix_sum = [0] * (n + 1)
  prefix_odds = [0] * (n + 1)
  for i in range(1, n + 1):
    prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1]
    prefix_odds[i] = prefix_odds[i - 1] + (arr[i - 1] % 2 == 1)
  print(arr[0], end=" ")
  for i in range(2, n + 1):
    print(prefix_sum[i] - (int(prefix_odds[i] / 3) + (prefix_odds[i] % 3 == 1)), end=" ")
    #print(int(prefix_odds[i] / 3) + (prefix_odds[i] % 3 == 1 and i > 3), end=" ")
  print('\n')