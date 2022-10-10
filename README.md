# BOJ

<details>
<summary>1477번: 휴게소 세우기</summary>

### #이분탐색

</details>
<details>
<summary>2210번: 공유기 설치</summary>

### #이분탐색  

공유기를 설치할 수 있는 위치는 주어진 집의 좌표들로 정해져 있다.
1) 공유기가 2개일 때  
좌표가 가작 작은 집과 가장 큰 집의 거리 차이가 됨은 자명하다.  

2) 공유기가 3개 이상일 때  
공유기가 설치된 C개의 집들 사이의 거리 중 **가장 작은 값이 최대**가 되는 C개의 집을 구하면 된다.
먼저 첫번째 집에 첫번째 공유기를 설치하고 그 후의 계산을 이어나간다.

```C++
while(st <= en)
    {
        ll cnt = 1;
        ll mid = (st + en ) / 2; // 간격
        ll cur = v[0]; // 

        for(int i = 1;i< n;i++)
        {
            if(v[i] - cur >= mid)
            {
                cnt++;
                cur = v[i];
            }
        }

        if(cnt >= c) // 공유기 수 줄이기 == 간격 넓히기
            st = mid + 1;
        else // 공유기 수 늘리기 == 간격 좁히기
            en = mid - 1; // 3
    }
```


</details>

y = A \times x + B