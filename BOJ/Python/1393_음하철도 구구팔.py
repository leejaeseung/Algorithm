#백준 1393 - 음하철도 구구팔
#답이 항상 정수로 나오므로, 열차가 한 번 이동하는 기울기를 기약분수로 나타내 지하철과의 거리가 가장 짧을 때 해당 지점을 출력했습니다.

import math

def gcb(a, b):
    while a != 0:
        r = b % a
        b = a
        a = r
    return abs(b)

def getDis(x1, y1, x2, y2):
    return math.sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))

station_x, station_y = map(int, input().split())
now_x, now_y, move_x, move_y = map(int, input().split())

if move_x != 0 or move_y != 0:
    gcb_num = gcb(min(move_x, move_y), max(move_x, move_y))
    move_x /= gcb_num
    move_y /= gcb_num

    minDis = getDis(now_x, now_y, station_x, station_y)
    nextDis = 0


    while True:
        now_x += move_x
        now_y += move_y
        nextDis = getDis(now_x, now_y, station_x, station_y)
        if nextDis > minDis:
            now_x -= move_x
            now_y -= move_y
            print(int(now_x), int(now_y))
            break
        else:
            minDis = nextDis
else:
    print(int(now_x), int(now_y))