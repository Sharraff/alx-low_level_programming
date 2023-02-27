#!/usr/bin/python3
# -*- encoding: utf-8 -*-
"""
created on 26 feb 2023
@uthor: Musharraff Ibrahim
"""

def island_perimeter(grid):
    """
    Calculate the islands perimeter

    parameter:
        grid (array): An 0's  and 1's array that represents and island (1)
        sorrounded by water (0)
    
    Returns:
        The island's perimeter
    """
    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0
    for i in range(1, rows - 1):
        for j in range(1, cols - 1):
            if grid[i][j] == 1:
                if grid[i - 1][j] == 0:
                    preimeter += 1
                if grid[i + 1][j] == 0:
                    perimeter += 1
                if grid[i][j - 1] == 0:
                    perimeter += 1
                if grid[i][j + 1] == 0:
                    perimeter += 1
    return perimeter
