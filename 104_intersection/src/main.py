#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## equation calc
## File description:
## equation cacl
##

import sys
from src.cordpoint import Cordpoint
from src.cacl_fonc import *
from src.error_manager import error_manager
import src.print_s as print_s

def main(argv, ac) :
    error = error_manager(argv, ac)
    if error != 0 :
        sys.exit(84)
    point_p = Cordpoint(int(argv[2]), int(argv[3]), int(argv[4]))
    vector_v = Cordpoint(int(argv[5]), int(argv[6]), int(argv[7]))

    if argv[1] == "1" :
        print("Sphere of radius %s" % argv[8])
        print("Line passing through the point (%s, %s, %s) and parallel to the vector (%s, %s, %s)" % (point_p.x, point_p.y, point_p.z, vector_v.x, vector_v.y, vector_v.z))
        cord_point = cacl_equation_sphere(point_p, vector_v, int(argv[8]))
        result = calc_quadratic_eq(cord_point.x, cord_point.y, cord_point.z)
        print_s.result(result, vector_v, point_p)
        sys.exit(0)

    if argv[1] == "2" :
        print("Cylinder of radius %s" % argv[8])
        print("Line passing through the point (%s, %s, %s) and parallel to the vector (%s, %s, %s)" % (point_p.x, point_p.y, point_p.z, vector_v.x, vector_v.y, vector_v.z))
        cord_point = cacl_equation_cylinder(point_p, vector_v, int(argv[8]))
        if cord_point.x == 0 and cord_point.y == 0 :
            print("There is an infinite number of intersection points.")
            sys.exit(84)
        result = calc_quadratic_eq(cord_point.x, cord_point.y, cord_point.z)
        print_s.result(result, vector_v, point_p)
        sys.exit(0)

    if argv[1] == "3" :
        print("Cone with a %s degree angle" % argv[8])
        print("Line passing through the point (%s, %s, %s) and parallel to the vector (%s, %s, %s)" % (point_p.x, point_p.y, point_p.z, vector_v.x, vector_v.y, vector_v.z))
        cord_point = cacl_equation_cone(point_p, vector_v, int(argv[8]))
        result = calc_quadratic_eq(cord_point.x, cord_point.y, cord_point.z)
        print_s.result(result, vector_v, point_p)
        sys.exit(0)
    sys.exit(84)