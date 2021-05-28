---
noteId: "eb53d940b4a011ebaea7210635332d60"
tags: []

---
# 102architect

## Usage
```shell
./102architect x y transfo1 arg11 [arg12] [transfo2 arg12 [arg22]] ...

    x   abscissa of the original point
    y   ordinate of the original point
    transfo arg1 [arg2]
    -t i j  translation along vector (i, j)
    -z m n  scaling by factors m (x-axis) and n (y-axis
    -r d    rotation centered in O by a d degree angle
    -s d    reflection over the axis passing through O with an inclination
    	    angle of d degrees
```

## Sythetic scheme
    Curve representing the number of individuals in relation to the generation
```shell
   10 +--------------------------------------------------------------------+   
      | AA   +      +      +      +      +     +      +      +      +      |   
  9.5 |-+AAA                                                             +-|   
      |     AA                                                             |   
    9 |-+     AA                                                         +-|   
      |         AA                                                         |   
  8.5 |-+         AAA                                                    +-|   
      |             AAA                                                    |   
    8 |-+              AAA                                               +-|   
      |                  AAA                                               |   
  7.5 |-+                   AAAA                                         +-|   
      |                         AAA                                        |   
    7 |-+                          AAAA                                  +-|   
      |                               AAAA                                 |   
  6.5 |-+                                 AAAA                           +-|   
      |                                       AAAA                         |   
    6 |-+                                         AAAAA                  +-|   
      |                                                AAAAAA              |   
  5.5 |-+                                                    AAAAA       +-|   
      |      +      +      +      +      +     +      +      +    AAAAAAA  |   
    5 +--------------------------------------------------------------------+   
      0      10     20     30     40     50    60     70     80     90    100
```