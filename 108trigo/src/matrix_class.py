#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## math
## File description:
## peitech
##

class Mats(list):
    def __matmul__(self, B):
        A = self
        result = [[0 for i in range(len(A))] for i in range(len(A))]
        for i in range(len(A)):
            for j in range(len(B)):
                for k in range(len(B)):
                    result[i][j] += A[i][k] * B[k][j]
        return Mats(result)

    def add_mat(self, B):
        A = self
        result = [[0 for i in range(len(A))] for i in range(len(A))]
        for i in range(len(A)):
            for j in range(len(A)):
                result[i][j] = A[i][j] + B[i][j]
        return Mats(result)

    def sub_mat(self, B):
        A = self
        result = [[0 for i in range(len(A))] for i in range(len(A))]
        for i in range(len(A)):
            for j in range(len(A)):
                result[i][j] = A[i][j] - B[i][j]
        return Mats(result)

    def div_num(self, num):
        A = self
        result = [[0 for i in range(len(A))] for i in range(len(A))]
        for i in range(len(A)):
            for j in range(len(A)):
                result[i][j] = A[i][j] / num
        return Mats(result)

    def add_num(self, num):
        A = self
        result = [[0 for i in range(len(A))] for i in range(len(A))]
        for i in range(len(A)):
            for j in range(len(A)):
                result[i][j] = A[i][j] + num
        return Mats(result)

    def print_mat(self):
        mat = self
        for i in range(len(mat)):
            for j in range(len(mat) - 1):
                print("%0.2f\t" % mat[i][j], end="")
            print("%0.2f\n" % mat[i][len(mat) - 1], end="")
    