##
## EPITECH PROJECT, 2021
## 104_intersection
## File description:
## print_result
##

import sys
from src.cordpoint import Cordpoint

def result(result, vector_v, point_p) :
    if result[0] == 0 and result[0] == 0 :
        print("No intersection point.")
        sys.exit(0)
    if result[0] == result[1] :
        print("1 intersection point:")
        cord_point = Cordpoint(point_p.x + vector_v.x * result[0], point_p.y + vector_v.y * result[0], point_p.z + vector_v.z * result[0])
        print("(%.3f, %.3f, %.3f)" % (cord_point.x, cord_point.y, cord_point.z))
    if result[0] != result[1] :
        print("2 intersection points:")
        cord_result = Cordpoint(point_p.x + vector_v.x * result[0], point_p.y + vector_v.y * result[0], point_p.z + vector_v.z * result[0])
        print("(%.3f, %.3f, %.3f)" % (cord_result.x, cord_result.y, cord_result.z))
        cord_result = Cordpoint(point_p.x + vector_v.x * result[1], point_p.y + vector_v.y * result[1], point_p.z + vector_v.z * result[1])
        print("(%.3f, %.3f, %.3f)" % (cord_result.x, cord_result.y, cord_result.z))