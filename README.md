# 10주완성 C++ 코딩테스트 | 알고리즘 강좌

![스크린샷 2022-11-03 오전 12 05 09](https://user-images.githubusercontent.com/91730236/199525637-3744d820-53dc-465b-b067-6004d6b2fc5a.png)

<br/>



## :white_check_mark: 섹션 0
[c++ 교안 실습 repo](https://github.com/mmtos/cpp_get_started)
<br/>

## :white_check_mark: 섹션 1
- [9375](https://github.com/t0e8r1r4y/Algorithm/blob/main/1week/9375.md)

<br/>

## :white_check_mark: 섹션 2
- 1992
- 2828
- 2870
- 2852
- 1450
- 2636

<br/>

## :white_check_mark: 섹션 3
- 15686
- 2589
- 16234
- [4179](https://github.com/t0e8r1r4y/Algorithm/blob/main/3week/4179.md) - 생각하는 방식 전환 필요
- 12869
- 16637
- 12851
- 13913
- 17071
- 14497
- [3197](https://github.com/t0e8r1r4y/Algorithm/blob/main/3week/3197.md) - 시간초과 ( mmtos help!!! ) -- OK
- [1987](https://github.com/t0e8r1r4y/Algorithm/blob/main/3week/1987.md)
- 2529
- [9934](https://github.com/t0e8r1r4y/Algorithm/blob/main/3week/9934.md)
- 15684
- 14620
- 1189

<br/>

## :white_check_mark: 섹션 4

<br/>

## :white_check_mark: 섹션 5
> 완탐 >> DP >> 그리디  
> 이렇게 문제를 접근해본다. 그리고 그리디 풀이에 대해서 강사님은 자주나오는 풀이를 외워라! 이렇게 말씀하심.

- Greedy의 가장 많은 풀이방법
  - 정렬을 사용하는 방법 ([1931](https://github.com/t0e8r1r4y/Algorithm/blob/main/5week/1931.md) : 회의실 배정 )
  - 우선순위 큐를 사용하는 방법( [1202](https://github.com/t0e8r1r4y/Algorithm/blob/main/5week/1202.md) : 보석 도둑)
  
- 라인스위핑
- 투포인터
  
:warning: 풀이 문제
- 2109 - 1781번과 풀이는 동일합니다. 다만 시간복잡도 측면에서 반드시 1781 풀면서 있었던 이슈 꼭 참고할 것! ( `우선순위 큐와 벡터의 정렬 속도 차이` )
- 9935
- [1781](https://github.com/t0e8r1r4y/Algorithm/blob/main/5week/1781.md)
- 14469
- [1931](https://github.com/t0e8r1r4y/Algorithm/blob/main/5week/1931.md)
- [1202](https://github.com/t0e8r1r4y/Algorithm/blob/main/5week/1202.md)
- 1644
- 13144
- 3273
- 1700
- 17144
- 14889
- 12100
- 3190
- 17406
- 15662
- 1911
- 17825
- 14888
- 17143
- 15685
- 2632
- 1912
- 15683
- 17822
- 2170

<br/>

## :white_check_mark: 섹션 6

<br/>

## :white_check_mark: 섹션 7
> DP : 완전탐색 + 메모리제이션  
> 메모리제이션의 핵심 : 계산된 값을 자료구조에 저장하여 다시 한번 계산하는 것을 방지하는 것  

- DP의 조건
  - 참조투명성을 가져야 하며 입력을 제외한 외적요소에 결과값이 영향을 미치지 않아야 함
  - Overlapping Subproblem, 겹치는 부분 문제가 존재하여야 함
  - Optimal Substructure : 최적 부분구조를 가져야 함
  - 묵시적으로 DAG 구조를 가지고 있어야함. 방향성이 있고 사이클이 없는 그래프 구조
  - 양방향간선이 존재하거나 사이클이 있는 그래프 같은 경우 preprocess를 통해 DAG를 만들어야 함.
  
- :white_check_mark: 생각의 접근
  - 이거 완전 탐색인가?
  - 경우의 수가 너무 큰가?
  - 메모리제이션 가능한가? ( 14729 문제 처럼 배열을 선언하고 메모라이제이션을 하기 힘들만큼 input이 크면 그리디일 가능성이 있다.)
  

<br/>

## :white_check_mark: 섹션 8
> 모빌리티 관련회사들에서 특히 지도쓰는 회사들에서 단골로 나오는 문제들입니다.  
> 다익스트라, 플로이드워셜, 가끔 벨만포트, 위상정렬까지 학습을 해두면 좋지만... 상황이 여의치 않다면 다익스트라, 플로이드 워셜은 외워 버립시다.




<br/>
