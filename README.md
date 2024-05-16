# Spinning Cube

C++ 콘솔 애플리케이션으로 구현한 3차원 공간에서 회전하는 큐브

> 참고: https://youtu.be/p09i_hoFdd0?si=vdAlAoYoUWH4wL_L 

> github: https://github.com/servetgulnaroglu/cube.c

# 실행 환경

- Windows 11
- Visual Studio 2022
- C++ Console Application

# 구현 내용

- 원점 기준 물체의 좌표 회전
    - 회전 행렬을 이용하여 물체의 좌표를 회전합니다.
- 원근 투영 적용
    - 해당 프로젝트에서는 `view frustum`을 고려하지 않은 원근 투영을 적용합니다.
    - 따라서 클리핑 및 NDC 좌표 적용은 고려하지 않았습니다.
