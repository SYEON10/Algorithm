import sys

# 세그먼트 트리 생성 함수
def init(node, start, end):
    if start == end:
        tree[node] = arr[start]
        return tree[node]
    
    mid = (start + end) // 2
    tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end)
    return tree[node]

# 값 업데이트 함수
def update(node, start, end, index, diff):
    if not (start <= index <= end):
        return
    
    tree[node] += diff
    
    if start != end:
        mid = (start + end) // 2
        update(node * 2, start, mid, index, diff)
        update(node * 2 + 1, mid + 1, end, index, diff)

# 구간 합 구하는 함수
def query(node, start, end, left, right):
    if left > end or right < start:
        return 0
    
    if left <= start and end <= right:
        return tree[node]
    
    mid = (start + end) // 2
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right)

if __name__ == '__main__':
    N, M, K = map(int, sys.stdin.readline().split())
    arr = [0] * (N + 1)
    
    # N개의 수 입력
    for i in range(1, N + 1):
        arr[i] = int(sys.stdin.readline())

    # 세그먼트 트리 배열의 크기는 N의 4배 정도로 잡는 것이 안전합니다.
    tree = [0] * (N * 4) 
    
    # 트리 초기화
    init(1, 1, N)

    # M+K번의 연산 수행
    for _ in range(M + K):
        a, b, c = map(int, sys.stdin.readline().split())
        
        if a == 1: # 값 업데이트
            diff = c - arr[b]
            arr[b] = c
            update(1, 1, N, b, diff)
        elif a == 2: # 구간 합 구하기
            print(query(1, 1, N, b, c))