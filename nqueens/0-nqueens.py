#!/usr/bin/python3
""" Program that solves the N queens problem."""

import sys


def is_safe(queen_positions, row, col):
    """Checks if the position is safe for a new queen"""
    for i in range(row):
        if queen_positions[i] == col or \
           queen_positions[i] - i == col - row or \
           queen_positions[i] + i == col + row:
            return False
    return True


def solve_nqueens(size, row, queen_positions):
    """ Solves the N Queens problem recursively"""
    if row == size:
        print_solution(queen_positions)
        return
    for col in range(size):
        if is_safe(queen_positions, row, col):
            queen_positions[row] = col
            solve_nqueens(size, row + 1, queen_positions)


def print_solution(queen_positions):
    """ Prints one solution from the list of queen positions"""
    solution = []
    for row, col in enumerate(queen_positions):
        solution.append([row, col])
    print(solution)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    queen_positions = [-1] * N
    solve_nqueens(N, 0, queen_positions)
