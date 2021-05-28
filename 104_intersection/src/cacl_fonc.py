##
## EPITECH PROJECT, 2021
## 104_intersection
## File description:
## cacl_fonc
##

import math
from src.cordpoint import Cordpoint

def determinan(a, b, c) :
    det = b ** 2 - (4 * a * c)
    return det

def calc_determinan_type(a, b, c) :
    det = determinan(a, b, c)
    if det > 0 :
        return 2
    elif det ==  0:
        return 1
    else :
        return 0

def calc_quadratic_eq(a, b, c) :
    det = determinan(a, b, c)
    i = calc_determinan_type(a, b, c)
    result = [0, 0]
    if det >= 0 :
        result[0] = (-b + math.sqrt(det)) / (2 * a)
        result[1] = (-b - math.sqrt(det)) / (2 * a)

    return result

def create_cord_point(point_p, vector_v, t) :
    x_t = point_p.x + (t * vector_v.x)
    y_t = point_p.y + (t * vector_v.y)
    z_t = point_p.z + (t * vector_v.z)
    return Cordpoint(x_t, y_t, z_t)

def cacl_equation_sphere(point_p, vector_v, r) :
    a = (vector_v.x ** 2 + vector_v.y ** 2 + vector_v.z ** 2)
    b = 2 * (vector_v.x * point_p.x + vector_v.y * point_p.y + vector_v.z * point_p.z)
    c = (point_p.x ** 2 + point_p.y ** 2 + point_p.z ** 2)
    return Cordpoint(a, b, c - (r ** 2))

def cacl_equation_cylinder(point_p, vector_v, r) :
    a = (vector_v.x ** 2 + vector_v.y ** 2)
    b = 2 * (vector_v.x * point_p.x + vector_v.y * point_p.y)
    c = point_p.x ** 2 + point_p.y ** 2
    return Cordpoint(a, b, c - (r ** 2))

def cacl_equation_cone(point_p, vector_v, angle) :
    a = 1 / math.tan(math.radians(angle)) ** 2 * (vector_v.x ** 2 + vector_v.y ** 2 ) - vector_v.z ** 2 
    b = 1 /math.tan(math.radians(angle)) ** 2 * (2 * point_p.x * vector_v.x + 2 * point_p.y * vector_v.y) - (2 * point_p.z * vector_v.z)
    c = 1 / math.tan(math.radians(angle)) ** 2 * (point_p.x ** 2 + point_p.y ** 2) - point_p.z ** 2
    return Cordpoint(a, b, c)